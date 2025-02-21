
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




### LaplaceSolver_0_3 Merged serial execution
```bash
$ export OMP_NUM_THREADS=1
$ make
$ ./laplace_solver
...
...
Conjugate Gradients terminated after 256 iterations; residual norm (nu) = 0.000975892
-----------------------------------------------------

[Line-2 Laplacian Time : 27.428ms]
[Line-6 Laplacian Time : 2971.38ms]
[Line-6 Average Laplacian Time : 11.5618ms]
Aggregated Laplacian Time : 2998ms
-----------------------------------------------------

[Line-2 Saxpy Time : 30.1041ms]
[Line-8 Saxpy Time : 2290.66ms]
[Line-8 Average Saxpy Time : 8.91306ms]
[Line-9-12 Saxpy Time : 8.45638ms]
[Line-9-12 Average Saxpy Time : 8.45638ms]
[Line-16 Saxpy Time : 3491.99ms]
[Line-16 Average Saxpy Time : 13.6406ms]
Aggregated Saxpy Time : 5819ms
-----------------------------------------------------

[Line-4 InnerProduct Time : 12.61ms]
[Line-6 InnerProduct Time : 2984.67ms]
[Line-6 Average InnerProduct Time : 11.6135ms]
Aggregated InnerProduct Time : 2996ms
-----------------------------------------------------

[Line-2 Norm Time : 14.8673ms]
[Line-8 Norm Time : 4431.27ms]
[Line-8 Average Norm Time : 17.2423ms]
Aggregated Norm Time : 4445ms
-----------------------------------------------------

[Line-4 Copy Time : 31.2045ms]
Aggregated Copy Time : 31ms
-----------------------------------------------------

[Merged Line-13 Time : 2937.03ms]
[Merged Line-13 Average Time : 11.4728ms]
-----------------------------------------------------

[WriteAsImage Time : 0ms]
WriteAsImage Time : 0ms
-----------------------------------------------------

Total time : 19226ms
-----------------------------------------------------

[Conjugate Gradients Time : 19594.6ms]
-----------------------------------------------------
```




### LaplaceSolver_0_3 Merged parallel execution
```bash
$ export OMP_NUM_THREADS=12
$ make
$ ./laplace_solver
...
...
Conjugate Gradients terminated after 256 iterations; residual norm (nu) = 0.000975892
-----------------------------------------------------

[Line-2 Laplacian Time : 13.9378ms]
[Line-6 Laplacian Time : 3745.64ms]
[Line-6 Average Laplacian Time : 14.5745ms]
Aggregated Laplacian Time : 3758ms
-----------------------------------------------------

[Line-2 Saxpy Time : 48.0553ms]
[Line-8 Saxpy Time : 3872.32ms]
[Line-8 Average Saxpy Time : 15.0674ms]
[Line-9-12 Saxpy Time : 43.2465ms]
[Line-9-12 Average Saxpy Time : 43.2465ms]
[Line-16 Saxpy Time : 4627.62ms]
[Line-16 Average Saxpy Time : 18.0767ms]
Aggregated Saxpy Time : 8590ms
-----------------------------------------------------

[Line-4 InnerProduct Time : 15.3389ms]
[Line-6 InnerProduct Time : 1074.53ms]
[Line-6 Average InnerProduct Time : 4.18104ms]
Aggregated InnerProduct Time : 1089ms
-----------------------------------------------------

[Line-2 Norm Time : 9.66278ms]
[Line-8 Norm Time : 670.698ms]
[Line-8 Average Norm Time : 2.60972ms]
Aggregated Norm Time : 679ms
-----------------------------------------------------

[Line-4 Copy Time : 25.7142ms]
Aggregated Copy Time : 25ms
-----------------------------------------------------

[Merged Line-13 Time : 1063.42ms]
[Merged Line-13 Average Time : 4.154ms]
-----------------------------------------------------

[WriteAsImage Time : 0ms]
WriteAsImage Time : 0ms
-----------------------------------------------------

Total time : 15204ms
-----------------------------------------------------

[Conjugate Gradients Time : 15228.4ms]
-----------------------------------------------------
```

### LaplaceSolver_0_3 Merged parallel execution
```bash
$ export OMP_NUM_THREADS=12
$ make
$ ./laplace_solver
...
...
Conjugate Gradients terminated after 256 iterations; residual norm (nu) = 0.000975892
-----------------------------------------------------

[Line-2 Laplacian Time : 13.9378ms]
[Line-6 Laplacian Time : 3745.64ms]
[Line-6 Average Laplacian Time : 14.5745ms]
Aggregated Laplacian Time : 3758ms
-----------------------------------------------------

[Line-2 Saxpy Time : 48.0553ms]
[Line-8 Saxpy Time : 3872.32ms]
[Line-8 Average Saxpy Time : 15.0674ms]
[Line-9-12 Saxpy Time : 43.2465ms]
[Line-9-12 Average Saxpy Time : 43.2465ms]
[Line-16 Saxpy Time : 4627.62ms]
[Line-16 Average Saxpy Time : 18.0767ms]
Aggregated Saxpy Time : 8590ms
-----------------------------------------------------

[Line-4 InnerProduct Time : 15.3389ms]
[Line-6 InnerProduct Time : 1074.53ms]
[Line-6 Average InnerProduct Time : 4.18104ms]
Aggregated InnerProduct Time : 1089ms
-----------------------------------------------------

[Line-2 Norm Time : 9.66278ms]
[Line-8 Norm Time : 670.698ms]
[Line-8 Average Norm Time : 2.60972ms]
Aggregated Norm Time : 679ms
-----------------------------------------------------

[Line-4 Copy Time : 25.7142ms]
Aggregated Copy Time : 25ms
-----------------------------------------------------

[Merged Line-13 Time : 1063.42ms]
[Merged Line-13 Average Time : 4.154ms]
-----------------------------------------------------

[WriteAsImage Time : 0ms]
WriteAsImage Time : 0ms
-----------------------------------------------------

Total time : 15204ms
-----------------------------------------------------

[Conjugate Gradients Time : 15228.4ms]
-----------------------------------------------------
```