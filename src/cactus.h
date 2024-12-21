#ifndef CACTUS_H_
#define CACTUS_H_

#include "utils.h"
#include "entity.h"
class Cactus : public CollidableEntity {
public: 
    Cactus(int scale, int x_speed);
    Cactus(const Cactus& other);
    ~Cactus() = default;

    void update(unsigned* framebuffer) override;
    void start() override;
    void reset() override;

    int get_top() const override { return top; }
    int get_left() const override { return left; }
    int get_width() const override { return width; }
    int get_height() const override { return height; }

    bool outofbound() const { return left + width < 0; }
    bool crashed(const CollidableEntity& obstacle) const override;

private:
    bool begin;
    int origin_width;
    int origin_height;
    int scale;
    int id;
    int x_speed;
    const unsigned* pixel;
};

#endif  // CACTUS_H_