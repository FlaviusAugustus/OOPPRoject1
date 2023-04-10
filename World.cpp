#include <algorithm>
#include "World.h"
#include "Organism.h"


World::World(size_t sizeX, size_t sizeY) : sizeX(sizeX), sizeY(sizeY) {

    worldArr = new char*[sizeY];
    for(size_t i = 0; i < sizeY; i++) {

        worldArr[i] = new char[sizeX];

        for(size_t j = 0; j < sizeX; j++) {

            worldArr[i][j] = ' ';

        }
    }
}

World::~World() {

    for(size_t i = 0; i < sizeY; i++) {

        delete[] worldArr[i];

    }

    delete[] worldArr;

}

void World::draw() {

    for(int i = 0; i < sizeY; i++) {

        for (int j = 0; j < sizeX; j++) {

            std::cout << worldArr[i][j] << " ";

        }

        std::cout << '\n';

    }
}

bool World::isSpace(int x, int y) {

   return worldArr[x][y] != ' ';

}

void World::addEntity(Organism* entity) {

    entities.push_back(entity);
    worldArr[entity->getpos().second][entity->getpos().first] = entity->getTexture();

}

void World::processTurn() {

    sortOrganisms();

    for (Organism* ent: entities) {

        ent->action(*this);
        int index = isCollision(ent);
        if(index != -1) { ent->collision(*this, entities[index]); }

    }
}

int World::isCollision(Organism *ent) {

    auto other = std::find_if(entities.begin(), entities.end(),
                              [ent](const Organism* o){ return o->getpos() == ent->getpos() && o != ent;});

    //if element is not found find_if returns entities.end()
    if(other == entities.end() && ent->getpos() != entities.back()->getpos()) { return -1;}
    int index = std::distance(entities.begin(), other);

    return index;

}

void World::sortOrganisms() {

    auto comp = [](const Organism* o1,const Organism* o2) -> int {

        if(o1->getInitiative() != o2->getInitiative()) {

            return o1->getInitiative() > o2->getInitiative();

        }
        else {

            return o1->getAge() > o2->getAge();

        }};

    std::sort(entities.begin(), entities.end(), comp);

}