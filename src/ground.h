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

    int get_top() const override { return top; }
    int get_left() const override { return left; }
    int get_width() const override { return width; }
    int get_height() const override { return height; }

private:
    int step;
    int x_speed;
    unsigned* pixel;
};

#endif  // GROUND_H_