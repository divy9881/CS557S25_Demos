
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

### Laplacian_0_0
```bash
$ export OMP_NUM_THREADS=12
$ ./a.out
Running test iteration  1 [Elapsed time : 259.763ms]
Running test iteration  2 [Elapsed time : 208.351ms]
Running test iteration  3 [Elapsed time : 195.3ms]
Running test iteration  4 [Elapsed time : 194.297ms]
Running test iteration  5 [Elapsed time : 196.778ms]
Running test iteration  6 [Elapsed time : 192.959ms]
Running test iteration  7 [Elapsed time : 194.538ms]
Running test iteration  8 [Elapsed time : 195.132ms]
Running test iteration  9 [Elapsed time : 190.338ms]
Running test iteration 10 [Elapsed time : 193.233ms]

$ export OMP_NUM_THREADS=16
$ ./a.out
Running test iteration  1 [Elapsed time : 260.211ms]
Running test iteration  2 [Elapsed time : 165.945ms]
Running test iteration  3 [Elapsed time : 174.166ms]
Running test iteration  4 [Elapsed time : 168.871ms]
Running test iteration  5 [Elapsed time : 172.108ms]
Running test iteration  6 [Elapsed time : 173.916ms]
Running test iteration  7 [Elapsed time : 174.176ms]
Running test iteration  8 [Elapsed time : 172.79ms]
Running test iteration  9 [Elapsed time : 174.669ms]
Running test iteration 10 [Elapsed time : 167.569ms]

$ export OMP_NUM_THREADS=1 
$ ./a.out
Running test iteration  1 [Elapsed time : 1840.07ms]
Running test iteration  2 [Elapsed time : 1688.35ms]
Running test iteration  3 [Elapsed time : 2102.61ms]
Running test iteration  4 [Elapsed time : 1857.76ms]
Running test iteration  5 [Elapsed time : 1901.88ms]
Running test iteration  6 [Elapsed time : 1860.13ms]
Running test iteration  7 [Elapsed time : 1710.96ms]
Running test iteration  8 [Elapsed time : 1711.24ms]
Running test iteration  9 [Elapsed time : 1621.92ms]
Running test iteration 10 [Elapsed time : 1636.8ms]
```

### Laplacian_0_1
```bash
$ g++ -fopenmp main.cpp Laplacian.cpp 
$ ./a.out 
Running test iteration  1 [Elapsed time : 1625.82ms]
Running test iteration  2 [Elapsed time : 1305.19ms]
Running test iteration  3 [Elapsed time : 1252.47ms]
Running test iteration  4 [Elapsed time : 1226.65ms]
Running test iteration  5 [Elapsed time : 1227.53ms]
Running test iteration  6 [Elapsed time : 1444.25ms]
Running test iteration  7 [Elapsed time : 1521.99ms]
Running test iteration  8 [Elapsed time : 1431.96ms]
Running test iteration  9 [Elapsed time : 1300.86ms]
Running test iteration 10 [Elapsed time : 1376.65ms]
```

### Laplacian_0_10
```bash
$ export OMP_NUM_THREADS=1
$ g++ -fopenmp main.cpp Laplacian.cpp       
$ ./a.out 
Running test iteration  1 [Elapsed time : 1147.75ms]
Running test iteration  2 [Elapsed time : 863.454ms]
Running test iteration  3 [Elapsed time : 873.617ms]
Running test iteration  4 [Elapsed time : 869.885ms]
Running test iteration  5 [Elapsed time : 862.666ms]
Running test iteration  6 [Elapsed time : 861.781ms]
Running test iteration  7 [Elapsed time : 875.017ms]
Running test iteration  8 [Elapsed time : 876.798ms]
Running test iteration  9 [Elapsed time : 942.534ms]
Running test iteration 10 [Elapsed time : 911.522ms]

$ export OMP_NUM_THREADS=12
$ g++ -fopenmp main.cpp Laplacian.cpp       
$ ./a.out
Running test iteration  1 [Elapsed time : 208.992ms]
Running test iteration  2 [Elapsed time : 149.058ms]
Running test iteration  3 [Elapsed time : 153.368ms]
Running test iteration  4 [Elapsed time : 146.964ms]
Running test iteration  5 [Elapsed time : 134.869ms]
Running test iteration  6 [Elapsed time : 138.985ms]
Running test iteration  7 [Elapsed time : 144.533ms]
Running test iteration  8 [Elapsed time : 136.178ms]
Running test iteration  9 [Elapsed time : 142.118ms]
Running test iteration 10 [Elapsed time : 137.006ms]

$ export OMP_NUM_THREADS=1
$ g++ -fopenmp -O3 main.cpp Laplacian.cpp
$ ./a.out
Running test iteration  1 [Elapsed time : 211.509ms]
Running test iteration  2 [Elapsed time : 63.2545ms]
Running test iteration  3 [Elapsed time : 51.4643ms]
Running test iteration  4 [Elapsed time : 51.9892ms]
Running test iteration  5 [Elapsed time : 50.9392ms]
Running test iteration  6 [Elapsed time : 51.2919ms]
Running test iteration  7 [Elapsed time : 47.1985ms]
Running test iteration  8 [Elapsed time : 46.6652ms]
Running test iteration  9 [Elapsed time : 49.8423ms]
Running test iteration 10 [Elapsed time : 47.7982ms]

$ export OMP_NUM_THREADS=12
$ g++ -fopenmp -O3 main.cpp Laplacian.cpp
$ ./a.out
Running test iteration  1 [Elapsed time : 102.865ms]
Running test iteration  2 [Elapsed time : 27.5783ms]
Running test iteration  3 [Elapsed time : 24.4827ms]
Running test iteration  4 [Elapsed time : 20.9801ms]
Running test iteration  5 [Elapsed time : 19.7127ms]
Running test iteration  6 [Elapsed time : 19.7728ms]
Running test iteration  7 [Elapsed time : 20.7993ms]
Running test iteration  8 [Elapsed time : 21.0341ms]
Running test iteration  9 [Elapsed time : 20.4642ms]
Running test iteration 10 [Elapsed time : 20.1989ms]
```

### Laplacian_0_10_i_k_j
```bash
$ export OMP_NUM_THREADS=1
$ g++ -fopenmp main.cpp Laplacian.cpp 
$ ./a.out
Running test iteration  1 [Elapsed time : 3057.77ms]
Running test iteration  2 [Elapsed time : 2853.83ms]
Running test iteration  3 [Elapsed time : 3395.51ms]
Running test iteration  4 [Elapsed time : 3694.35ms]
Running test iteration  5 [Elapsed time : 3687.99ms]
Running test iteration  6 [Elapsed time : 3756.47ms]
Running test iteration  7 [Elapsed time : 3558.59ms]
Running test iteration  8 [Elapsed time : 3498.46ms]
Running test iteration  9 [Elapsed time : 3583.48ms]
Running test iteration 10 [Elapsed time : 3681.22ms]

$ export OMP_NUM_THREADS=12
$ g++ -fopenmp main.cpp Laplacian.cpp 
$ ./a.out
Running test iteration  1 [Elapsed time : 673.235ms]
Running test iteration  2 [Elapsed time : 592.706ms]
Running test iteration  3 [Elapsed time : 1441.84ms]
Running test iteration  4 [Elapsed time : 1333.27ms]
Running test iteration  5 [Elapsed time : 1267.31ms]
Running test iteration  6 [Elapsed time : 1146.56ms]
Running test iteration  7 [Elapsed time : 1164.49ms]
Running test iteration  8 [Elapsed time : 1162.9ms]
Running test iteration  9 [Elapsed time : 1170.88ms]
Running test iteration 10 [Elapsed time : 1190.74ms]

$ export OMP_NUM_THREADS=1 
$ g++ -fopenmp -O3 main.cpp Laplacian.cpp   
$ ./a.out
Running test iteration  1 [Elapsed time : 2590.84ms]
Running test iteration  2 [Elapsed time : 2431.09ms]
Running test iteration  3 [Elapsed time : 2596.82ms]
Running test iteration  4 [Elapsed time : 2706.1ms]
Running test iteration  5 [Elapsed time : 2680.12ms]
Running test iteration  6 [Elapsed time : 2782.16ms]
Running test iteration  7 [Elapsed time : 2666.74ms]
Running test iteration  8 [Elapsed time : 2663.05ms]
Running test iteration  9 [Elapsed time : 2671.61ms]
Running test iteration 10 [Elapsed time : 2667.71ms]

$ export OMP_NUM_THREADS=12
$ g++ -fopenmp -O3 main.cpp Laplacian.cpp 
$ ./a.out
Running test iteration  1 [Elapsed time : 670.787ms]
Running test iteration  2 [Elapsed time : 590.447ms]
Running test iteration  3 [Elapsed time : 1209.72ms]
Running test iteration  4 [Elapsed time : 1169.83ms]
Running test iteration  5 [Elapsed time : 953.676ms]
Running test iteration  6 [Elapsed time : 942.214ms]
Running test iteration  7 [Elapsed time : 876.86ms]
Running test iteration  8 [Elapsed time : 906.692ms]
Running test iteration  9 [Elapsed time : 873.619ms]
Running test iteration 10 [Elapsed time : 872.501ms]
```

### Laplacian_0_10_k_j_i
```bash
$ export OMP_NUM_THREADS=1  
$ g++ -fopenmp main.cpp Laplacian.cpp       
$ ./a.out
Running test iteration  1 [Elapsed time : 1407.23ms]
Running test iteration  2 [Elapsed time : 1267.08ms]
Running test iteration  3 [Elapsed time : 1183.8ms]
Running test iteration  4 [Elapsed time : 1243.87ms]
Running test iteration  5 [Elapsed time : 1220.7ms]
Running test iteration  6 [Elapsed time : 1321.42ms]
Running test iteration  7 [Elapsed time : 1333.21ms]
Running test iteration  8 [Elapsed time : 1931.56ms]
Running test iteration  9 [Elapsed time : 1924.34ms]
Running test iteration 10 [Elapsed time : 2074.67ms]

$ export OMP_NUM_THREADS=12
$ g++ -fopenmp main.cpp Laplacian.cpp 
$ ./a.out
Running test iteration  1 [Elapsed time : 319.025ms]
Running test iteration  2 [Elapsed time : 246.763ms]
Running test iteration  3 [Elapsed time : 245.948ms]
Running test iteration  4 [Elapsed time : 252.246ms]
Running test iteration  5 [Elapsed time : 263.021ms]
Running test iteration  6 [Elapsed time : 648.498ms]
Running test iteration  7 [Elapsed time : 774.168ms]
Running test iteration  8 [Elapsed time : 730.413ms]
Running test iteration  9 [Elapsed time : 673.438ms]
Running test iteration 10 [Elapsed time : 647.86ms]

$ export OMP_NUM_THREADS=1
$ g++ -fopenmp -O3 main.cpp Laplacian.cpp
$ ./a.out
Running test iteration  1 [Elapsed time : 1071.04ms]
Running test iteration  2 [Elapsed time : 925.586ms]
Running test iteration  3 [Elapsed time : 921.211ms]
Running test iteration  4 [Elapsed time : 911.208ms]
Running test iteration  5 [Elapsed time : 1168.2ms]
Running test iteration  6 [Elapsed time : 1373.03ms]
Running test iteration  7 [Elapsed time : 1295.81ms]
Running test iteration  8 [Elapsed time : 1634ms]
Running test iteration  9 [Elapsed time : 1538.17ms]
Running test iteration 10 [Elapsed time : 1383.13ms]

$ export OMP_NUM_THREADS=12
$ g++ -fopenmp -O3 main.cpp Laplacian.cpp
$ ./a.out
Running test iteration  1 [Elapsed time : 209.621ms]
Running test iteration  2 [Elapsed time : 185.079ms]
Running test iteration  3 [Elapsed time : 172.729ms]
Running test iteration  4 [Elapsed time : 202.188ms]
Running test iteration  5 [Elapsed time : 172.613ms]
Running test iteration  6 [Elapsed time : 180.068ms]
Running test iteration  7 [Elapsed time : 180.838ms]
Running test iteration  8 [Elapsed time : 182.361ms]
Running test iteration  9 [Elapsed time : 258.07ms]
Running test iteration 10 [Elapsed time : 602.208ms]
```