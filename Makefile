CXX=gcc
#CFLAGS=-fPIC -fopenmp -fopenmp-targets=nvptx64-nvidia-cuda
CFLAGS=-fPIC -fopenmp

all: libgputool.so
	$(CXX) $(CFLAGS) -L. -lgputool -o main main.c

libgputool.so:
	$(CXX) $(CFLAGS) -c -o gputool.o gputool.c
	$(CXX) $(CFLAGS) -shared -o libgputool.so gputool.o


# Phony
clean:
	rm *.o *.so main
