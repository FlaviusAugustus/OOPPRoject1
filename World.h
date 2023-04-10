#pragma once
#include <iostream>
#include <vector>

class Organism;

class World {

    size_t sizeX;
    size_t sizeY;
    char** worldArr;
    std::vector<Organism*> entities;

    public:

    World(size_t sizeX, size_t sizeY);

    ~World();

    void processTurn();

    void draw();

    bool isSpace(int x, int y);

    void addEntity(Organism* entity);

    int isCollision(Organism* ent);

    void sortOrganisms();

};


