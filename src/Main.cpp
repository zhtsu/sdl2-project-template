#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int kWindowWidth = 960;
const int kWindowHeight = 640;
const char kWindowTitle[] = "SDL2 Window";

int main(int argc, char* argv[])
{
    // Initialize
    if (SDL_Init(SDL_INIT_VIDEO != 0) && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
        SDL_Log("Failed to initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    SDL_WindowFlags window_flags = (SDL_WindowFlags) (SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow(kWindowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, kWindowWidth, kWindowHeight, window_flags);
    if (window == nullptr)
    {
        SDL_Log("Failed to create Window: %s\n", SDL_GetError());
        return false;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        SDL_Log("Failed to create Renderer: %s\n", SDL_GetError());
        return false;
    }

    // Main loop
    bool is_running = true;
    SDL_Event event;
    while (is_running)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            is_running = false;
        }

        SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);
        SDL_RenderClear(renderer);
        
        SDL_RenderPresent(renderer);
    }

    // Destroy
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();

    return 0;
}

