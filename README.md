# Computer Graphics (OPENGL Codes)

### Compilation
g++ test.cpp -o test_result.out -lGL -lGLU -lglut -lm

### Run 
./test_result.out


## SETUP
### For Ubuntu
##### Relatively Easy Installation for Ubuntu

* Open your terminal and update the repository using command: _**sudo apt update**_ . 
  After entering your password your update will be done .
* Type the following command : _**sudo apt-get install freeglut3-dev**_
* After completion, run a program to check successful installation.

### For Windows
##### Can't find definite installation steps, so I used WSL.

* Install [WSL1](https://docs.microsoft.com/en-us/windows/wsl/install).
* Open your terminal and update the repository using command: **sudo apt update** .
  After entering your password your update will be done .
* Type the following command : **sudo apt-get install freeglut3-dev**
* Install [VcXsrv](https://sourceforge.net/projects/vcxsrv/) and start a xserver (using XLaunch).
* Choose 'One Large Window' option. 
* Open Linux Shell and run OpenGL programs.

### Troubleshooting - Helpful Links
* [_failed to open display freeglut ''_](https://github.com/microsoft/WSL/issues/4106) 
* [_DISPLAY not set_](https://askubuntu.com/questions/432255/what-is-the-display-environment-variable)
* [*Interesting Read on X Windows DISPLAY Environment Variable*](https://superuser.com/questions/368530/understanding-x-windows-display-environment-variable-when-tunnelling)

--------------------------------------------------------------------------------

### [Use OpenGL Library to: ]

1. Write a program in C to draw a line by using DDA algorithm when two points are given.

2. Write a program in C to draw a line by using DDA algorithm when starting point, slope and number of iterations are given.

3. Write a program in C to draw two lines by using DDA algorithm when a common starting point, their slopes (unequal) and number of iterations are given.

4. Write a program in C to draw a line by using Bresenham Line Drawing Algorithm when two points are given.

5. Write a program in C to draw two parallel lines when two points are given for the first line and one point as starting point where x−value is same as in the starting point of the first line and y−value is increased by n (a natural number) for the second line by using Bresenham Line Drawing Algorithm.

6. Write a program in C to draw an n-sided polygon by using Bresenham’s line drawing algorithm when n points are given as input.

7. Write a program in C to draw a circle by using midpoint circle drawing algorithm.

8. Write a program in C to draw n concentric circles by using midpoint circle drawing algorithm.
 
9. Write a program in C to draw an ellipse by using midpoint ellipse drawing algorithm.
  
10. Write a program in C to draw n concentric ellipses by using midpoint ellipse drawing algorithm where the ratio of the greater diameter and the shorter diameter is same for all the ellipses.   
