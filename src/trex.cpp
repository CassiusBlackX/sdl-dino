#include "trex.h"
#include "utils.h"

int Trex::pixels[][420] = {
    {
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff
    },
    {
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff

    },
    {
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff
    },
    {
        0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0x0,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0x0,0x0,0x0,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0x0,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0x0,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0x0,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff
    }
};

Trex::Trex(int scale, int s, int h) : scale(scale), y_speed(s), jump_height(h), status(HALTING) {
    width = 21 * scale;
    height = 20 * scale;
    frame_id = 0;
    top = GROUND_Y_POS - height - GROUND_DISTANCE;
    left = TREX_X_POS;
    initial_y = top;
    velocity_y = 0;
}


void Trex::jump() {
    if (status == RUNNING) {
        status = JUMPING;
        velocity_y = -y_speed;
    }
}

bool Trex::crashed(const CollidableEntity& obstacle) const {
    unsigned bottom1 = top + height;
    unsigned right1 = left + width;
    unsigned bottom2 = obstacle.get_top() + obstacle.get_height();
    unsigned right2 = obstacle.get_left() + obstacle.get_width();

    if (left >= right2 || obstacle.get_left() >= right1 || top >= bottom2 || obstacle.get_top() >= bottom1) {
        return false;
    }
    return true;
}

void Trex::update(unsigned* framebuffer) {
    switch (status) {
        case RUNNING:
            frame_id = (frame_id + 1) % 3;
            break;
        case JUMPING:
            velocity_y += GRAVITY;
            top += velocity_y;
            if (top >= initial_y) {
                top = initial_y;
                status = RUNNING;
                velocity_y = 0;
            }
            frame_id = (frame_id + 1) % 3;
            break;
        case HALTING:
            frame_id = 3;  // when halting, only show the first frame
            break;
    }

    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 20; ++j) {
            unsigned color = pixels[frame_id][i * 20 + j];
            for (int dy = 0; dy < scale; ++dy) {
                for (int dx = 0; dx < scale; ++dx) {
                    utils::write_to_vga((top + i * scale + dy) * SCREEN_WIDTH + (left + j * scale + dx), color, framebuffer);
                }
            }
        }
    }
}