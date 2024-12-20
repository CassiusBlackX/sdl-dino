#ifndef GROUND_H_
#define GROUND_H_

#include "entity.h"
class Ground : public Entity {
public:
    Ground(int thickness, int step, int x_speed);
    ~Ground() = default;

    void update(unsigned* framebuffer) override;
    void start() override;
    void reset() override;

    unsigned get_top() const override { return top; }
    unsigned get_left() const override { return left; }
    unsigned get_width() const override { return width; }
    unsigned get_height() const override { return height; }

private:
    int step;
    int x_speed;
    unsigned* pixel;
};

#endif  // GROUND_H_