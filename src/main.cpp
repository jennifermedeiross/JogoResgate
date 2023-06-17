#include "ASCII_ENGINE/SpriteBase.hpp"
#include "ASCII_ENGINE/Sprite.hpp"
#include "ASCII_ENGINE/ObjetoDeJogo.hpp"

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

    ObjetoDeJogo helicop("Helicoptero", Sprite("src/imgs/helicopteroSprite.txt"), 176, 2);

    screen.imprimir();

    return 0;
}

    // ObjetoDeJogo algo("Helicoptero", Sprite("src/imgs/helicopteroSprite.txt"), 2, 2);
    // helicop.draw(screen, helicop.getColuna(), helicop.getLinha());
    // std::cout << "Colisão: " << helicop.colideCom(algo) << std::endl;

    // std::cout << "COluna: " << helicop.getColuna() << std::endl;
    // std::cout << "Linha: " << helicop.getLinha() << std::endl;
    
    // helicop.moveRigth();
    // helicop.moveRigth();

    // std::cout << "\nCOluna: " << helicop.getColuna() << std::endl;
    // std::cout << "Linha: " << helicop.getLinha() << std::endl;