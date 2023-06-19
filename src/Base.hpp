#ifndef BASE_HPP
#define BASE_HPP

#include "ASCII_ENGINE/ObjetoDeJogo.hpp"

class Base : public ObjetoDeJogo
{
    public:
        Base(const ObjetoDeJogo & obj):
            ObjetoDeJogo(obj){}
        ~Base(){}
};

#endif