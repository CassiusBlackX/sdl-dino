#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

#include "entity.h"
#include "trex.h"
#include "cactus.h"
#include "ground.h"
#include "score.h"
#include "utils.h"

unsigned framebuffer[SCREEN_WIDTH * SCREEN_HEIGHT];
unsigned vga_buffer[SCREEN_WIDTH * 3 * SCREEN_HEIGHT * 3];

void scale_framebuffer(const unsigned* framebuffer, unsigned* vga_buffer, int scale) {
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            unsigned color = framebuffer[y * SCREEN_WIDTH + x];
            for (int dy = 0; dy < scale; ++dy) {
                for (int dx = 0; dx < scale; ++dx) {
                    int vga_x = x * scale + dx;
                    int vga_y = y * scale + dy;
                    vga_buffer[vga_y * SCREEN_WIDTH * scale + vga_x] = color;
                }
            }
        }
    }
}

void render_game(SDL_Renderer* renderer, SDL_Texture* texture, uint32_t* framebuffer) {
    scale_framebuffer(framebuffer, vga_buffer, 3);
    SDL_UpdateTexture(texture, NULL, vga_buffer, SCREEN_WIDTH * 3 * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Dino Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * 3, SCREEN_HEIGHT * 3, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH * 3, SCREEN_HEIGHT * 3);
    if (!texture) {
        printf("Texture could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Clear the framebuffer
    memset(framebuffer, 0, sizeof(framebuffer));

    Trex trex(1, 12);
    Cactus cactus(1, 3);
    Ground ground(1, 10, 3);
    Score score(1, 3);

    bool quit = false;
    bool reset = false;
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
                            cactus.start();
                            trex.start();
                            ground.start();
                            score.start();
                            break;
                    }
            }

        }

        // Clear the framebuffer
        memset(framebuffer, 0, sizeof(framebuffer));

        // Update game state
        score.update(framebuffer);
        trex.update(framebuffer);
        cactus.update(framebuffer);
        if (cactus.outofbound()) {
            cactus.reset();
            cactus.start();
        }
        ground.update(framebuffer);

        if (trex.crashed(cactus)) {
            reset = true;
            trex.reset();
            ground.reset();
            cactus.reset();
            score.reset();
        }

        // Render game state
        render_game(renderer, texture, framebuffer);
        SDL_RenderPresent(renderer);

        // Calculate frame time and delay to maintain frame rate
        frame_time = SDL_GetTicks() - start_time;
        Uint32 expected_time = 1000 / FPS;
        if (frame_time < expected_time) {
            SDL_Delay(expected_time - frame_time);
        }

    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}