# raycaster
Playground for creating a raycasting engine

## How to display things on the screen
We'll use [SDL](https://www.libsdl.org/) (Simple DirectMedia Layer). Which is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D

How to install:
1. download brew
2. install the library using brew: `brew install sdl2`
3. add `#include <SDL2/SDL.h>` in your header file
4. compile like this: `gcc test.c -o test -lSDL2`

N.B: if you get this error message :  **ld: library not found for -lSDL2**, it means that the [linker](https://en.wikipedia.org/wiki/Linker_(computing)) is unable to find the SDL2 library. Here are the steps to specify where the library is:
1. `brew list sdl2` to show the installation path of the library
2. Look for two paths leading to folders:
    - one ending with `/lib` that's the path to the library
    - another ending with `/include` that's the path the library's [header files](https://www.tutorialspoint.com/cprogramming/c_header_files.htm)
3. update your compilation command: -I`gcc -o test test.c /path_to_library/lib` -L`/path_to_header_files/include` -lSDL2

## How to create a window, to render our graphics
## How to create a game loop
- frame rate? speed? 
## How to draw something on the window
## How to get input from the keyboard

# Useful Links
- [Ray casting](https://en.wikipedia.org/wiki/Ray_casting) (Wiki)
- [Raycasting Engine Programming with C](https://pikuma.com/courses/raycasting-engine-tutorial-algorithm-javascript) (Course)
- [Game Engine Black Book: Wolfenstein 3D](https://www.amazon.com/Game-Engine-Black-Book-Wolfenstein/dp/1539692876) (Book)