#include "SpriteAnimado.hpp"

void SpriteAnimado::lerMedidas(){
    std::istringstream linha(this->getSprite()[0]);
    int quantidade, altura;

    linha >> quantidade >> altura;

    this->quantidadeSprites = quantidade;
    this->alturaSprites = altura;
}

void SpriteAnimado::dividirSprites(){
    for (int i = 0; i < this->quantidadeSprites; i++){
        int altura = this->alturaSprites;
        int linha = 2;
        Sprite subsprite;

        for(int j = linha; j < altura+linha; j++){
            std::vector<std::string> vectorSubSprite;
            
            vectorSubSprite.push_back(getSprite()[j]);

            subsprite.setSprite(vectorSubSprite);
        }

        this->sprites.push_back(subsprite);
        linha+=(altura+1);
    }
}

void SpriteAnimado::draw(SpriteBase &base, unsigned colunaDesejada, unsigned linhaDesejada){
    const std::vector<std::string> desenhoOrigem = this->getSpriteAtual().getSprite();
    std::vector<std::string> desenhoDestino = base.getSprite();

    int alturaOrigem = desenhoOrigem.size();
    int alturaDestino = desenhoDestino.size();

    for (int i = 0; i < alturaOrigem; i++) {

        int larguraOrigem = desenhoOrigem[i].size();
        int larguraDestino = desenhoDestino[i].size();

        for (int j = 0; j < larguraOrigem; j++) {
            int coluna = colunaDesejada + j;
            int linha = linhaDesejada + i;

            if (coluna < larguraDestino &&
                linha < alturaDestino) {
                char pixel = desenhoOrigem[i][j];
                if (pixel != 'x')
                {
                    desenhoDestino[linha][coluna] = pixel;
                }
            }
        }
    }

    base.setSprite(desenhoDestino);
}

void SpriteAnimado::update(){
    lerMedidas();
    dividirSprites();
    this->spriteAtual++;

    if(this->spriteAtual >= this->quantidadeSprites)
        this->spriteAtual = 0;
}

