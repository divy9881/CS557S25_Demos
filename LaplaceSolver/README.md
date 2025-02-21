
### CPU Specifications
- Processor	13th Gen Intel(R) Core(TM) i5-1350P   1.90 GHz
- Installed RAM	16.0 GB (15.4 GB usable)
- Total Cores 12
- Performance-cores 4
- Efficient-cores 8
- Total Threads 16
- Max Turbo Frequency 4.70 GHz
- Performance-core Max Turbo Frequency 4.70 GHz
- Efficient-core Max Turbo Frequency 3.50 GHz


### Memory bandwidth
```bash
DDR5-4800 (Dual-Channel)
Memory speed: 4800 MT/s
Bus width per DIMM: 64 bits (8 bytes)
Channels: 2 (dual-channel)
4800 × 8 × 2 = 76.8 GB/s
```

### Compiler
```bash
$ g++ --version
g++ (Ubuntu 14.2.0-16ubuntu1) 14.2.0
Copyright (C) 2024 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

### OS
```bash
$ cat /etc/os-release 
PRETTY_NAME="Ubuntu Plucky Puffin (development branch)"
NAME="Ubuntu"
VERSION_ID="25.04"
VERSION="25.04 (Plucky Puffin)"
VERSION_CODENAME=plucky
ID=ubuntu
ID_LIKE=debian
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
UBUNTU_CODENAME=plucky
LOGO=ubuntu-logo
```

### Compilation commands
```bash
$ g++ -fopenmp main.cpp Laplacian.cpp
```

### LaplaceSolver_0_3 serial execution
```bash
$ export OMP_NUM_THREADS=1
$ make
$ ./laplace_solver
...
...
Conjugate Gradients terminated after 256 iterations; residual norm (nu) = 0.000975892
-----------------------------------------------------

[Line-2 Laplacian Time : 29.1459ms]
[Line-6 Laplacian Time : 4052.18ms]
[Line-6 Average Laplacian Time : 15.7672ms]
Aggregated Laplacian Time : 4081ms
-----------------------------------------------------

[Line-2 Saxpy Time : 35.5474ms]
[Line-8 Saxpy Time : 2987.49ms]
[Line-8 Average Saxpy Time : 11.6245ms]
[Line-9-12 Saxpy Time : 14.9098ms]
[Line-9-12 Average Saxpy Time : 14.9098ms]
[Line-16 Saxpy Time : 5667.91ms]
[Line-16 Average Saxpy Time : 22.1403ms]
Aggregated Saxpy Time : 8703ms
-----------------------------------------------------

[Line-4 InnerProduct Time : 14.2709ms]
[Line-6 InnerProduct Time : 3934ms]
[Line-6 Average InnerProduct Time : 15.3074ms]
[Line-13 InnerProduct Time : 3819.27ms]
[Line-13 Average InnerProduct Time : 14.919ms]
Aggregated InnerProduct Time : 7766ms
-----------------------------------------------------

[Line-2 Norm Time : 18.8318ms]
[Line-8 Norm Time : 6603.5ms]
[Line-8 Average Norm Time : 25.6945ms]
Aggregated Norm Time : 6621ms
-----------------------------------------------------

[Line-4 Copy Time : 34.1096ms]
[Line-13 Copy Time : 2141.6ms]
[Line-13 Average Copy Time : 8.36563ms]
Aggregated Copy Time : 2175ms
-----------------------------------------------------

[WriteAsImage Time : 0ms]
WriteAsImage Time : 0ms
-----------------------------------------------------

Total time : 29346ms
-----------------------------------------------------

[Conjugate Gradients Time : 29381.6ms]
-----------------------------------------------------
```

### LaplaceSolver_0_3 parallel execution
```bash
$ export OMP_NUM_THREADS=12
$ make
$ ./laplace_solver
...
...
Conjugate Gradients terminated after 256 iterations; residual norm (nu) = 0.000975892
-----------------------------------------------------

[Line-2 Laplacian Time : 15.5547ms]
[Line-6 Laplacian Time : 4987.46ms]
[Line-6 Average Laplacian Time : 19.4065ms]
Aggregated Laplacian Time : 5002ms
-----------------------------------------------------

[Line-2 Saxpy Time : 30.5737ms]
[Line-8 Saxpy Time : 5030.09ms]
[Line-8 Average Saxpy Time : 19.5723ms]
[Line-9-12 Saxpy Time : 35.5049ms]
[Line-9-12 Average Saxpy Time : 35.5049ms]
[Line-16 Saxpy Time : 7732.92ms]
[Line-16 Average Saxpy Time : 30.2067ms]
Aggregated Saxpy Time : 12827ms
-----------------------------------------------------

[Line-4 InnerProduct Time : 10.7883ms]
[Line-6 InnerProduct Time : 1444.16ms]
[Line-6 Average InnerProduct Time : 5.61929ms]
[Line-13 InnerProduct Time : 1315.97ms]
[Line-13 Average InnerProduct Time : 5.1405ms]
Aggregated InnerProduct Time : 2769ms
-----------------------------------------------------

[Line-2 Norm Time : 8.45493ms]
[Line-8 Norm Time : 1224.5ms]
[Line-8 Average Norm Time : 4.76458ms]
Aggregated Norm Time : 1232ms
-----------------------------------------------------

[Line-4 Copy Time : 18.3264ms]
[Line-13 Copy Time : 1307.69ms]
[Line-13 Average Copy Time : 5.10816ms]
Aggregated Copy Time : 1325ms
-----------------------------------------------------

[WriteAsImage Time : 0ms]
WriteAsImage Time : 0ms
-----------------------------------------------------

Total time : 23155ms
-----------------------------------------------------

[Conjugate Gradients Time : 23187.2ms]
-----------------------------------------------------
```