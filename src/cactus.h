#ifndef CACTUS_H_
#define CACTUS_H_

#include "utils.h"
#include "entity.h"
class Cactus : public CollidableEntity {
public: 
    Cactus(int scale, int id, int x_speed);
    Cactus(const Cactus& other);
    ~Cactus() = default;

    void update(unsigned* framebuffer) override;
    void start() override;
    void reset() override;

    unsigned get_top() const override { return top; }
    unsigned get_left() const override { return left; }
    unsigned get_width() const override { return width * scale; }
    unsigned get_height() const override { return height * scale; }

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