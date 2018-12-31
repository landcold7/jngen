all: libjngen.so

build: includes/*.h impl/*.h drawer/*.h
	@echo "Building libjngen.so.."
	@-rm includes/jngen.h
	@python build.py

libjngen.so: build lib.cpp
	g++ -O2 -std=c++11 -Wall -c lib.cpp -fPIC -o libjngen.so

install:
	cp includes/jngen.h /usr/local/include/
	cp libjngen.so /usr/local/lib/
	rm libjngen.so

clean:
	rm libjngen.so
	rm /usr/local/include/jngen.h
	rm /usr/local/lib/libjngen.so
