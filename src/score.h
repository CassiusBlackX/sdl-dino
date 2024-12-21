#ifndef SCORE_H_
#define SCORE_H_

#include "entity.h"
class Score : public Entity {
public:
    Score(int scale, int x_speed);
    // Score(const Score& other);
    ~Score() = default;

    void update(unsigned* framebuffer) override;
    void start() override;
    void reset() override;

    int get_top() const override { return top; }
    int get_left() const override { return left; }
    int get_width() const override { return width; }
    int get_height() const override { return height; }

private:
    bool begin;
    int x_speed;
    int scale;
    static int hightest_score;
    int cur_score;
    static const unsigned digits_alphabet[37][35];  // 5x7 pixels
};

#endif  // SCORE_H_