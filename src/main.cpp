#include "./SpriteBase.hpp"
#include "./Sprite.hpp"

int main() {
    Sprite screen("src/imgs/screen.txt");
    Sprite arvore("src/imgs/arvore.txt");
    Sprite nuvem("src/imgs/nuvem.txt");
    Sprite plataformas("src/imgs/plataformas.txt");
    Sprite cacto("src/imgs/cacto.txt");

    plataformas.draw(screen, 1, 13); // coluna x linha
    arvore.draw(screen, 2, 22);
    nuvem.draw(screen, 130, 6);
    nuvem.draw(screen, 140, 8);
    nuvem.draw(screen, 115, 9);
    nuvem.draw(screen, 78, 36);
    nuvem.draw(screen, 88, 39);
    cacto.draw(screen, 25, 6);
    cacto.draw(screen, 150, 20);
    screen.imprimir();

    return 0;
}
