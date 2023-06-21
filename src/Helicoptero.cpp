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

void Helicoptero::subtrairPeso(int peso){
    this->peso -= peso;
}

void Helicoptero::processoDeResgate(Pessoa &pessoa, int novaC, int novaL){
    resgate();
    subtrairPeso(pessoa.getPeso());
    pessoa.desativar();
    pessoa.setColuna(novaC);
    pessoa.setLinha(novaL);
    pessoa.resgatarPessoa();
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

void Helicoptero::setPeso(double peso){
    this->peso = peso;
}

void Helicoptero::setPesoMax(double max){
    this->pesoMax = max;
}


// GAMEBASE
void Helicoptero::update(){
    if(this->tanque > 0) this->tanque -= 5;
    this->ObjetoDeJogo::update();
}