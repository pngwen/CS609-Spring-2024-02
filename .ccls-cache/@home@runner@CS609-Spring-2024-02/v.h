#include <SDL.h>

int main(int argc, char* args[]) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Set the coordinates for the left-top corner of the rectangle
    int x = 100;
    int y = 100;

    // Set the dimensions of the rectangle
    int width = 200;
    int height = 150;

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Rectangle with Coordinates",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set the draw color (in this case, white)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Create a rectangle
    SDL_Rect rect = { x, y, width, height };

    // Render the rectangle
    SDL_RenderFillRect(renderer, &rect);

    // Update the screen
    SDL_RenderPresent(renderer);

    // Wait for a key press before closing the window
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) !=
