CXX=clang
OMPFLAGS=-fopenmp -fopenmp-targets=nvptx64
CFLAGS=-fPIC $(OMPFLAGS)

all: libgputool.so
	$(CXX) $(CFLAGS) -L. -lgputool -o main main.c

libgputool.so:
	$(CXX) $(CFLAGS) -c -o gputool.o gputool.c
	$(CXX) $(CFLAGS) -shared -o libgputool.so gputool.o


# Phony
clean:
	rm *.o *.so main
