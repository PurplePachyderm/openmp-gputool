# openmp-gputool

Test repository to play with OpenMP's OMPT interface and GPU offloading.

## Requirements

A compiler with support for both OMPT (introduced in OpenMP 4.5) and offloading to Nvidia GPUs.

## Build

Edit the first two lines in the `Makefile` to match your compiler and required OpenMP flags (default is setup to use LLVM offloading to the `nvptx64` target) : 

```
CXX=clang
OMPFLAGS=-fopenmp -fopenmp-targets=nvptx64
```

Then run : 

```
make
```

## Useful links

- [OpenMP specs](https://www.openmp.org/specifications/)
- [Summary of OpenMP support status for different compilers](https://www.openmp.org/resources/openmp-compilers-tools/#compilers)
- [LLVM's official OpenMP page](https://openmp.llvm.org/)
- [A guide on how to build LLVM with Nvidia offloading support](https://freecompilercamp.org/llvm-openmp-build/)
- [Webinar on  OpenMP GPU programming (YouTube video)](https://www.youtube.com/watch?v=uVcvecgdW7g)
- [Webinar on  OpenMP GPU programming (PDF slides)](https://www.openmp.org/wp-content/uploads/2021-10-20-Webinar-OpenMP-Offload-Programming-Introduction.pdf)
