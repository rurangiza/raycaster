# Writing a Raycasting Engine
Playground for creating a raycasting engine



## Basics
<details>
<summary>Setup SDL (Graphic Library)</summary>

I'll use [SDL](https://www.libsdl.org/) (Simple DirectMedia Layer). Which is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D

How to install:
1. Download **brew** with this command `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
2. Install the **SDL library** using brew: `brew install sdl2`
3. Add this header file `#include <SDL2/SDL.h>`
4. Compile like this: `gcc test.c -o test -lSDL2` [^1]
    - gcc is the compiler
    - test.c is the source file with all the code
    - -o test allows to rename the executable
    - -lSDL2 allows to access all functions defined by SDL

[^1]:
    N.B: if you get this error message :  **ld: library not found for -lSDL2**, it means that the [linker](https://en.wikipedia.org/wiki/Linker_(computing)) is unable to find the SDL2 library. Here are the steps to specify where the library is:
    1. `brew list sdl2` to show the installation path of the library
    3. Update your compilation command: -I`gcc -o test test.c /path_to_library/lib` -L`/path_to_header_files/include` -lSDL2

</details>

<details>
<summary>Game Structure</summary>

```C
int main() {
    // Initialize the game window and set a boolean flag to control the main game loop
    isGameRunning = initWindow();

    // Set up the initial game state, such as loading assets or initializing variables.
    setup();


    while (isGameRunning) {
        // Handle user input and update the game state accordingly.
        processInput();
        update();
        // Render the game state to the screen
        render();
    }

    // Clean up any resources that were allocated during the game
    destroyWindow();
    return 0;
}
```
</details>


<details>
<summary>Create a window (the canvas)</summary>

```C
SDL_Window *window = NULL;

int initWindow() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }

    // Create the window
    window = SDL_CreateWindow(
        NULL,                       // title
        SDL_WINDOWPOS_CENTERED,     // x position
        SDL_WINDOWPOS_CENTERED,     // y position
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        fprintf(stderr, "Error creating SDL window.\n");
        return FALSE;
    }

    // Create the renderer
    renderer = SDL_CreateRenderer(
        window,                     // window
        -1,                         // driver (-1 means default driver)
        0
    );
    if (!renderer) {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return FALSE;
    }

    // Set the blend mode for the renderer
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    return TRUE;
}
```
</details>


</details>

<details>
<summary>Take user input</summary>

```C
void    processInput() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            // Quit the game if the window is closed
            isGameRunning = FALSE;
            break ;

        case SDL_KEYDOWN: {
            // Handle key presses
            if (event.key.keysym.sym == SDLK_ESCAPE)
                // Quit the game if the escape key is pressed
                isGameRunning = FALSE;
            else if (event.key.keysym.sym == SDLK_DOWN)
                // Move the player down if the down arrow key is pressed
                playerY += 20;
            else if (event.key.keysym.sym == SDLK_UP)
                // Move the player up if the up arrow key is pressed
                playerY -= 20;
            break;
        }
    }
}
```
</details>


<details>
<summary>Draw something on the window</summary>

```C
void render() {
    // Set background color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw player rectangle in yellow
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect rect = {playerX, playerY, 20, 20};
    SDL_RenderFillRect(renderer, &rect);

    // Show the rendered frame
    SDL_RenderPresent(renderer);
}
```
</details>


# Useful Links
- [Ray casting](https://en.wikipedia.org/wiki/Ray_casting) (Wiki)
- [Raycasting Engine Programming with C](https://pikuma.com/courses/raycasting-engine-tutorial-algorithm-javascript) (Course)
- [Game Engine Black Book: Wolfenstein 3D](https://www.amazon.com/Game-Engine-Black-Book-Wolfenstein/dp/1539692876) (Book)
- [Running C games in the browser](https://medium.com/swlh/i-made-a-game-in-c-run-in-a-web-browser-and-so-can-you-2911b9fe2368)
- [Tutorial by Vinicius Reif Biavatti](https://github.com/vinibiavatti1/RayCastingTutorial/wiki)
