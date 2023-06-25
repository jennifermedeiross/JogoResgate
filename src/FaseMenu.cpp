#include "FaseMenu.hpp"

void FaseMenu::run(){
    Sprite screen("src/imgs/screen.txt");
    Sprite mHelp("src/imgs/mensagemHelp.txt");
    Sprite mAbout("src/imgs/mensagemAbout.txt");
    Sound somMenu("src/musics/menu.mp3");
    Sound selecionou("src/musics/salvou.mp3");

    init();
    somMenu.playloop();

    while (true) {
        
        system("clear");
        draw(screen, 0 ,0);
        show(&screen);
        char entrada = getTeclado().getch();


        if( entrada == 'q' || entrada == 'Q'){
            setState("end");
            somMenu.stop();
            exit(0);
        }

        else if( entrada == 'd' || entrada == 'D'){
            if((pSelector->getColuna()+pSelector->getSpriteObj()->getLargura())  < (pExit->getColuna() - 2)){
                moveRigth(*pSelector);
            }
        }

        else if( entrada == 'a' || entrada == 'A'){
            if(pSelector->getColuna() > pStart->getColuna()){
                moveLeft(*pSelector);
            }
        }

        else if (entrada == 'x' || entrada == 'X'){

            if(pSelector->colideCom(*pStart)){
                selecionou.play();
                setState("FaseGame");
                break;
            }

            else if(pSelector->colideCom(*pHelp)){
                selecionou.play();
                system("clear");
                mHelp.draw(screen, 43, 12);
                show(&screen);
                std::cin.ignore();
            }

            else if(pSelector->colideCom(*pAbout)){
                selecionou.play();

                mAbout.draw(screen, 43, 16);

                system("clear");
                show(&screen);
                std::cin.ignore();
            }

            else if(pSelector->colideCom(*pExit)){
                setState("end");
                break;
            }
        }


    }
}


void FaseMenu::init(){
    Sprite screen("src/imgs/screen.txt");
    Sprite gameName("src/imgs/gameName.txt");
    Sprite start("src/imgs/Menustart.txt");
    Sprite help("src/imgs/Menuhelp.txt");
    Sprite about("src/imgs/Menuabout.txt");
    Sprite exit("src/imgs/Menuexit.txt");
    Sprite selector("src/imgs/selector.txt");

    gameName.draw(screen, 58, 15);

    this->setBackground(&screen);

    std::list<ObjetoDeJogo *> lista;

    pStart = new ObjetoDeJogo(start, 23, 32);
    pHelp = new ObjetoDeJogo(help, 63, 32);
    pAbout = new ObjetoDeJogo(about, 103, 32);
    pExit = new ObjetoDeJogo(exit, 143, 32);
    pSelector = new ObjetoDeJogo(selector, 14, 33);

    lista.push_back(pStart);
    lista.push_back(pHelp);
    lista.push_back(pAbout);
    lista.push_back(pExit);
    lista.push_back(pSelector);

    setListaObjetos(lista);
}

void FaseMenu::moveRigth(ObjetoDeJogo &obj){
    for(int i=0; i < 20; i++){
        obj.moveRigth();
    }
}

void FaseMenu::moveLeft(ObjetoDeJogo &obj){
    for(int i=0; i < 20; i++){
        obj.moveLeft();
    }
}