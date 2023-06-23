#ifndef HEROI_HPP
#define HEROI_HPP

#include "ASCII_ENGINE/ObjetoDeJogo.hpp"
#include "Pessoa.hpp"

class Heroi : public ObjetoDeJogo
{
    private:
        unsigned capacidade, capacidadeMax;
        double tanque, tanqueMax, peso, pesoMax;

    public:
        Heroi(const ObjetoDeJogo &obj) :
            ObjetoDeJogo(obj), capacidade(2), capacidadeMax(2), tanque(600), tanqueMax(600), peso(150), pesoMax(150) {}

        Heroi(const ObjetoDeJogo &obj, unsigned capacidade, double tanque, double peso) :
            ObjetoDeJogo(obj), capacidade(capacidade), capacidadeMax(capacidade), tanque(tanque), tanqueMax(tanque), peso(peso), pesoMax(peso) {}
        
        virtual ~Heroi(){}

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