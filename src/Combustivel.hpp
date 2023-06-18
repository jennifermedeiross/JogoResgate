#ifndef COMBUSTIVEL_HPP
#define COMBUSTIVEL_HPP

#include "ASCII_ENGINE/ObjetoDeJogo.hpp"

class Combustivel : public ObjetoDeJogo
{
    public:
        Combustivel(Sprite sprite, unsigned x, unsigned y) :
            ObjetoDeJogo(sprite, x, y){}
        ~Combustivel(){}
};

#endif