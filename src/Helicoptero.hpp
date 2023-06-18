#ifndef HELICOPTERO_HPP
#define HELICOPTERO_HPP

#include "ASCII_ENGINE/ObjetoDeJogo.hpp"

class Helicoptero : public ObjetoDeJogo
{
    private:
        unsigned capacidade, tanque, tanqueMax;

    public:
        Helicoptero(Sprite sprite, unsigned x, unsigned y) :
            ObjetoDeJogo(sprite, x, y), capacidade(2), tanque(20), tanqueMax(20) {}

        Helicoptero(SpriteAnimado sprite, unsigned x, unsigned y) :
            ObjetoDeJogo(sprite, x, y), capacidade(2), tanque(20), tanqueMax(20) {}

        Helicoptero(Sprite sprite, unsigned capacidade, unsigned tanque, unsigned x, unsigned y) :
            ObjetoDeJogo(sprite, x, y), capacidade(capacidade), tanque(tanque), tanqueMax(tanque) {}

        Helicoptero(SpriteAnimado sprite, unsigned capacidade, unsigned tanque, unsigned x, unsigned y) :
            ObjetoDeJogo(sprite, x, y), capacidade(capacidade), tanque(tanque), tanqueMax(tanque) {}
        
        virtual ~Helicoptero(){}

        void resgate();
        void abastecer();

        // GETTERS E SETTERS
        unsigned getCapacidade() const{ return this->capacidade; }
        unsigned getTanque() const{ return this->tanque; }
        unsigned getTanqueMax() const { return this->tanqueMax; }

        void setCapacidade(unsigned);
        void setTanque(unsigned);
        void setTanqueMax(unsigned);

        // GAMEBASE
        void update();

        
};

#endif