#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
public:
    virtual void update(unsigned* framebuffer) = 0;
    virtual void start() = 0;
    virtual void reset() = 0;

    virtual int get_top() const { return top; }
    virtual int get_left() const { return left; }
    virtual int get_width() const { return width; }
    virtual int get_height() const { return height; }

protected:
    // each entity has a position of top-left corner
    int top, left;
    int width, height;
};

class CollidableEntity : public Entity {
    // only those who should be considered to be a obstacle can crash
public:
    virtual bool crashed(const CollidableEntity& other) const = 0;
};

#endif // ENTITY_H_