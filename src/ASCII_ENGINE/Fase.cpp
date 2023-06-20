#include "Fase.hpp"

void Fase::show(SpriteBase *screen){
    for (std::string  linha : screen->getSprite()){
        std::cout << linha << std::endl;
    }
}

void Fase::draw(SpriteBase &screen, unsigned x, unsigned y){
    background->draw(screen, 0, 0);

    for (auto it = listaObjetos.begin(); it != listaObjetos.end(); ++it){
        (*it)->draw(screen, (*it)->getColuna(), (*it)->getLinha());
    }
}

void Fase::setBackground(SpriteBase *bkg){
    this->background = bkg->copy();
}

void Fase::setListaObjetos(std::list<ObjetoDeJogo*> lista){
    this->listaObjetos = lista;
}