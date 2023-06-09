#pragma once
#include "World.h"
#include "Organism.h"
class Plant : Organism {

    protected:

    int growthProbability;

    Plant();

    public:

    virtual void action(World &world) override;

    virtual void collision(World& world, Organism* other) override;

};



