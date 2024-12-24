#include "score.h"
#include "utils.h"

#define CHAR_WIDTH 5
#define CHAR_HEIGHT 7

int Score::hightest_score = 0;

const unsigned Score::digits_alphabet[37][35] = {
    { // space
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    { // 0
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 1, 1,
        1, 0, 1, 0, 1,
        1, 1, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // 1
        0, 0, 1, 0, 0,
        0, 1, 1, 0, 0,
        1, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        1, 1, 1, 1, 1
    },
    { // 2
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        0, 0, 0, 0, 1,
        0, 0, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 0, 0, 0,
        1, 1, 1, 1, 1
    },
    { // 3
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        0, 0, 0, 0, 1,
        0, 0, 1, 1, 0,
        0, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // 4
        0, 0, 0, 1, 0,
        0, 0, 1, 1, 0,
        0, 1, 0, 1, 0,
        1, 0, 0, 1, 0,
        1, 1, 1, 1, 1,
        0, 0, 0, 1, 0,
        0, 0, 0, 1, 0
    },
    { // 5
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 0,
        0, 0, 0, 0, 1,
        0, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // 6
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // 7
        1, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        0, 0, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 0, 0, 0,
        0, 1, 0, 0, 0,
        0, 1, 0, 0, 0
    },
    { // 8
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // 9
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // A
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1
    },
    { // B
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 0
    },
    { // C
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // D
        1, 1, 1, 0, 0,
        1, 0, 0, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 1, 0,
        1, 1, 1, 0, 0
    },
    { // E
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 1
    },
    { // F
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0
    },
    { // G
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 0,
        1, 0, 0, 1, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // H
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1
    },
    { // I
        0, 1, 1, 1, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 1, 1, 1, 0
    },
    { // J
        0, 0, 0, 1, 1,
        0, 0, 0, 0, 1,
        0, 0, 0, 0, 1,
        0, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // K
        1, 0, 0, 0, 1,
        1, 0, 0, 1, 0,
        1, 0, 1, 0, 0,
        1, 1, 0, 0, 0,
        1, 0, 1, 0, 0,
        1, 0, 0, 1, 0,
        1, 0, 0, 0, 1
    },
    { // L
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 1
    },
    { // M
        1, 0, 0, 0, 1,
        1, 1, 0, 1, 1,
        1, 0, 1, 0, 1,
        1, 0, 1, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1
    },
    { // N
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 0, 0, 1,
        1, 0, 1, 0, 1,
        1, 0, 0, 1, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1
    },
    { // O
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // P
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0
    },
    { // Q
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 1, 0, 1,
        1, 0, 0, 1, 0,
        0, 1, 1, 0, 1
    },
    { // R
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 0,
        1, 0, 1, 0, 0,
        1, 0, 0, 1, 0,
        1, 0, 0, 0, 1
    },
    { // S
        0, 1, 1, 1, 1,
        1, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 1,
        0, 0, 0, 0, 1,
        1, 1, 1, 1, 0
    },
    { // T
        1, 1, 1, 1, 1,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0
    },
    { // U
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    },
    { // V
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 0, 1, 0,
        0, 0, 1, 0, 0
    },
    { // W
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 1, 0, 1,
        1, 0, 1, 0, 1,
        1, 1, 0, 1, 1,
        1, 0, 0, 0, 1
    },
    { // X
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 0, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1
    },
    { // Y
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0
    },
    { // Z
        1, 1, 1, 1, 1,
        0, 0, 0, 0, 1,
        0, 0, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 0, 0, 0,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 1
    }
};

Score::Score(int scale, int x_speed) : scale(scale), x_speed(x_speed), begin(false) {
    top = SCORE_UP_BOUND;
    width = (7 + 1 + 5 + 1 + SCORE_MAX_CHARS) * 5 * scale;  // highest score + cur score
    left = SCREEN_WIDTH - SCORE_RIGHT_BOUND - width;
    // 7 * pixel pixels for each line, 1 * scale pixel for space
    height = 8 * scale * 2;  // cur score + highest score, two lines, 
    cur_score = 0;
    hightest_score = 0;
}

void Score::reset() {
    cur_score = 0;
    begin = false;
}

void Score::start() {
    begin = true;
    cur_score = 0;
}

void Score::update(unsigned* framebuffer) {
    // update cur score
    if (begin) {
        cur_score += x_speed;
    }
    if (cur_score > hightest_score) {
        hightest_score = cur_score;
    }

    // get cur score digits
    int cur_score_digits[SCORE_MAX_CHARS];
    int cur_score_copy = cur_score;
    for (int i = 0; i < SCORE_MAX_CHARS; i++) {
        cur_score_digits[i] = cur_score_copy % 10;
        cur_score_copy /= 10;
    }
    
    // get highest score digits
    int highest_score_digits[SCORE_MAX_CHARS];
    int highest_score_copy = hightest_score;
    for (int i = 0; i < SCORE_MAX_CHARS; i++) {
        highest_score_digits[i] = highest_score_copy % 10;
        highest_score_copy /= 10;
    }
    
    // draw 'highest score {highest_score}'
    char highest_score_char[] = "highest score ";
    int highest_score_char_index[14 + SCORE_MAX_CHARS];
    for (int i = 0; i < 14; i++) {
        // if cur char is space, index < 0, then real char index should be 0
        highest_score_char_index[i] = highest_score_char[i] - 'a' + 1 < 0 ? 0 : highest_score_char[i] - 'a' + 11;
    }
    for (int i = 0; i < SCORE_MAX_CHARS; i++) {
        highest_score_char_index[14 + i] = highest_score_digits[SCORE_MAX_CHARS - 1 - i] + 1;
    }
    for (int i = 0; i < 14 + SCORE_MAX_CHARS; i++) {
        int char_index = highest_score_char_index[i];
        for (int j = 0; j < CHAR_HEIGHT; j++) {
            for (int k=0; k < CHAR_WIDTH; k++) {
                unsigned color = digits_alphabet[char_index][j * CHAR_WIDTH + k] == 1 ? 0xFFFF : 0x0000;
                for (int dy = 0; dy < scale; dy++) {
                    for (int dx = 0; dx < scale; dx++) {
                        utils::write_to_vga((top + j * scale + dy) * SCREEN_WIDTH + (left + i * CHAR_WIDTH * scale + k * scale + dx), color, framebuffer);
                    }
                }
            }
        }
    }

    // draw 'cur score {cur_score}'
    char cur_score_char[] = "cur score     ";
    int cur_score_char_index[14 + SCORE_MAX_CHARS];
    for (int i = 0; i < 14; i++) {
        cur_score_char_index[i] = cur_score_char[i] - 'a' + 1 < 0 ? 0 : cur_score_char[i] - 'a' + 11;
    }
    for (int i = 0; i < SCORE_MAX_CHARS; i++) {
        cur_score_char_index[14 + i] = cur_score_digits[SCORE_MAX_CHARS - 1 - i] + 1;
    }
    for (int i = 0; i < 14 + SCORE_MAX_CHARS; i++) {
        int char_index = cur_score_char_index[i];
        for (int j = 0; j < CHAR_HEIGHT; j++) {
            for (int k=0; k < CHAR_WIDTH; k++) {
                unsigned color = digits_alphabet[char_index][j * CHAR_WIDTH + k] == 1 ? 0xFFFF : 0x0000;
                for (int dy = 0; dy < scale; dy++) {
                    for (int dx = 0; dx < scale; dx++) {
                        utils::write_to_vga((top + (1 + CHAR_HEIGHT) * scale + j * scale + dy) * SCREEN_WIDTH + (left + i * CHAR_WIDTH * scale + k * scale + dx), color, framebuffer);
                    }
                }
            }
        }
    }

    // draw start menu
    if (!begin){
        char start_menu[] = "middle to start";
        for (int i = 0; i < 15; i++) {
            int char_index = start_menu[i] - 'a' + 1 < 0 ? 0 : start_menu[i] - 'a' + 11;
            for (int j = 0; j < CHAR_HEIGHT; j++) {
                for (int k=0; k < CHAR_WIDTH; k++) {
                    unsigned color = digits_alphabet[char_index][j * CHAR_WIDTH + k] == 1 ? 0xFFFF : 0x0000;
                    for (int dy = 0; dy < scale; dy++) {
                        for (int dx = 0; dx < scale; dx++) {
                            utils::write_to_vga((START_Y_POS + j * scale + dy) * SCREEN_WIDTH + (START_X_POS + i * CHAR_WIDTH * scale + k * scale + dx), color, framebuffer);
                        }
                    }
                }
            }
        }
        char start_menu2[] = "up to jump";
        for (int i = 0; i < 10; i++) {
            int char_index = start_menu2[i] - 'a' + 1 < 0 ? 0 : start_menu2[i] - 'a' + 11;
            for (int j = 0; j < CHAR_HEIGHT; j++) {
                for (int k=0; k < CHAR_WIDTH; k++) {
                    unsigned color = digits_alphabet[char_index][j * CHAR_WIDTH + k] == 1 ? 0xFFFF : 0x0000;
                    for (int dy = 0; dy < scale; dy++) {
                        for (int dx = 0; dx < scale; dx++) {
                            utils::write_to_vga((START_Y_POS + (1 + CHAR_HEIGHT) * scale + j * scale + dy) * SCREEN_WIDTH + (START_X_POS + i * CHAR_WIDTH * scale + k * scale + dx), color, framebuffer);
                        }
                    }
                }
            }
        }
    }

}