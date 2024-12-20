#include "lib/mem.h"
#include "lib/device.h"

#include "entity.h"
#include "trex.h"
#include "cactus.h"
#include "ground.h"
#include "utils.h"

unsigned framebuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

// TODO
void render_game(unsigned* framebuffer) {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            set_vram(j, i, framebuffer[i * SCREEN_WIDTH + j]);
        }
    }
    commit_vram();
}
int main(int argc, char* args[]) {
    

    // Clear the framebuffer
    memset(framebuffer, 0, sizeof(framebuffer));

    Trex trex(3, 20, 150);
    Cactus cactus(3, 0, 10);
    Ground ground(10, 30, 10);

    bool quit = false;
    SDL_Event e;
    unsigned start_time = 0;
    unsigned frame_time = 0;

    while (!quit) {
        start_time = time();

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
                            break;
                    }
            }

        }

        // Clear the framebuffer
        memset(framebuffer, 0, sizeof(framebuffer));

        // Update game state
        trex.update(framebuffer);
        cactus.update(framebuffer);
        if (cactus.outofbound()) {
            cactus.reset();
            cactus.start();
        }
        ground.update(framebuffer);

        if (trex.crashed(cactus)) {
            quit = true;
        }

        // Render game state
        render_game(framebuffer);

        // Calculate frame time and delay to maintain frame rate
        // on bare metal we cannot maintain frame rate!
        frame_time = time() - start_time;
        unsigned expected_time = 1000 / FPS;
        if (frame_time < expected_time) {
            sleep(expected_time - frame_time);
        }

    }


    return 0;
}