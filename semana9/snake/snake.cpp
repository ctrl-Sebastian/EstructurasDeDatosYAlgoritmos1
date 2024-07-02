#include <iostream>
#include <conio.h>
#include "snake.h"
#include <chrono>
#include <thread>
#include <algorithm>


Snake::Snake(int startX, int startY) {
    body.push_back({startX, startY});
    direction = {0, 1}; // Initially moving to the right
}

void Snake::move(int dx, int dy) {
    std::pair<int, int> newHead = {body.front().first + dx, body.front().second + dy};
    body.push_front(newHead);
    body.pop_back();
}

void Snake::grow() {
    body.push_back(body.back());
}

bool Snake::checkCollision(int width, int height) const {
    std::pair<int, int> head = body.front();
    if (head.first < 0 || head.first >= width || head.second < 0 || head.second >= height) {
        return true;
    }
    auto it = body.begin();
    ++it;
    for (; it != body.end(); ++it) {
        if (head == *it) {
            return true;
        }
    }
    return false;
}

std::list<std::pair<int, int>> Snake::getBody() const {
    return body;
}

void printBoard(const Snake& snake, int width, int height) {
    auto body = snake.getBody();
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (std::find(body.begin(), body.end(), std::make_pair(x, y)) != body.end()) {
                std::cout << 'O';
            } else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
}

int main() {
    const int width = 20;
    const int height = 10;
    Snake snake(5, 5);

    char input;
    while (true) {
        system("cls");
        printBoard(snake, width, height);

        if (_kbhit()) {
            input = _getch();
            switch (input) {
                case 'w': snake.move(0, -1); break;
                case 's': snake.move(0, 1); break;
                case 'a': snake.move(-1, 0); break;
                case 'd': snake.move(1, 0); break;
            }
        }

        if (snake.checkCollision(width, height)) {
            std::cout << "Game Over!" << std::endl;
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
