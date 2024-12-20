#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

#include "entity.h"
#include "trex.h"
#include "cactus.h"
#include "ground.h"
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

    Trex trex(3, 20, 150);
    Cactus cactus(3, 0, 10);
    Ground ground(10, 30, 10);

    bool quit = false;
    SDL_Event e;
    Uint32 start_time = 0;
    Uint32 frame_time = 0;

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
                            trex.jump();  // delay jump for 10 frames
                            break;
                        case SDLK_UP:
                            std::cout << "start" << std::endl;
                            cactus.start();
                            trex.start();
                            ground.start();
                            break;
                    }
            }

        }

        // Clear the framebuffer
        memset(framebuffer, 0, sizeof(framebuffer));

        // Update game state
        trex.update(framebuffer);
        cactus.update(framebuffer);
        std::cout << "cactus left: " << cactus.get_left() << " cactus right: " << cactus.get_left() + cactus.get_width() << std::endl;
        if (cactus.outofbound()) {
            // std::cout << "***************cactus reset !!!!!" << std::endl;
            cactus.reset();
            cactus.start();
        }
        ground.update(framebuffer);

        if (trex.crashed(cactus)) {
            quit = true;
        }

        // Render game state
        render_game(renderer, texture, framebuffer);
        SDL_RenderPresent(renderer);

        // Calculate frame time and delay to maintain frame rate
        frame_time = SDL_GetTicks() - start_time;
        // std::cout << frame_time << std::endl;
        Uint32 expected_time = 1000 / FPS;
        if (frame_time < expected_time) {
            SDL_Delay(expected_time - frame_time);
        }
        // std::cout << "toatl time: " << SDL_GetTicks() - start_time << std::endl;

    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}