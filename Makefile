all: libjngen.so

libjngen.so: lib.cpp
	g++ -O2 -std=c++11 -Wall -c lib.cpp -fPIC -o libjngen.so

install: jngen.h libjngen.so
	cp jngen.h /usr/local/include/
	cp libjngen.so /usr/local/lib/

clean:
	rm libjngen.so
	rm /usr/local/include/jngen.h
	rm /usr/local/lib/libjngen.so
