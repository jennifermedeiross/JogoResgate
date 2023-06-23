#include "Sprite.hpp"

SpriteBase *Sprite::copy(){
    return new Sprite(*this);
}


void Sprite::draw(SpriteBase &base, unsigned colunaDesejada, unsigned linhaDesejada){
    const std::vector<std::string> desenhoOrigem = this->getSprite();
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
