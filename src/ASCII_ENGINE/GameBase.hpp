#ifndef GAMEBASE_HPP
#define GAMEBASE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

class SpriteBase;

class GameBase {
    private:
        int altura_tela = 54;
        int largura_tela = 180;
    public:
        GameBase(){}
        virtual ~GameBase() {}

        virtual void init() = 0;
        virtual void update() = 0;
        virtual void draw(SpriteBase &screen, unsigned x, unsigned y) = 0;

        int ALTURA_TELA(){ return altura_tela; }
        int LARGURA_TELA(){ return largura_tela; }
};

#endif
