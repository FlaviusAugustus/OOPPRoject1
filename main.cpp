#include <iostream>
#include "World.h"
#include "Organism.h"

int main() {

    size_t x, y;
    std::cin >> x >> y;

    World world(x, y);
    world.draw();
    world.processTurn();

    return 0;
}
