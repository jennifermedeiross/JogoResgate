#ifndef HELICOPTERO_HPP
#define HELICOPTERO_HPP

#include "ASCII_ENGINE/ObjetoDeJogo.hpp"
#include "Pessoa.hpp"

class Helicoptero : public ObjetoDeJogo
{
    private:
        unsigned capacidade, capacidadeMax;
        double tanque, tanqueMax, peso, pesoMax;

    public:
        Helicoptero(const ObjetoDeJogo &obj) :
            ObjetoDeJogo(obj), capacidade(2), capacidadeMax(2), tanque(500), tanqueMax(500), peso(200), pesoMax(200) {}

        Helicoptero(const ObjetoDeJogo &obj, unsigned capacidade, double tanque, double peso) :
            ObjetoDeJogo(obj), capacidade(capacidade), capacidadeMax(capacidade), tanque(tanque), tanqueMax(tanque), peso(peso), pesoMax(peso) {}
        
        virtual ~Helicoptero(){}

        void resgate();
        void abastecer();
        void subtrairPeso(int);
        void processoDeResgate(Pessoa &, int, int);

        // GETTERS E SETTERS
        unsigned getCapacidade() const{ return this->capacidade; }
        unsigned getCapacidadeMax() const { return this->capacidadeMax; }
        double getTanque() const{ return this->tanque; }
        double getTanqueMax() const { return this->tanqueMax; }
        double getPeso() const{ return this->peso; }
        double getPesoMax() const { return this->pesoMax; }

        void setCapacidade(unsigned);
        void setCapacidadeMax(unsigned);
        void setTanque(double);
        void setTanqueMax(double);
        void setPeso(double);
        void setPesoMax(double);

        // GAMEBASE
        virtual void update();        
};

#endif