#include "FaseGame.hpp"

void FaseGame::run(){
    Sprite screen("src/imgs/screen.txt");
    Sprite gameOver("src/imgs/gameOver.txt");
    Sprite gameWin("src/imgs/gameWin.txt");
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
        informativo(pHelicoptero->getTanque(), pHelicoptero->getTanqueMax(),
                pHelicoptero->getCapacidade(), pHelicoptero->getCapacidadeMax(),
                pHelicoptero->getPeso(), pHelicoptero->getPesoMax());

        draw(screen, 0 ,0);
        show(&screen);
        char entrada = getTeclado().getch();

        if(pHelicoptero->getTanque() == 0){
            system("clear");
            informativo(pHelicoptero->getTanque(), pHelicoptero->getTanqueMax(),
                pHelicoptero->getCapacidade(), pHelicoptero->getCapacidadeMax(),
                pHelicoptero->getPeso(), pHelicoptero->getPesoMax());
            gameOver.draw(screen, 35 , 15);
            show(&screen);
            somGame.pause();
            somGameOver.play();
            sleep(5);
            break;
        }

        if (qntResgatado == 6){
            system("clear");
            informativo(pHelicoptero->getTanque(), pHelicoptero->getTanqueMax(),
                pHelicoptero->getCapacidade(), pHelicoptero->getCapacidadeMax(),
                pHelicoptero->getPeso(), pHelicoptero->getPesoMax());
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

        else if (entrada == '\n'){
            update();
        }   


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
            update();

            //COMBUSTIVEL
            if(pHelicoptero->colideCom(*pCombustivel)){
                pHelicoptero->abastecer();
                abasteceu.play();
            }

            //PESSOA 1
            else if(pHelicoptero->colideCom(*pPessoa1) && 
                !(pPessoa1->getResgatada()) &&
                pHelicoptero->getPeso() > pPessoa1->getPeso()){

                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->processoDeResgate(*pPessoa1, 131, 35);
                    resgatou.play();
                }
            }
            
            //PESSOA 2
            else if(pHelicoptero->colideCom(*pPessoa2) && 
                !(pPessoa2->getResgatada()) &&
                pHelicoptero->getPeso() > pPessoa2->getPeso()){

                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->processoDeResgate(*pPessoa2, 137, 35);
                    resgatou.play();
                }
            }

            //PESSOA 3
            else if(pHelicoptero->colideCom(*pPessoa3) && 
                !(pPessoa3->getResgatada()) &&
                pHelicoptero->getPeso() > pPessoa3->getPeso()){

                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->processoDeResgate(*pPessoa3, 143, 35);
                    resgatou.play();
                }
            }

            // PESSOA 4
            else if(pHelicoptero->colideCom(*pPessoa4) && 
                !(pPessoa4->getResgatada()) &&
                pHelicoptero->getPeso() > pPessoa4->getPeso()){

                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->processoDeResgate(*pPessoa4, 149, 35);
                    resgatou.play();
                }
            }

            //PESSOA 5
            else if(pHelicoptero->colideCom(*pPessoa5) && 
                !(pPessoa5->getResgatada()) &&
                pHelicoptero->getPeso() > pPessoa5->getPeso()){

                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->processoDeResgate(*pPessoa5, 155, 35);
                    resgatou.play();
                }
            }

            //PESSOA 6
            else if(pHelicoptero->colideCom(*pPessoa6) && 
                !(pPessoa6->getResgatada()) &&
                pHelicoptero->getPeso() > pPessoa6->getPeso()){

                if(pHelicoptero->getCapacidade() > 0){
                    pHelicoptero->processoDeResgate(*pPessoa6, 161, 35);
                    resgatou.play();
                }
            }

            //BASE
            else if(pHelicoptero->colideCom(*pBase)){
                pHelicoptero->setCapacidade(pHelicoptero->getCapacidadeMax());
                pHelicoptero->setPeso(pHelicoptero->getPesoMax());

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
    Sprite pessoa("src/imgs/pessoa.txt");

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

void FaseGame::informativo(int tanque, int tanqueMax, int capacidade, int capacidadeMax, int peso, int pesoMax){

    std::string tanqueStr = "FUEL: " + std::to_string(tanque) + "/" + std::to_string(tanqueMax);
    std::string capacidadeStr = "CAPACITY: " + std::to_string(capacidade) + "/" + std::to_string(capacidadeMax);
    std::string pesoStr = "WEIGHT: " + std::to_string(peso) + "/" + std::to_string(pesoMax);

    int totalWidth = (180 / 3) - 3;

    std::cout << "| " << std::setw(totalWidth) << std::left << tanqueStr
                << "| " << std::setw(totalWidth) << std::left << capacidadeStr
                << "| " << std::setw(totalWidth) << std::left << pesoStr << " |" << std::endl;
}

