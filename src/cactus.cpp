#include "cactus.h"
#include "utils.h"
#include <iostream>
namespace {

const unsigned Cactus_0[] = {
0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0xffff,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0xffff,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0xffff,0x0,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0x0,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0x0,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0x0
};
constexpr unsigned width_0 = 24;
constexpr unsigned height_0 = 19;

const unsigned Cactus_1[] = {
0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0xffff
};
constexpr unsigned width_1 = 10;
constexpr unsigned height_1 = 19;

const unsigned Cactus_2[] = {
0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0x0,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0xffff,0xffff
};
constexpr unsigned width_2 = 13;
constexpr unsigned height_2 = 24;

constexpr unsigned max_obstacles = 2;

}

Cactus::Cactus(int scale, int speed) : scale(scale), x_speed(speed), begin(false) {
    id = utils::rand() % 3;
    switch (id) {
        case 0:
            pixel = Cactus_0;
            origin_width = width_0;
            origin_height = height_0;
            break;
        case 1:
            pixel = Cactus_1;
            origin_width = width_1;
            origin_height = height_1;
            break;
        case 2:
            pixel = Cactus_2;
            origin_width = width_2;
            origin_height = height_2;
            break;
        default:
            break;
    }
    width = origin_width * scale;
    height = origin_height * scale;
    top = GROUND_Y_POS - height - GROUND_DISTANCE;
    left = SCREEN_WIDTH;
}

Cactus::Cactus(const Cactus &other) {
    scale = other.scale;
    id = other.id;
    x_speed = other.x_speed;
    begin = other.begin;
    pixel = other.pixel;
    origin_width = other.origin_width;
    origin_height = other.origin_height;
    width = other.width;
    height = other.height;
    top = other.top;
    left = other.left;
}

bool Cactus::crashed(const CollidableEntity& obstacle) const {
    return (top + height > obstacle.get_top() && top < obstacle.get_top() + obstacle.get_height() &&
            left + width > obstacle.get_left() && left < obstacle.get_left() + obstacle.get_width());
}

void Cactus::start() {
    begin = true;
}

void Cactus::reset() {
    begin = false;
    id = utils::rand() % 3;
    switch (id) {
        case 0:
            pixel = Cactus_0;
            origin_width = width_0;
            origin_height = height_0;
            break;
        case 1:
            pixel = Cactus_1;
            origin_width = width_1;
            origin_height = height_1;
            break;
        case 2:
            pixel = Cactus_2;
            origin_width = width_2;
            origin_height = height_2;
            break;
        default:
            break;
    }
    width = origin_width * scale;
    height = origin_height * scale;
    top = GROUND_Y_POS - height - GROUND_DISTANCE;
    left = SCREEN_WIDTH;
}

void Cactus::update(unsigned* framebuffer) {
    if (!begin) {
        return;
    }

    left -= x_speed;
    if (left + width < 0 || left > SCREEN_WIDTH) {
        std::cout << "***********************out of bound!!!" << std::endl;
        return;
    }

    for (int i = 0; i < origin_height; ++i) {
        for (int j = 0; j < origin_width; ++j) {
            unsigned color = pixel[i * origin_width + j];
            for (int dy = 0; dy < scale; ++dy) {
                for (int dx = 0; dx < scale; ++dx) {
                    int x = left + j * scale + dx;
                    int y = top + i * scale + dy;
                    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
                        utils::write_to_vga(y * SCREEN_WIDTH + x, color, framebuffer);
                    }
                }
            }
        }
    }
    
}

