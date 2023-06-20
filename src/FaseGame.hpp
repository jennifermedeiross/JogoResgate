#ifndef FASEGAME_HPP
#define FASEGAME_HPP

#include "ASCII_ENGINE/Fase.hpp"
#include "Helicoptero.hpp"
#include "Combustivel.hpp"
#include "Base.hpp"
#include "Pessoa.hpp"

class FaseGame : public Fase
{
    public:
        FaseGame(){}
        virtual ~FaseGame(){}

        virtual void run(){}

        //GAMEBASE
        virtual void init();
};

#endif
