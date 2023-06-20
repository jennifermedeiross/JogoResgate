#include "FaseGame.hpp"

void FaseGame::run(){
    Sprite screen("src/imgs/screen.txt");
    Sound somGame("src/musics/game.mp3");
    Sound abasteceu("src/musics/abasteceu.mp3");
    Sound resgatou("src/musics/salvou.mp3");
    Sound colocouBase("src/musics/base.mp3");

    init();
    somGame.playloop();

    while (true) {
        
        system("clear");
        std::cout << "TANQUE: " << pHelicoptero->getTanque() << 
        "         CAPACIDADE: " << pHelicoptero->getCapacidade()<< 
        "         CAPACIDADE MÁXIMA: " << pHelicoptero->getCapacidadeMax() <<std::endl;
        draw(screen, 0 ,0);
        show(&screen);
        char entrada = teclado.getch();


        if(entrada == 'w' || entrada == 'W'){ 
            pHelicoptero->moveUp();
            update();
        }

        else if(entrada == 's' || entrada == 'S'){ 
            pHelicoptero->moveDown();
            update();
        }

        else if(entrada == 'd' || entrada == 'D'){ 
            pHelicoptero->moveRigth();
            update();
        }

        if(entrada == 'a' || entrada == 'A'){ 
            pHelicoptero->moveLeft();
            update();
        }

        if(entrada == 'x' || entrada == 'X'){ 

            //COMBUSTIVEL
            if(pHelicoptero->colideCom(*pCombustivel)){
                pHelicoptero->abastecer();
                abasteceu.play();
            }

            //PESSOA 1
            else if(pHelicoptero->colideCom(*pPessoa1)){
                if(pHelicoptero->getCapacidade() > 0 && !(pPessoa1->getResgatada())){
                    pHelicoptero->resgate();
                    pPessoa1->desativar();
                    pPessoa1->setColuna(131);
                    pPessoa1->setLinha(35);
                    pPessoa1->resgatarPessoa();
                    resgatou.play();
                }
            }
            //PESSOA 2
            else if(pHelicoptero->colideCom(*pPessoa2) && !(pPessoa2->getResgatada())){
                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->resgate();
                    pPessoa2->desativar();
                    pPessoa2->setColuna(131);
                    pPessoa2->setLinha(35);
                    pPessoa2->resgatarPessoa();
                    resgatou.play();
                }
            }
            //PESSOA 3
            else if(pHelicoptero->colideCom(*pPessoa3) && !(pPessoa3->getResgatada())){
                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->resgate();
                    pPessoa3->desativar();
                    pPessoa3->setColuna(137);
                    pPessoa3->setLinha(35);
                    pPessoa3->resgatarPessoa();
                    resgatou.play();
                }
            }
            // PESSOA 4
            else if(pHelicoptero->colideCom(*pPessoa4) && !(pPessoa4->getResgatada())){
                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->resgate();
                    pPessoa4->desativar();
                    pPessoa4->setColuna(143);
                    pPessoa4->setLinha(35);
                    pPessoa4->resgatarPessoa();
                    resgatou.play();
                }
            }
            //PESSOA 5
            else if(pHelicoptero->colideCom(*pPessoa5) && !(pPessoa5->getResgatada())){
                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->resgate();
                    pPessoa5->desativar();
                    pPessoa5->setColuna(149);
                    pPessoa5->setLinha(35);
                    pPessoa5->resgatarPessoa();
                    resgatou.play();
                }
            }
            //PESSOA 6
            else if(pHelicoptero->colideCom(*pPessoa6) && !(pPessoa6->getResgatada())){
                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->resgate();
                    pPessoa6->desativar();
                    pPessoa6->setColuna(156);
                    pPessoa6->setLinha(35);
                    pPessoa6->resgatarPessoa();
                    resgatou.play();
                }
            }

            //BASE
            else if(pHelicoptero->colideCom(*pBase)){
                pHelicoptero->setCapacidade(pHelicoptero->getCapacidadeMax());

                if (pPessoa1->getAtivo() == false) pPessoa1->ativar();
                if (pPessoa2->getAtivo() == false) pPessoa2->ativar();
                if (pPessoa3->getAtivo() == false) pPessoa3->ativar();
                if (pPessoa4->getAtivo() == false) pPessoa4->ativar();
                if (pPessoa5->getAtivo() == false) pPessoa5->ativar();
                if (pPessoa6->getAtivo() == false) pPessoa6->ativar();
                
                colocouBase.play();
            }
        }

        else if(entrada == 'q' || entrada == 'Q'){ 
            break;
        }

        else if (entrada == '\n'){
            update();
        }   

    }
}

void FaseGame::init(){

    Sprite informativo("src/imgs/informativos.txt");
    Sprite screen("src/imgs/screen.txt");
    Sprite arvore("src/imgs/arvore.txt");
    Sprite nuvens1("src/imgs/nuvens1.txt");
    Sprite nuvens2("src/imgs/nuvens2.txt");
    Sprite plataformas("src/imgs/plataformas.txt");
    Sprite cacto("src/imgs/cacto.txt");
    Sprite pessoa("src/imgs/pessoa.txt");

    informativo.draw(screen, 0, 0);
    plataformas.draw(screen, 1, 13);
    arvore.draw(screen, 1, 22);
    nuvens1.draw(screen, 115, 6);
    nuvens2.draw(screen, 78, 36);
    cacto.draw(screen, 25, 6);
    cacto.draw(screen, 150, 20);

    this->setBackground(&screen);

    pPessoa1 = new Pessoa(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 70, 7), 70.00);
    pPessoa2 = new Pessoa(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 50, 7), 60.00);
    pPessoa3 = new Pessoa(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 110, 21), 60.00);
    pPessoa4 = new Pessoa(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 130, 21), 80.00);
    pPessoa5 = new Pessoa(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 80, 21), 90.00);
    pPessoa6 = new Pessoa(ObjetoDeJogo(Sprite("src/imgs/pessoa.txt"), 60, 39), 50.00);
    pHelicoptero = new Helicoptero(ObjetoDeJogo(Sprite("src/imgs/helicopteroGame.txt"), 0, 4));
    pCombustivel = new Combustivel(ObjetoDeJogo(Sprite("src/imgs/combustivel.txt"), 35, 29));
    pBase = new Base(ObjetoDeJogo(Sprite("src/imgs/base.txt"), 130, 42));

    std::list<ObjetoDeJogo*> lista;
    lista.push_back(pPessoa1);
    lista.push_back(pPessoa2);
    lista.push_back(pPessoa3);
    lista.push_back(pPessoa4);
    lista.push_back(pPessoa5);
    lista.push_back(pPessoa6);
    lista.push_back(pBase);
    lista.push_back(pCombustivel);
    lista.push_back(pHelicoptero);

    this->setListaObjetos(lista);
}

void FaseGame::informa(){
    std::cout << "TAQUE: " << pHelicoptero->getTanque();
}
