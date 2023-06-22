#ifndef FASEGAME_HPP
#define FASEGAME_HPP

#include "ASCII_ENGINE/Fase.hpp"
#include "Helicoptero.hpp"
#include "Combustivel.hpp"
#include "Base.hpp"
#include "Pessoa.hpp"
#include <iomanip>
#include <string>

class FaseGame : public Fase
{
    private:
        Helicoptero *pHelicoptero;
        Combustivel *pCombustivel;
        Base *pBase;
        Pessoa *pPessoa1;
        Pessoa *pPessoa2;
        Pessoa *pPessoa3;
        Pessoa *pPessoa4;
        Pessoa *pPessoa5;
        Pessoa *pPessoa6;

    public:
        FaseGame(std::string state) : Fase(state){}
        virtual ~FaseGame(){}

        void informativo(int, int, int, int, int, int);

        virtual void run();

        //GAMEBASE
        virtual void init();
};

#endif
