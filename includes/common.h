#pragma once

#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <type_traits>

#include "config.h"

#ifdef JNGEN_DECLARE_ONLY
#define JNGEN_EXTERN extern
#else
#define JNGEN_EXTERN
#endif

namespace jngen {

class Exception : public std::runtime_error {
public:
    explicit Exception(const std::string& s)
        : std::runtime_error("Assertion `" + s + "` failed.") {}

    Exception(const std::string& assertMsg, const std::string& expl)
        : std::runtime_error(
            expl + " (Assertion `" + assertMsg + "` failed).") {}
};

class InternalException : public Exception {
public:
    explicit InternalException(const std::string& s)
        : Exception(s) {}

    InternalException(const std::string& assertMsg, const std::string& expl)
        : Exception(assertMsg, expl) {}
};

} // namespace jngen

#define JNGEN_CHECK1(exType, cond)  \
    do {                            \
        if ( !(cond) ) {            \
            throw exType(#cond);    \
        }                           \
    } while (false)

#define JNGEN_CHECK2(exType, cond, msg)  \
    do {                                 \
        if ( !(cond) ) {                 \
            throw exType(#cond, msg);    \
        }                                \
    } while (false)

#define JNGEN_SWITCH_CHECKER(_1, _2, checker, ...) checker

#define CHECK(...)                                                  \
    JNGEN_SWITCH_CHECKER(__VA_ARGS__, JNGEN_CHECK2, JNGEN_CHECK1)   \
    (jngen::Exception, __VA_ARGS__)

#define INTER_CHECK(...)                                            \
    JNGEN_SWITCH_CHECKER(__VA_ARGS__, JNGEN_CHECK2, JNGEN_CHECK1)   \
    (jngen::InternalException, __VA_ARGS__)

namespace jngen {

template<typename ... Args>
std::string format(const std::string& fmt, Args... args) {
    // Alaways existing memory after this function first be called.
    constexpr static char BUF_SIZE = 64;
    static char BUFFER[BUF_SIZE];

    int bufSize = BUF_SIZE;
    char *buf = BUFFER;

    while (true) {
        int ret = std::snprintf(buf, bufSize, fmt.c_str(), args...);
        if (ret < bufSize) {
            break;
        }

        if (bufSize != BUF_SIZE) {
            delete[] buf;
        }

        bufSize *= 2;
        buf = new char[bufSize];
    }

    std::string result(buf);

    if (bufSize != BUF_SIZE) {
        delete[] buf;
    }

    return result;
}

class ContextTimer {
public:
    ContextTimer(const std::string& name)
            : name_(name) {
        start_ = std::chrono::steady_clock::now();
    }

    ContextTimer() : ContextTimer("") {}

    ContextTimer(const ContextTimer&) = delete;
    ContextTimer& operator=(const ContextTimer&) = delete;
    ContextTimer(ContextTimer&&) = delete;
    ContextTimer& operator=(ContextTimer&&) = delete;

    ~ContextTimer() {
        auto dif = std::chrono::steady_clock::now() - start_;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dif);
        if (!name_.empty()) {
            std::cerr << "[" << name_ << "] ";
        }
        std::cerr << ms.count() << " ms\n";
    }

private:
    std::string name_;
    std::chrono::steady_clock::time_point start_;
};

// TODO: why use && here???
template<typename F>
auto distribution(int n, F&& f) -> std::map<decltype(f()), int> {
    std::map<decltype(f()), int> dist;
    for (int i = 0; i < n; ++i) {
        ++dist[f()];
    }
    return dist;
}

inline void checkLargeParameter(int n) {
    if (!config.generateLargeObjects) {
        constexpr static int BOUND = 5e6;
        CHECK(n <= BOUND,
              "If you want to generate an object of size > 5'000'000, "
              "please set 'config.generateLargeObjects = true'.");
    }
}

// Some type traits helpers. Based on ideas from TCPPPL v4.
template<bool B, typename T = void>
using enable_if_t = typename std::enable_if<B, T>::type;

template<typename T>
using decay_t = typename std::decay<T>::type;

namespace util {

inline long long gcd(long long a, long long b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }

    while (a && b) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

inline std::vector<std::string> split(std::string s, char delimiter) {
    auto strip = [](std::string s) {
        size_t l = 0;
        while (l < s.size() && s[l] == ' ') {
            ++l;
        }
        s = s.substr(l);
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        return s;
    };

    std::vector<std::string> result;
    s += delimiter;
    std::string cur;

    for (char c : s) {
        if (c == delimiter) {
            result.push_back(strip(cur));
            cur.clear();
        } else {
            cur += c;
        }
    }

    return result;
}

} // namespace util

} // namespace jngen

using jngen::format;
using jngen::ContextTimer;
using jngen::distribution;
