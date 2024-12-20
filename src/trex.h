#ifndef TREX_H_
#define TREX_H_

#include "entity.h"

class Trex : public Entity {
public:
    Trex(int scale, int y_speed, int initial_y, int jump_height);
    ~Trex() = default;
    void update(unsigned* framebuffer) override;
    void start() override { status = RUNNING; }
    void reset() override { status = HALTING; top = initial_y; }

    unsigned get_top() const override { return top; }
    unsigned get_left() const override { return left; }
    unsigned get_width() const override { return width; }
    unsigned get_height() const override { return height; }

    bool outofbound() const { return false; }  // dino never out of bound

    void jump();
private:
    bool crashed(const Entity& cactus) const;

private:
    enum Status {RUNNING, JUMPING, FALLING, HALTING, CRASHED};
    Status status;  // only can jump when RUNNING
    int initial_y;
    int y_speed;
    int scale;
    int jump_height;  // max height of jump
    static int pixels[][420];  // 21x20 pixels
    int frame_id;
};


#endif  // TREX_H_