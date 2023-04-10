#pragma once
#include <utility>

class Organism {

    protected:

    std::pair<int, int> position;
    int strength;
    int initiative;
    char texture;
    int age;

    public:

    Organism() : strength(), initiative(), texture(' '), position(std::make_pair(-1, -1)) {}

    virtual void action(World& world) = 0;

    virtual void collision(World& world, Organism* other) = 0;

    virtual void draw(World& world) = 0;

    virtual Organism* getSelf() = 0;

    std::pair<int, int> getpos() const { return position; }

    void setPos(std::pair<int, int> newPos) { position = newPos; }

    char getTexture() const { return texture; }

    int getInitiative() const { return initiative;}

    int getAge() const { return age; }

    std::pair<int, int> getRandomPosNearby(World& world) {

        std::pair<int, int> oldPos = getpos();
        std::pair<int, int> newPos;

        int possiblePos[4][2] = {{0, 1},
                                 {0, -1},
                                 {1,0},
                                 {-1, 0}};

        for (int j = 0, i = rand() % 4; j < 4; i++, j++){

            if(world.isSpace(oldPos.first + possiblePos[i][0], oldPos.second + possiblePos[i][1])) {

               return std::make_pair(oldPos.first + possiblePos[i][0], oldPos.second + possiblePos[i][1]);

            }
        }

       return std::make_pair(-1, -1);

    }
};




