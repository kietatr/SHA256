# SHA256
## Kiet Tran and Katya Gurgel

An implementation of the hashing algorithm SHA-256 in C. 

This code closely follows the pseudocode provided in the official documentation **[FIPS 180-4](https://github.com/kietatr/SHA256/blob/master/NIST.FIPS.180-4.pdf), Section 6.2.2, page 22**.

## Demo Video

[Click here to view the demo video.](https://drive.google.com/file/d/1n7mqzZ77mDuZUgvySg3Ai88MnSLIkYXf/view?usp=sharing)

This video is also included in this repo under the name of **demo-video.mp4**

## How to compile and run

In your (Mac or Linux) Terminal or Windows Subsystem for Linux, run the following commands:

```
git clone https://github.com/kietatr/SHA256.git
cd SHA256
make
```

The `make` command will:
1. Compile the source code
2. Then run the compiled executable file for you

## Comparing runtime with another implementation

There isn't a standard C library for SHA-2, so we settled with an implementation from [amosnier](https://github.com/amosnier), which has been reviewed with the [Stack Exchange CODE
REVIEW](https://codereview.stackexchange.com/questions/182812/self-contained-sha-256-implementation-in-c).

To time the code of my implementation, run:

```
make time-my-implementation
```

To time the code of [amosnier](https://github.com/amosnier)'s implementation, run:

```
make time-other-implementation
```