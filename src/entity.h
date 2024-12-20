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

protected:
    // each entity has a position of top-left corner
    unsigned top, left;
    unsigned width, height;
};

class CollidableEntity : public Entity {
    // only those who should be considered to be a obstacle can crash
public:
    virtual bool crashed(const CollidableEntity& other) const = 0;
};

#endif // ENTITY_H_