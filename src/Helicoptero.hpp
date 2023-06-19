#ifndef HELICOPTERO_HPP
#define HELICOPTERO_HPP

#include "ASCII_ENGINE/ObjetoDeJogo.hpp"

class Helicoptero : public ObjetoDeJogo
{
    private:
        unsigned capacidade;
        double tanque, tanqueMax;

    public:
        Helicoptero(const ObjetoDeJogo & obj) :
            ObjetoDeJogo(obj), capacidade(2), tanque(20), tanqueMax(20) {}

        Helicoptero(const ObjetoDeJogo(&obj), unsigned capacidade, double tanque) :
            ObjetoDeJogo(obj), capacidade(capacidade), tanque(tanque), tanqueMax(tanque) {}
        
        virtual ~Helicoptero(){}

        void resgate();
        void abastecer();

        // GETTERS E SETTERS
        unsigned getCapacidade() const{ return this->capacidade; }
        double getTanque() const{ return this->tanque; }
        double getTanqueMax() const { return this->tanqueMax; }

        void setCapacidade(unsigned);
        void setTanque(double);
        void setTanqueMax(double);

        // GAMEBASE
        virtual void update();        
};

#endif