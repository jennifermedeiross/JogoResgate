#ifndef COMBUSTIVEL_HPP
#define COMBUSTIVEL_HPP

#include "ASCII_ENGINE/ObjetoDeJogo.hpp"

class Combustivel : public ObjetoDeJogo
{   
    public:
        Combustivel(ObjetoDeJogo & obj) :
            ObjetoDeJogo(obj){}
        ~Combustivel(){}
};

#endif