#pragma once
#include <utility>

class Organism {

    protected:

    std::pair<int, int> position;
    int strength;
    int initiative;
    char texture;

    public:

    virtual void action(World& world) = 0;

    virtual void collision(World& world, Organism* other) = 0;

    virtual void draw(World& world) = 0;

    std::pair<int, int> getpos() const { return position; }

    char getTexture() { return texture;}

    friend bool compareByInitiative(Organism* o1, Organism* o2);

};


bool compareByInitiative(Organism* o1, Organism* o2) { return o1->initiative > o2->initiative; }



