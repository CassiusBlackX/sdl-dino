#include "lib/mem.h"
#include "lib/device.h"

#include "entity.h"
#include "trex.h"
#include "cactus.h"
#include "ground.h"
#include "score.h"
#include "utils.h"

unsigned framebuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

void clearDisplayMemory() {
    memset(framebuffer, 0, sizeof(framebuffer));
}

void render_game(unsigned* framebuffer) {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j += 8) {
            unsigned val = 0;
            for (int k = 7; k >= 0; k--) {  // 反转处理顺序
                val = (val << 4) | (framebuffer[i * SCREEN_WIDTH + j + k] & 0xF);
            }
            set_vram(i, j / 8, val);
        }
    }
    commit_vram();
}


int main() {
    // Clear the framebuffer
    clearDisplayMemory();
    render_game(framebuffer);

    Trex trex(1, 12);
    Cactus cactus(1, 3);
    Ground ground(1, 10, 3);
    Score score(1, 1); 

    bool quit = false;
    bool start = false;
    bool jump = false;
    unsigned start_time = 0;
    unsigned frame_time = 0;
    int led_data = 0;
    trex.start();
    ground.start();
    cactus.start();
    // score.start();
    while (!quit) {
        set_led(led_data++);
        start_time = time();

        // if (get_button_state() != 0) {  // a button is pressed
        //     jump = get_jump_button_state();
        //     start = get_reset_button_state();

        //     if (jump) {
        //         trex.jump();
        //     }

        //     if (start) {
        //         trex.start();
        //         ground.start();
        //         cactus.start();
        //         score.start();
        //     }

        //     if (led_data > 0x3FF) {
        //         trex.start();
        //     }
        // }

        // Clear the framebuffer
        clearDisplayMemory();

        // Update game state
        trex.update(framebuffer);
        cactus.update(framebuffer);
        ground.update(framebuffer);
        score.update(framebuffer);

        // check cactus out of bound
        if (cactus.outofbound()) {
            cactus.reset();
            cactus.start();
        }

        // check crash
        // if (trex.crashed(cactus)) {
        //     start = false;
        //     trex.reset();
        //     ground.reset();
        //     cactus.reset();
        //     score.reset();
        // }

        // Render game state
        render_game(framebuffer);

        // Calculate frame time and delay to maintain frame rate
        // on bare metal we cannot maintain frame rate!
        frame_time = time() - start_time;
        unsigned expected_time = 10 / FPS;
        if (frame_time < expected_time) {
            sleep(expected_time - frame_time);
        }
    }
    return 0;
}