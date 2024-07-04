#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <utility>

class Snake {
public:
    Snake(int startX, int startY);
    void move(int dx, int dy);
    void grow();
    bool checkCollision(int width, int height) const;
    std::list<std::pair<int, int>> getBody() const;

private:
    std::list<std::pair<int, int>> body;
    std::pair<int, int> direction;
};

#endif
