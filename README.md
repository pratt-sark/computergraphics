# Computer Graphics (OPENGL Codes)

### Compilation
g++ test.cpp -o test_result.out -lGL -lGLU -lglut -lm

### Run 
./test_result.out


## SETUP
### For Ubuntu
##### Relatively Easy Installation for Ubuntu

* Open your terminal and update the repository using command: **sudo apt update** . After entering your password your update will be done .
* Type the following command : **sudo apt-get install freeglut3-dev**
* After completion, run a program to check successful installation.

### For Windows
##### Can't find definite installation steps, so I used WSL.

* Install [WSL1](https://docs.microsoft.com/en-us/windows/wsl/install).
* Open your terminal and update the repository using command: **sudo apt update** . After entering your password your update will be done .
* Type the following command : **sudo apt-get install freeglut3-dev**
* Install [VcXsrv](https://sourceforge.net/projects/vcxsrv/) and start a xserver (using XLaunch).
* Choose 'One Large Window' option. 
* Open Linux Shell and run OpenGL programs.

### Troubleshooting - Helpful Links
* [_failed to open display freeglut ''_](https://github.com/microsoft/WSL/issues/4106) 
* [_DISPLAY not set_](https://askubuntu.com/questions/432255/what-is-the-display-environment-variable)

--------------------------------------------------------------------------------

### [Use OpenGL Library to: ]

1. Write a program in C to draw a line by using DDA algorithm when two points are given.

2. Write a program in C to draw a line by using DDA algorithm when starting point, slope and number of iterations are given.

3. Write a program in C to draw two lines by using DDA algorithm when a common starting point, their slopes (unequal) and number of iterations are given.

4. Write a program in C to draw a line by using Bresenham Line Drawing Algorithm when two points are given.

5. Write a program in C to draw two parallel lines when two points are given for the first line and one point as starting point where x−value is same as in the starting point of the first line and y−value is increased by n (a natural number) for the second line by using Bresenham Line Drawing Algorithm.
