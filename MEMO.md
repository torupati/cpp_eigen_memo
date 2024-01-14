# CPP_EIGEN_MEMO

Here is my learning notebook to aquire how to implement CPP coding with EIGEN.

https://eigen.tuxfamily.org/dox/index.html


# Evnironment Setting

## Installation

In my WSL2, apt install was enough.

```
$ sudo apt install libeigen3-dev
...
Suggested packages:
  libeigen3-doc libmpfrc++-dev
The following NEW packages will be installed:
  libeigen3-dev
0 upgraded, 1 newly installed, 0 to remove and 135 not upgraded.
Need to get 815 kB of archives.
After this operation, 7161 kB of additional disk space will be used.
Get:1 http://archive.ubuntu.com/ubuntu focal/universe amd64 libeigen3-dev all 3.3.7-2 [815 kB]
Fetched 815 kB in 2s (343 kB/s)
Selecting previously unselected package libeigen3-dev.
(Reading database ... 85105 files and directories currently installed.)
Preparing to unpack .../libeigen3-dev_3.3.7-2_all.deb ...
Unpacking libeigen3-dev (3.3.7-2) ...
Setting up libeigen3-dev (3.3.7-2) ...
```

I could find where it was installed.

```
$ pkg-config --cflags eigen3
-I/usr/include/eigen3
```

