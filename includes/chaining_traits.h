#pragma once

#define JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, name) \
        int _ ## name = 0;                              \
        Class& name(int val = 1) {                      \
            _ ## name = val;                            \
            return *this;                               \
        }

#define JNGEN_CHAINING_TRAITS_INNER_0(Class)

#define JNGEN_CHAINING_TRAITS_INNER_1(Class, arg) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)

#define JNGEN_CHAINING_TRAITS_INNER_2(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg) \
        JNGEN_CHAINING_TRAITS_INNER_1(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_3(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg) \
        JNGEN_CHAINING_TRAITS_INNER_2(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_4(Class, arg, ...)  \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_3(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_5(Class, arg, ...)  \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_4(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_6(Class, arg, ...)  \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_5(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_7(Class, arg, ...)  \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_6(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_8(Class, arg, ...)  \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_7(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_9(Class, arg, ...)  \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_8(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_10(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_9(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_11(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_10(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_12(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_11(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_13(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_12(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_14(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_13(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_15(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_14(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_16(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_15(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_17(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_16(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_18(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_17(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_19(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_18(Class, __VA_ARGS__)

#define JNGEN_CHAINING_TRAITS_INNER_20(Class, arg, ...) \
        JNGEN_DEFINE_CHAINING_TRAITS_FIELD(Class, arg)  \
        JNGEN_CHAINING_TRAITS_INNER_19(Class, __VA_ARGS__)

#define JNGEN_GET_CHAINING_TRAITS_INNER_IMPL(                   \
        p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, \
        p14, p15, p16, p17, p18, p19, p20, x, ...)              \
        x

// Depends the the number of args, it will chose corresponding marcos.
#define JNGEN_GET_CHAINING_TRAITS_INNER(...)      \
        JNGEN_GET_CHAINING_TRAITS_INNER_IMPL(     \
            __VA_ARGS__,                          \
            JNGEN_CHAINING_TRAITS_INNER_20,       \
            JNGEN_CHAINING_TRAITS_INNER_19,       \
            JNGEN_CHAINING_TRAITS_INNER_18,       \
            JNGEN_CHAINING_TRAITS_INNER_17,       \
            JNGEN_CHAINING_TRAITS_INNER_16,       \
            JNGEN_CHAINING_TRAITS_INNER_15,       \
            JNGEN_CHAINING_TRAITS_INNER_14,       \
            JNGEN_CHAINING_TRAITS_INNER_13,       \
            JNGEN_CHAINING_TRAITS_INNER_12,       \
            JNGEN_CHAINING_TRAITS_INNER_11,       \
            JNGEN_CHAINING_TRAITS_INNER_10,       \
            JNGEN_CHAINING_TRAITS_INNER_9,        \
            JNGEN_CHAINING_TRAITS_INNER_8,        \
            JNGEN_CHAINING_TRAITS_INNER_7,        \
            JNGEN_CHAINING_TRAITS_INNER_6,        \
            JNGEN_CHAINING_TRAITS_INNER_5,        \
            JNGEN_CHAINING_TRAITS_INNER_4,        \
            JNGEN_CHAINING_TRAITS_INNER_3,        \
            JNGEN_CHAINING_TRAITS_INNER_2,        \
            JNGEN_CHAINING_TRAITS_INNER_1,        \
            JNGEN_CHAINING_TRAITS_INNER_0)

#define JNGEN_CHAINING_TRAITS(Class, ...) \
    struct Class { \
        JNGEN_GET_CHAINING_TRAITS_INNER(__VA_ARGS__) (Class, __VA_ARGS__) \
    };

