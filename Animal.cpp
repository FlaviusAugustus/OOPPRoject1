#include "Animal.h"
#include <typeinfo>
void Animal::collision(World &world, Organism *other) {

    if(typeid(this) == typeid(other)) {

        std::pair<int, int> newAnimalPos = getRandomPosNearby(world);

        if(newAnimalPos.first == -1) { return; }

        Organism* newAnimal = getSelf();
        newAnimal->setPos(newAnimalPos);
        world.addEntity(newAnimal);

    }
}

void Animal::action(World &world) {}