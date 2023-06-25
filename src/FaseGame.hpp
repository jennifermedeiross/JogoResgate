#ifndef FASEGAME_HPP
#define FASEGAME_HPP

#include "ASCII_ENGINE/Fase.hpp"
#include "Heroi.hpp"
#include "Combustivel.hpp"
#include "Base.hpp"
#include "Pessoa.hpp"
#include <iomanip>
#include <string>

class FaseGame : public Fase
{
    private:
        Heroi *pHeroi;
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
        virtual ~FaseGame(){
            Fase::~Fase();
            delete pHeroi;
            delete pCombustivel;
            delete pBase;
            delete pPessoa1;
            delete pPessoa2;
            delete pPessoa3;
            delete pPessoa4;
            delete pPessoa5;
            delete pPessoa6;
        }

        void informativo(int, int, int, int, int, int);

        virtual void run();

        //GAMEBASE
        virtual void init();
};

#endif
