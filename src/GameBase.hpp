#ifndef GAMEBASE_HPP
#define GAMEBASE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class SpriteBase;

class GameBase {

    public:
        GameBase(){}
        virtual ~GameBase() {}

        virtual void init() = 0;
        virtual void update() = 0;
        virtual void draw(SpriteBase &screen, unsigned x, unsigned y) = 0;
};

#endif
