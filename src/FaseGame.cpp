#include "FaseGame.hpp"

void FaseGame::run(){
    Sprite screen("src/imgs/screen.txt");
    Sprite gameOver("src/imgs/gameOver.txt");
    Sprite gameWin("src/imgs/gameWin.txt");
    Sprite pause("src/imgs/pause.txt");
    Sound somGame("src/musics/game.mp3");
    Sound somGameOver("src/musics/gameover.mp3");
    Sound somVitoria("src/musics/vitoria.mp3");
    Sound abasteceu("src/musics/abasteceu.mp3");
    Sound resgatou("src/musics/salvou.mp3");
    Sound colocouBase("src/musics/base.mp3");

    init();
    somGame.playloop();

    int qntResgatado = 0;

    while (true) {
        
        system("clear");
        informativo(pHeroi->getTanque(), pHeroi->getTanqueMax(),
                pHeroi->getCapacidade(), pHeroi->getCapacidadeMax(),
                pHeroi->getPeso(), pHeroi->getPesoMax());

        draw(screen, 0 ,0);
        show(&screen);
        char entrada = getTeclado().getch();

        if(pHeroi->getTanque() == 0){
            system("clear");
            setState("FaseMenu");
            informativo(pHeroi->getTanque(), pHeroi->getTanqueMax(),
                pHeroi->getCapacidade(), pHeroi->getCapacidadeMax(),
                pHeroi->getPeso(), pHeroi->getPesoMax());
            gameOver.draw(screen, 35 , 15);
            show(&screen);
            somGame.pause();
            somGameOver.play();
            sleep(5);
            break;
        }

        if (qntResgatado == 6){
            system("clear");
            setState("FaseMenu");
            informativo(pHeroi->getTanque(), pHeroi->getTanqueMax(),
                pHeroi->getCapacidade(), pHeroi->getCapacidadeMax(),
                pHeroi->getPeso(), pHeroi->getPesoMax());
            gameWin.draw(screen, 35 , 15);
            show(&screen);
            somGame.pause();
            somVitoria.play();
            sleep(10);
            break;
        }

        else if(entrada == 'q' || entrada == 'Q'){ 
            this->setState("FaseMenu");
            break;
        }

        else if(entrada == 'p' || entrada == 'P'){
            resgatou.play();
            system("clear");
            informativo(pHeroi->getTanque(), pHeroi->getTanqueMax(),
                pHeroi->getCapacidade(), pHeroi->getCapacidadeMax(),
                pHeroi->getPeso(), pHeroi->getPesoMax());
            pause.draw(screen, 57, 18);
            somGame.pause();
            show(&screen);
            std::cin.ignore();
            somGame.unpause();
        }

        else if (entrada == '\n'){
            update();
        }   


        if(entrada == 'w' || entrada == 'W'){ 
            pHeroi->moveUp();
            update();
        }

        else if(entrada == 's' || entrada == 'S'){ 
            pHeroi->moveDown();
            update();
        }

        else if(entrada == 'd' || entrada == 'D'){ 
            pHeroi->moveRigth();
            update();
        }

        if(entrada == 'a' || entrada == 'A'){ 
            pHeroi->moveLeft();
            update();
        }

        if(entrada == 'x' || entrada == 'X'){
            update();

            //COMBUSTIVEL
            if(pHeroi->colideCom(*pCombustivel)){
                pHeroi->abastecer();
                abasteceu.play();
            }

            //PESSOA 1
            else if(pHeroi->colideCom(*pPessoa1) && 
                !(pPessoa1->getResgatada()) &&
                pHeroi->getPeso() > pPessoa1->getPeso()){

                if(pHeroi->getCapacidade() > 0){
                    pHeroi->processoDeResgate(*pPessoa1, 131, 35);
                    resgatou.play();
                }
            }
            
            //PESSOA 2
            else if(pHeroi->colideCom(*pPessoa2) && 
                !(pPessoa2->getResgatada()) &&
                pHeroi->getPeso() > pPessoa2->getPeso()){

                if(pHeroi->getCapacidade() > 0){
                    pHeroi->processoDeResgate(*pPessoa2, 137, 35);
                    resgatou.play();
                }
            }

            //PESSOA 3
            else if(pHeroi->colideCom(*pPessoa3) && 
                !(pPessoa3->getResgatada()) &&
                pHeroi->getPeso() > pPessoa3->getPeso()){

                if(pHeroi->getCapacidade() > 0){
                    pHeroi->processoDeResgate(*pPessoa3, 143, 35);
                    resgatou.play();
                }
            }

            // PESSOA 4
            else if(pHeroi->colideCom(*pPessoa4) && 
                !(pPessoa4->getResgatada()) &&
                pHeroi->getPeso() > pPessoa4->getPeso()){

                if(pHeroi->getCapacidade() > 0){
                    pHeroi->processoDeResgate(*pPessoa4, 149, 35);
                    resgatou.play();
                }
            }

            //PESSOA 5
            else if(pHeroi->colideCom(*pPessoa5) && 
                !(pPessoa5->getResgatada()) &&
                pHeroi->getPeso() > pPessoa5->getPeso()){

                if(pHeroi->getCapacidade() > 0){
                    pHeroi->processoDeResgate(*pPessoa5, 155, 35);
                    resgatou.play();
                }
            }

            //PESSOA 6
            else if(pHeroi->colideCom(*pPessoa6) && 
                !(pPessoa6->getResgatada()) &&
                pHeroi->getPeso() > pPessoa6->getPeso()){

                if(pHeroi->getCapacidade() > 0){
                    pHeroi->processoDeResgate(*pPessoa6, 161, 35);
                    resgatou.play();
                }
            }

            //BASE
            else if(pHeroi->colideCom(*pBase)){
                pHeroi->setCapacidade(pHeroi->getCapacidadeMax());
                pHeroi->setPeso(pHeroi->getPesoMax());

                if (pPessoa1->getAtivo() == false) {
                    pPessoa1->ativar();
                    qntResgatado ++;
                }

                if (pPessoa2->getAtivo() == false) {
                    pPessoa2->ativar();
                    qntResgatado ++;
                }

                if (pPessoa3->getAtivo() == false) {
                    pPessoa3->ativar();
                    qntResgatado ++;
                }

                if (pPessoa4->getAtivo() == false) {
                    pPessoa4->ativar();
                    qntResgatado ++;
                }

                if (pPessoa5->getAtivo() == false) {
                    pPessoa5->ativar();
                    qntResgatado ++;
                }

                if (pPessoa6->getAtivo() == false) {
                    pPessoa6->ativar();
                    qntResgatado ++;
                }
                
                colocouBase.play();
            }
        }
        

    }
}

void FaseGame::init(){

    Sprite screen("src/imgs/screen.txt");
    Sprite informacoes("src/imgs/informacoes.txt");
    Sprite arvore("src/imgs/arvore.txt");
    Sprite nuvens1("src/imgs/nuvens1.txt");
    Sprite nuvens2("src/imgs/nuvens2.txt");
    Sprite plataformas("src/imgs/plataformas.txt");
    Sprite cacto("src/imgs/cacto.txt");
    SpriteAnimado pessoa("src/imgs/Animado_pessoa.txt");

    informacoes.draw(screen, 143, 0);
    plataformas.draw(screen, 1, 13);
    arvore.draw(screen, 1, 22);
    nuvens1.draw(screen, 115, 6);
    nuvens2.draw(screen, 78, 36);
    cacto.draw(screen, 25, 6);
    cacto.draw(screen, 150, 20);

    this->setBackground(&screen);

    pPessoa1 = new Pessoa(ObjetoDeJogo(pessoa, 70, 7), 70.00);
    pPessoa2 = new Pessoa(ObjetoDeJogo(pessoa, 50, 7), 60.00);
    pPessoa3 = new Pessoa(ObjetoDeJogo(pessoa, 110, 21), 60.00);
    pPessoa4 = new Pessoa(ObjetoDeJogo(pessoa, 130, 21), 80.00);
    pPessoa5 = new Pessoa(ObjetoDeJogo(pessoa, 80, 21), 90.00);
    pPessoa6 = new Pessoa(ObjetoDeJogo(pessoa, 60, 39), 50.00);
    pHeroi = new Heroi(ObjetoDeJogo(SpriteAnimado("src/imgs/Animado_helicopteroGame.txt"), 0, 4));
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
    lista.push_back(pHeroi);

    this->setListaObjetos(lista);
}

void FaseGame::informativo(int tanque, int tanqueMax, int capacidade, int capacidadeMax, int peso, int pesoMax){

    std::string tanqueStr = "FUEL: " + std::to_string(tanque) + "/" + std::to_string(tanqueMax);
    std::string capacidadeStr = "CAPACITY: " + std::to_string(capacidade) + "/" + std::to_string(capacidadeMax);
    std::string pesoStr = "WEIGHT: " + std::to_string(peso) + "/" + std::to_string(pesoMax);

    int totalWidth = (180 / 3) - 3;

    std::cout << "| " << std::setw(totalWidth) << std::left << tanqueStr
                << "| " << std::setw(totalWidth) << std::left << capacidadeStr
                << "| " << std::setw(totalWidth) << std::left << pesoStr << " |" << std::endl;
}

