
ifndef CC
CC=cc
endif

ifndef CXX
CXX=c++
endif

default: ../lib/libariac.so test

all: ../lib/libariac.so ../lib/libariacs.so ../lib/libariac.a test testcs tests

clean: FORCE
	rm -f test testcs tests ../lib/libariac.so ../lib/libariacs.so ../lib/libariac.a

test: test.c ../lib/libariac.so ../lib/libAria.so ariac.h
	$(CC) -std=c99 -fPIC -I../include -o $@ $< -L../lib -lariac -lAria -lpthread -ldl -lrt -lm

testcs: test.c ../lib/libariacs.so ariac.h
	$(CC) -std=c99 -fPIC -I../include -o $@ $< -L../lib -lariacs 

tests: test.c ../lib/libariac.a ariac.h
	$(CC) -std=c99 -fPIC -I../include -o $@ $< -L../lib -Wl,-static  -Wl,-Bstatic -lariac

../lib/libariac.so: ariac.cpp ariac.h 
	$(CXX) -fPIC -shared -I../include -o $@ $< -L../lib -lAria -lpthread -ldl -lrt -lm

../lib/libariac.a: ariac.cpp ariac.h ../lib/libAria.a
	$(CXX) -c -fPIC -I../include -o ariac.o $< -L../lib -static-libstdc++ -Wl,-Bstatic -lAria -lpthread -ldl -lrt -lm
	ar -cr $@ ariac.o
	ranlib $@

# Links to libAria.a statically (but is a dynamic library):
../lib/libariacs.so: ariac.cpp ariac.h ../lib/libAria.a
	$(CXX) -fPIC -shared -I ../include -o $@ $< -L../lib -static-libstdc++ -Wl,-Bstatic -lAria 

../lib/libAria.so: FORCE
	$(MAKE) -C .. lib/libAria.so

../lib/libAria.a: FORCE
	$(MAKE) -C .. lib/libAria.a


FORCE:

.PHONY: default all clean
