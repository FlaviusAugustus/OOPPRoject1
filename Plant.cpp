#include "Plant.h"

Plant::Plant() : Organism(), growthProbability() { initiative = 0; }

void Plant::collision(World &world, Organism* other) {}

void Plant::action(World &world) {

    for(int i = 0; i < growthAttempts; i++) {

        if (rand() % 100 > growthProbability) {

            bool isCorectPos = false;
            int posX;
            int posY;

            while (!isCorectPos) {

                posX = rand() % 4;
                posY = rand() % 4;

                if(world.isSpace(posX, posY)) {

                    //world.addEntity(new ));
                    isCorectPos = true;

                }
            }
        }
    }
}