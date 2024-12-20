#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
public:
    virtual void update(unsigned* framebuffer) = 0;
    virtual void start() = 0;
    virtual void reset() = 0;

    virtual unsigned get_top() const { return top; }
    virtual unsigned get_left() const { return left; }
    virtual unsigned get_width() const { return width; }
    virtual unsigned get_height() const { return height; }

    virtual bool outofbound() const { return left + width < 0; }

protected:
    // each entity has a position of top-left corner
    int top, left;
    int width, height;
};

#endif // ENTITY_H_