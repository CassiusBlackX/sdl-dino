#ifndef CACTUS_H_
#define CACTUS_H_

#include "entity.h"
class Cactus : public Entity {
public: 
    Cactus(int scale, int id, int x_speed);
    ~Cactus() = default;

    void update(unsigned* framebuffer) override;
    void start() override {return;}
    void reset() override {return;}

    unsigned get_top() const override { return top; }
    unsigned get_left() const override { return left; }
    unsigned get_width() const override { return width; }
    unsigned get_height() const override { return height; }

    bool outofbound() const { return left + width < 0; }

private:
    

private:
    int scale;
    int id;
    int x_speed;
    const unsigned* pixel;
};

#endif  // CACTUS_H_