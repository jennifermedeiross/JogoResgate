#include "Helicoptero.hpp"

void Helicoptero::resgate(){
    if(this->getCapacidade() > 0)
        this->capacidade -= 1;
}

void Helicoptero::abastecer(){
    int limite = getTanque() + (getTanqueMax()/5);

    if(limite < getTanqueMax()){
        setTanque(limite);
    }
}

void Helicoptero::setCapacidade(unsigned capacidade){
    this->capacidade = capacidade;
}

void Helicoptero::setTanque(unsigned tanque){
    this->tanque = tanque;
}

void Helicoptero::setTanqueMax(unsigned max){
    this->tanqueMax = max;
}

// GAMEBASE
void Helicoptero::update(){
    this->tanque -= 2;
    this->ObjetoDeJogo::update();
}