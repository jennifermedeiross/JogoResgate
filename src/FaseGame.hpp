#ifndef FASEGAME_HPP
#define FASEGAME_HPP

#include "ASCII_ENGINE/Fase.hpp"
#include "ASCII_ENGINE/Teclado.hpp"
#include "Helicoptero.hpp"
#include "Combustivel.hpp"
#include "Base.hpp"
#include "Pessoa.hpp"

class FaseGame : public Fase
{
    private:
        Teclado teclado; // manipulação do teclado

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
        FaseGame(){}
        virtual ~FaseGame(){}

        void informa();

        virtual void run();

        //GAMEBASE
        virtual void init();
};

#endif
