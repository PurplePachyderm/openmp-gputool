CXX=clang
OMPFLAGS=-fopenmp -fopenmp-targets=nvptx64
CFLAGS=$(OMPFLAGS) -Wall

all: libgputool.so tests.o
	$(CXX) $(CFLAGS) -L. -lgputool -o main tests.o main.c

libgputool.so: gputool.c
	$(CXX) $(CFLAGS) -shared -fPIC -o libgputool.so gputool.c

tests.o: tests.c
	$(CXX) $(CFLAGS) -c -o tests.o tests.c


# Phony
clean:
	rm *.o *.so main
