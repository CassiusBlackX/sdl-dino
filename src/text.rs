use crate::config::{SCORE_MAX_CHARS, SCORE_RIGHT_BOUND, SCORE_UP_BOUND, SCREEN_WIDTH};
use crate::entity::Entity;
use crate::utils::write_to_vga;

const CHAR_WIDTH: usize = 5;
const CHAR_HEIGHT: usize = 7;

static DIGITS_ALPHABETS: [[usize; CHAR_WIDTH * CHAR_HEIGHT]; 37] = [
    [
        // space
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0,
    ],
    [
        // 0
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // 1
        0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1,
        1, 1, 1, 1,
    ],
    [
        // 2
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
        1, 1, 1, 1,
    ],
    [
        // 3
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // 4
        0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0,
        0, 0, 1, 0,
    ],
    [
        // 5
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // 6
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // 7
        1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
        1, 0, 0, 0,
    ],
    [
        // 8
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // 9
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // A
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1,
        0, 0, 0, 1,
    ],
    [
        // B
        1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1,
        1, 1, 1, 0,
    ],
    [
        // C
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // D
        1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1,
        1, 1, 0, 0,
    ],
    [
        // E
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        1, 1, 1, 1,
    ],
    [
        // F
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        0, 0, 0, 0,
    ],
    [
        // G
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // H
        1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1,
        0, 0, 0, 1,
    ],
    [
        // I
        0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
        1, 1, 1, 0,
    ],
    [
        // J
        0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // K
        1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1,
        0, 0, 0, 1,
    ],
    [
        // L
        1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        1, 1, 1, 1,
    ],
    [
        // M
        1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1,
        0, 0, 0, 1,
    ],
    [
        // N
        1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1,
        0, 0, 0, 1,
    ],
    [
        // O
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // P
        1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        0, 0, 0, 0,
    ],
    [
        // Q
        0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0,
        1, 1, 0, 1,
    ],
    [
        // R
        1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1,
        0, 0, 0, 1,
    ],
    [
        // S
        0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1,
        1, 1, 1, 0,
    ],
    [
        // T
        1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 1, 0, 0,
    ],
    [
        // U
        1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
        1, 1, 1, 0,
    ],
    [
        // V
        1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
        0, 1, 0, 0,
    ],
    [
        // W
        1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1,
        0, 0, 0, 1,
    ],
    [
        // X
        1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1,
        0, 0, 0, 1,
    ],
    [
        // Y
        1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 1, 0, 0,
    ],
    [
        // Z
        1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        1, 1, 1, 1,
    ],
];

pub struct Text<'a> {
    top: i32,
    left: i32,
    width: usize,
    height: usize,
    begin: bool,
    x_speed: i32,
    scale: usize,
    heighest_score: i32,
    cur_score: i32,
    pixels: &'a [[usize; CHAR_WIDTH * CHAR_HEIGHT]; 37],
}

impl Text<'_> {
    pub fn new(scale: usize, x_speed: i32) -> Self {
        let width = (7 + 1 + 5 + 1 + SCORE_MAX_CHARS) * 5 * scale;
        Text {
            top: SCORE_UP_BOUND as i32,
            left: (SCREEN_WIDTH - SCORE_RIGHT_BOUND - width) as i32,
            width,
            height: 8 * scale * 2, // cur score + highest score, two lines
            cur_score: 0,
            heighest_score: 0,
            begin: false,
            scale,
            x_speed,
            pixels: &DIGITS_ALPHABETS,
        }
    }
}

impl Entity for Text<'_> {
    fn get_top(&self) -> i32 {
        self.top
    }

    fn get_height(&self) -> usize {
        self.height
    }

    fn get_left(&self) -> i32 {
        self.left
    }

    fn get_width(&self) -> usize {
        self.width
    }

    fn start(&mut self) {
        self.begin = true;
        self.cur_score = 0;
    }

    fn reset(&mut self) {
        self.begin = false;
        self.cur_score = 0;
    }

    fn update(&mut self, frame_buffer: &mut [u32]) {
        if self.begin {
            self.cur_score += self.x_speed;
        }
        if self.cur_score > self.heighest_score {
            self.heighest_score = self.cur_score
        }

        // get cur score digits
        let mut cur_score_digits = [0; SCORE_MAX_CHARS];
        let mut cur_copy = self.cur_score;
        for cur in cur_score_digits.iter_mut() {
            *cur = cur_copy % 10;
            cur_copy /= 10;
        }

        // get highest score digits
        let mut highest_score_digits = [0; SCORE_MAX_CHARS];
        let mut highest_copy = self.heighest_score;
        for high in highest_score_digits.iter_mut() {
            *high = highest_copy % 10;
            highest_copy /= 10;
        }

        // draw "highest score {highest_score}"
        let highest_score_str = "highest score";
        let total_length = 14 + SCORE_MAX_CHARS;
        let mut highest_score_char_index = [0; 14 + SCORE_MAX_CHARS];
        for (i, c) in highest_score_str.chars().enumerate() {
            highest_score_char_index[i] = if c.is_ascii_lowercase() {
                c as usize - 'a' as usize + 11
            } else {
                0
            };
        }
        for i in 0..SCORE_MAX_CHARS {
            highest_score_char_index[i + 14] =
                (highest_score_digits[SCORE_MAX_CHARS - 1 - i] + 1) as usize;
        }
        for i in 0..total_length {
            let char_index = highest_score_char_index[i];
            for j in 0..CHAR_HEIGHT {
                for k in 0..CHAR_WIDTH {
                    let color = if self.pixels[char_index][j * CHAR_WIDTH + k] == 1 {
                        0xffff
                    } else {
                        0
                    };
                    for dy in 0..self.scale {
                        for dx in 0..self.scale {
                            let address = (self.top as usize + j * self.scale + dy) * SCREEN_WIDTH
                                + (self.left as usize
                                    + i * CHAR_WIDTH * self.scale
                                    + k * self.scale
                                    + dx);
                            write_to_vga(address, color, frame_buffer);
                        }
                    }
                }
            }
        }

        // draw "cur score {cur_score}"
        let cur_score_str = "cur score     ";
        let mut cur_score_char_index = [0; 14 + SCORE_MAX_CHARS];
        for (i, c) in cur_score_str.chars().enumerate() {
            cur_score_char_index[i] = if c.is_ascii_lowercase() {
                c as usize - 'a' as usize + 11
            } else {
                0
            };
        }
        for i in 0..SCORE_MAX_CHARS {
            cur_score_char_index[i + 14] = (cur_score_digits[SCORE_MAX_CHARS - 1 - i] + 1) as usize;
        }
        for i in 0..total_length {
            let char_index = cur_score_char_index[i];
            for j in 0..CHAR_HEIGHT {
                for k in 0..CHAR_WIDTH {
                    let color = if DIGITS_ALPHABETS[char_index][j * CHAR_WIDTH + k] == 1 {
                        0xffff
                    } else {
                        0
                    };
                    for dy in 0..self.scale {
                        for dx in 0..self.scale {
                            let address = (self.top as usize
                                + (1 + CHAR_HEIGHT) * self.scale
                                + j * self.scale
                                + dy)
                                * SCREEN_WIDTH
                                + (self.left as usize
                                    + i * CHAR_WIDTH * self.scale
                                    + k * self.scale
                                    + dx);
                            write_to_vga(address, color, frame_buffer);
                        }
                    }
                }
            }
        }
    }
}

