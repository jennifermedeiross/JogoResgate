#include "ObjetoDeJogo.hpp"


bool ObjetoDeJogo::colideCom(ObjetoDeJogo &obj) const{
    int colunaThis = this->getColuna();
    int linhaThis = this->getLinha();
    int larguraThis = this->spriteObj.getSprite()[0].size();
    int alturaThis = this->spriteObj.getSprite().size();

    int colunaOutro = obj.getColuna();
    int linhaOutro = obj.getLinha();
    int larguraOutro = obj.getSpriteObj().getSprite()[0].size();
    int alturaOutro = obj.getSpriteObj().getSprite().size();
    
    if(colunaThis < colunaOutro + larguraOutro &&
        colunaOutro < colunaThis + larguraThis &&
        linhaThis < linhaOutro + alturaOutro &&
        linhaOutro < linhaThis + alturaThis){ 
            return true;
    }
    else { return false; }
    
}

void ObjetoDeJogo::moveTo(unsigned linha, unsigned coluna){
    setLinha(linha);
    setColuna(coluna);
}

void ObjetoDeJogo::setNome(std::string nome){
    this->nome = nome;
}

void ObjetoDeJogo::setSpriteObj(SpriteBase &sprite){
    this->spriteObj = sprite;
}

void ObjetoDeJogo::setLinha(unsigned linha){
    this->linha = linha;
}

void ObjetoDeJogo::setColuna(unsigned coluna){
    this->coluna = coluna;
}

void ObjetoDeJogo::ativar(){
    this->ativo = true;
}

void ObjetoDeJogo::desativar(){
    this->ativo = false;
}
