#include "FaseGame.hpp"

void FaseGame::init(){

    Sprite screen("src/imgs/screen.txt");
    Sprite arvore("src/imgs/arvore.txt");
    Sprite nuvens1("src/imgs/nuvens1.txt");
    Sprite nuvens2("src/imgs/nuvens2.txt");
    Sprite plataformas("src/imgs/plataformas.txt");
    Sprite cacto("src/imgs/cacto.txt");
    Sprite pessoa("src/imgs/pessoa.txt");

    plataformas.draw(screen, 1, 13);
    arvore.draw(screen, 1, 22);
    nuvens1.draw(screen, 115, 6);
    nuvens2.draw(screen, 78, 36);
    cacto.draw(screen, 25, 6);
    cacto.draw(screen, 150, 20);

    this->setBackground(&screen);

    Combustivel combustivel(ObjetoDeJogo(Sprite("src/imgs/combustivel.txt"), 35, 29));
    Base base(ObjetoDeJogo(Sprite("src/imgs/base.txt"), 130, 42));
    Pessoa pessoa1(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 70, 7), 70.00);
    Pessoa pessoa2(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 50, 7), 60.00);
    Pessoa pessoa3(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 110, 21), 60.00);
    Pessoa pessoa4(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 130, 21), 80.00);
    Pessoa pessoa5(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 80, 21), 90.00);
    Pessoa pessoa6(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 60, 39), 50.00);
    Helicoptero helicoptero(ObjetoDeJogo(Sprite("src/imgs/helicopteroGame.txt"), 0, 4));

    std::list<ObjetoDeJogo*> lista;
    lista.push_back(new ObjetoDeJogo(combustivel));
    lista.push_back(new ObjetoDeJogo(base));
    lista.push_back(new ObjetoDeJogo(pessoa1));
    lista.push_back(new ObjetoDeJogo(pessoa2));
    lista.push_back(new ObjetoDeJogo(pessoa3));
    lista.push_back(new ObjetoDeJogo(pessoa4));
    lista.push_back(new ObjetoDeJogo(pessoa5));
    lista.push_back(new ObjetoDeJogo(pessoa6));
    lista.push_back(new ObjetoDeJogo(helicoptero));

    this->setListaObjetos(lista);
}
