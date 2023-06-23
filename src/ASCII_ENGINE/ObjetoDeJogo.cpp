#include "ObjetoDeJogo.hpp"

ObjetoDeJogo::ObjetoDeJogo(const ObjetoDeJogo &obj){
    this->spriteObj = obj.spriteObj->copy();
    this->coluna = obj.getColuna();
    this->linha = obj.getLinha();
    this->ativo = true;
}

bool ObjetoDeJogo::colideCom(ObjetoDeJogo &obj) const{
    int colunaObjetoAtual = this->getColuna();
    int linhaObjetoAtual = this->getLinha();
    int larguraObjetoAtual = this->spriteObj->getLargura();
    int alturaObjetoAtual = this->spriteObj->getAltura();

    int colunaOutroObjeto = obj.getColuna();
    int linhaOutroObjeto = obj.getLinha();
    int larguraOutroObjeto = obj.getSpriteObj()->getAltura();
    int alturaOutroObjeto = obj.getSpriteObj()->getLargura();
    
    if(colunaObjetoAtual < colunaOutroObjeto + larguraOutroObjeto &&
        colunaOutroObjeto < colunaObjetoAtual + larguraObjetoAtual &&
        linhaObjetoAtual < linhaOutroObjeto + alturaOutroObjeto &&
        linhaOutroObjeto < linhaObjetoAtual + alturaObjetoAtual ){ 
            return true;
    }
    else { return false; }
    
}

void ObjetoDeJogo::moveTo(unsigned linha, unsigned coluna){
    setLinha(linha);
    setColuna(coluna);
}

void ObjetoDeJogo::moveLeft(){
    if((this->coluna - 2) >= 1){
        moveTo(this->linha, this->coluna -= 2);
    }
}

void ObjetoDeJogo::moveRigth(){
    int largura = getSpriteObj()->getSprite()[0].size();

    if((this->coluna + 2 + largura) <= (GameBase::LARGURA_TELA() - 1)){
        moveTo(this->linha, this->coluna += 2);
    }
}

void ObjetoDeJogo::moveDown(){
    int altura = getSpriteObj()->getSprite().size();

    if((this->linha + 2 + altura) <= (GameBase::ALTURA_TELA() - 1)){
        moveTo(this->linha += 2, this->coluna);
    }
}

void ObjetoDeJogo::moveUp(){
    if((this->linha - 2) >= 4){
        moveTo(this->linha -= 2, this->coluna);
    }
}

void ObjetoDeJogo::setSpriteObj(SpriteBase &sprite){
    this->spriteObj = &sprite;
}

void ObjetoDeJogo::setLinha(unsigned linha){
    this->linha = linha;
}

void ObjetoDeJogo::setColuna(unsigned coluna){
    this->coluna = coluna;
}

void ObjetoDeJogo::ativar(){
    this->ativo = true;
    update();
}

void ObjetoDeJogo::desativar(){
    this->ativo = false;
    update();
}

// GAMEBASE

void ObjetoDeJogo::draw(SpriteBase &base, unsigned x, unsigned y){
    if(this->ativo){
        spriteObj->draw(base, x, y);
    }
}

void ObjetoDeJogo::update(){
    this->getSpriteObj()->update();
}
