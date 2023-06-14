#include "Sprite.hpp"

void Sprite::draw(SpriteBase &base, unsigned colunaDesejada, unsigned linhaDesejada){
    const std::vector<std::string> desenhoOrigem = this->getSprite();
    std::vector<std::string> desenhoDestino = base.getSprite();

    int alturaOrigem = desenhoOrigem.size();
    int alturaDestino = desenhoDestino.size();

    for (int i = 0; i < alturaOrigem; i++) {

        int larguraOrigem = desenhoOrigem[i].size();
        int larguraDestino = desenhoDestino[i].size();

        for (int j = 0; j < larguraOrigem; j++) {
            unsigned coluna = colunaDesejada + j;
            unsigned linha = linhaDesejada + i;

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
