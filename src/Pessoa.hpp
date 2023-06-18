#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "ASCII_ENGINE/ObjetoDeJogo.hpp"

class Pessoa : public ObjetoDeJogo
{
    private:
        double peso;
        bool resgatada;

    public:
        Pessoa(Sprite sprite, double peso, unsigned x, unsigned y) :
            ObjetoDeJogo(sprite, x, y), peso(peso), resgatada(false) {}

        Pessoa(SpriteAnimado sprite, double peso, unsigned x, unsigned y) :
            ObjetoDeJogo(sprite, x, y), peso(peso), resgatada(false) {}
        
        virtual ~Pessoa(){}
        
        double getPeso() const{ return this->peso; }
        void setPeso(double peso) { this->peso = peso; }

        void resgatar(){
            this->resgatada = true;
            this->desativar();
        }
};

#endif