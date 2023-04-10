#include "Plant.h"

Plant::Plant() : Organism(), growthProbability() { initiative = 0; }

void Plant::collision(World &world, Organism* other) {}

void Plant::action(World &world) {

    if (rand() % 100 > growthProbability) {

        std::pair<int, int> newPlantPos = getRandomPosNearby(world);

        if(newPlantPos.first == -1) { return; }

        Organism* newPlant = getSelf();
        newPlant->setPos(newPlantPos);
        world.addEntity(newPlant);

    }
}