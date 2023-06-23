#include "SpriteAnimado.hpp"

void SpriteAnimado::lerMedidas(){
    std::istringstream linha(this->getSprite()[0]);
    int quantidade, altura;

    linha >> quantidade >> altura;

    this->quantidadeSprites = quantidade;
    this->alturaSprites = altura;

}

void SpriteAnimado::imprimirSpriteAnimado(){
    for (std::string  linha : this->getSpriteAtual()){
        std::cout << linha << std::endl;
    }
}

void SpriteAnimado::dividirSprites(){
    int linha = 1;
    Sprite subsprite;
    int altura = this->alturaSprites; 
    std::vector<std::string> vectorSubSprite;

    for (int i = 0; i < this->quantidadeSprites; i++){
        vectorSubSprite.clear();

        for(int j = linha; j < altura+linha; j++){
            vectorSubSprite.push_back(getSprite()[j]);
        } 
        
        subsprite.setSprite(vectorSubSprite);

        this->sprites.push_back(subsprite);
        linha+=(altura+1);
    }
}

void SpriteAnimado::draw(SpriteBase &base, unsigned colunaDesejada, unsigned linhaDesejada){
    const std::vector<std::string> desenhoOrigem = this->getSpriteAtual();
    std::vector<std::string> desenhoDestino = base.getSprite();

    int alturaOrigem = getAltura();
    int alturaDestino = base.getAltura();

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
    this->spriteAtual++;

    if(this->spriteAtual >= this->quantidadeSprites)
        this->spriteAtual = 0;
}

