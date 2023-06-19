#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "ASCII_ENGINE/ObjetoDeJogo.hpp"

class Pessoa : public ObjetoDeJogo
{
    private:
        double peso;
        bool resgatada;

    public:
        Pessoa(ObjetoDeJogo &obj, double peso) :
            ObjetoDeJogo(obj), peso(peso), resgatada(false) {}
        
        virtual ~Pessoa(){}
        
        double getPeso() const{ return this->peso; }
        void setPeso(double peso) { this->peso = peso; }

        void resgatar(){
            this->resgatada = true;
        }
};

#endif