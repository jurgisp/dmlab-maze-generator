#include <iostream>

#include "../src/maze_generator.h"

int main(int, char **) {
    for (int i = 0; i < 10; i++) {
        auto maze = createRandomMaze(i);
        std::cout << maze << std::endl;
    }
}
