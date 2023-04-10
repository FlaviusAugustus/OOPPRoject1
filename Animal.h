#include <iostream>
#include "World.h"
#include "Organism.h"

class Animal : Organism {

    void action(World& world) override;

    void collision(World& world, Organism* other) override;

};


