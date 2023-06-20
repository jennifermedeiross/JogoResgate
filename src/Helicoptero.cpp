#include "Helicoptero.hpp"

void Helicoptero::resgate(){
    if(getCapacidade() <= getCapacidadeMax() && getCapacidade() > 0){
        this->capacidade -= 1;
    }
}

void Helicoptero::abastecer(){
    int limite = getTanque() + (getTanqueMax()/5);

    if(limite < getTanqueMax()){
        setTanque(limite);
    } else {
        setTanque(getTanqueMax());
    }
}

void Helicoptero::setCapacidade(unsigned capacidade){
    this->capacidade = capacidade;
}

void Helicoptero::setCapacidadeMax(unsigned capacidadeMax){
    this->capacidadeMax = capacidadeMax;
}

void Helicoptero::setTanque(double tanque){
    this->tanque = tanque;
}

void Helicoptero::setTanqueMax(double max){
    this->tanqueMax = max;
}

// GAMEBASE
void Helicoptero::update(){
    this->tanque -= 5;
    this->ObjetoDeJogo::update();
}