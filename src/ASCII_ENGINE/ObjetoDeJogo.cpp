#include "ObjetoDeJogo.hpp"

bool ObjetoDeJogo::colideCom(ObjetoDeJogo &obj) const{
    int colunaObjetoAtual = this->getColuna();
    int linhaObjetoAtual = this->getLinha();
    int larguraObjetoAtual = this->spriteObj.getSprite()[0].size();
    int alturaObjetoAtual = this->spriteObj.getSprite().size();

    int colunaOutroObjeto = obj.getColuna();
    int linhaOutroObjeto = obj.getLinha();
    int larguraOutroObjeto = obj.getSpriteObj().getSprite()[0].size();
    int alturaOutroObjeto = obj.getSpriteObj().getSprite().size();
    
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
    int largura = this->spriteObj.getSprite()[0].size();

    if((this->coluna + 2 + largura) <= (GameBase::LARGURA_TELA() - 1)){
        moveTo(this->linha, this->coluna += 2);
    }
}

void ObjetoDeJogo::moveDown(){
    int altura = this->spriteObj.getSprite().size();

    if((this->linha + 2 + altura) <= (GameBase::ALTURA_TELA() - 1)){
        moveTo(this->linha += 2, this->coluna);
    }
}

void ObjetoDeJogo::moveUp(){
    if((this->linha - 2) >= 4){
        moveTo(this->linha -= 2, this->coluna);
    }
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
