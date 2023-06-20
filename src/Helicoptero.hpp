#ifndef HELICOPTERO_HPP
#define HELICOPTERO_HPP

#include "ASCII_ENGINE/ObjetoDeJogo.hpp"

class Helicoptero : public ObjetoDeJogo
{
    private:
        unsigned capacidade, capacidadeMax;
        double tanque, tanqueMax;

    public:
        Helicoptero(const ObjetoDeJogo &obj) :
            ObjetoDeJogo(obj), capacidade(2), tanque(500), tanqueMax(500), capacidadeMax(2) {}

        Helicoptero(const ObjetoDeJogo &obj, unsigned capacidade, double tanque) :
            ObjetoDeJogo(obj), capacidade(capacidade), tanque(tanque), tanqueMax(tanque), capacidadeMax(capacidade) {}
        
        virtual ~Helicoptero(){}

        void resgate();
        void abastecer();

        // GETTERS E SETTERS
        unsigned getCapacidade() const{ return this->capacidade; }
        unsigned getCapacidadeMax() const { return this->capacidadeMax; }
        double getTanque() const{ return this->tanque; }
        double getTanqueMax() const { return this->tanqueMax; }

        void setCapacidade(unsigned);
        void setCapacidadeMax(unsigned);
        void setTanque(double);
        void setTanqueMax(double);

        // GAMEBASE
        virtual void update();        
};

#endif