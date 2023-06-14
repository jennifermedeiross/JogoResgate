#include "Sprite.hpp"

void Sprite::draw(SpriteBase &base, int xDesejado, int yDesejado){
    const std::vector<std::string> desenhoOrigem = this->getSprite();
    std::vector<std::string> desenhoDestino = base.getSprite();

    int alturaOrigem = desenhoOrigem.size();
    int alturaDestino = desenhoDestino.size();

    for (int i = 0; i < alturaOrigem; i++) {

        int larguraOrigem = desenhoOrigem[i].size();
        int larguraDestino = desenhoDestino[i].size();

        for (int j = 0; j < larguraOrigem; j++) {
            int posX = xDesejado + j;
            int posY = yDesejado + i;

            if (posX >= 0 && posX < larguraDestino &&
                posX >= 0 && posY < alturaDestino) {
                char pixel = desenhoOrigem[i][j];
                if (pixel != 'x')
                {
                    desenhoDestino[posY][posX] = pixel;
                }
            }
        }
    }

    base.setSprite(desenhoDestino);
}
