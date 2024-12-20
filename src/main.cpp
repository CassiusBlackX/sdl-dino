#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

#include "entity.h"
#include "trex.h"
#include "cactus.h"
#include "utils.h"

unsigned framebuffer[SCREEN_WIDTH * SCREEN_HEIGHT];


void render_game(SDL_Renderer* renderer, SDL_Texture* texture, uint32_t* framebuffer) {
    SDL_UpdateTexture(texture, NULL, framebuffer, SCREEN_WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Dino Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!texture) {
        printf("Texture could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Clear the framebuffer
    memset(framebuffer, 0, sizeof(framebuffer));

    // Trex trex(3, 1, SCREEN_HEIGHT-70-21*3, 100);
    // trex.start();
    Cactus cactus(1, 0, 1);
    

    bool quit = false;
    SDL_Event e;
    Uint32 start_time = 0;

    while (!quit) {
        start_time = SDL_GetTicks();

        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                        case SDLK_SPACE:
                            printf("Jump\n");
                            // trex.jump();  // delay jump for 10 frames
                            break;
                        case SDLK_UP:
                            std::cout << "start" << std::endl;
                            // trex.start();
                            break;
                    }
            }

        }

        // Clear the framebuffer
        memset(framebuffer, 0, sizeof(framebuffer));

        // trex.update(framebuffer);
        cactus.update(framebuffer);
        // Draw the current frame of the dinosaur
        // draw_dinosaur_frame(frame, 0, 0); // Position the dinosaur at (100, 100)

        // Render game state
        render_game(renderer, texture, framebuffer);

        SDL_RenderPresent(renderer);

    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}