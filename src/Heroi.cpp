#include "Heroi.hpp"

void Heroi::resgate(){
    if(getCapacidade() <= getCapacidadeMax() && getCapacidade() > 0){
        this->capacidade -= 1;
    }
}

void Heroi::abastecer(){
    int limite = getTanque() + (getTanqueMax()/5);

    if(limite < getTanqueMax()){
        setTanque(limite);
    } else {
        setTanque(getTanqueMax());
    }
}

void Heroi::subtrairPeso(int peso){
    this->peso -= peso;
}

void Heroi::processoDeResgate(Pessoa &pessoa, int novaC, int novaL){
    resgate();
    subtrairPeso(pessoa.getPeso());
    pessoa.desativar();
    pessoa.setColuna(novaC);
    pessoa.setLinha(novaL);
    pessoa.resgatarPessoa();
}

void Heroi::setCapacidade(unsigned capacidade){
    this->capacidade = capacidade;
}

void Heroi::setCapacidadeMax(unsigned capacidadeMax){
    this->capacidadeMax = capacidadeMax;
}

void Heroi::setTanque(double tanque){
    this->tanque = tanque;
}

void Heroi::setTanqueMax(double max){
    this->tanqueMax = max;
}

void Heroi::setPeso(double peso){
    this->peso = peso;
}

void Heroi::setPesoMax(double max){
    this->pesoMax = max;
}


// GAMEBASE
void Heroi::update(){
    if(this->tanque > 0) this->tanque -= 3;
    this->ObjetoDeJogo::update();
}