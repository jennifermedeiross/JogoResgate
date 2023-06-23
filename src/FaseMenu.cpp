// #include "FaseMenu.hpp"

// void FaseMenu::run(){
//     Sprite screen("src/imgs/screen.txt");
//     Sound somMenu("src/musics/menu.mp3");
//     Sound selecionou("src/musics/salvou.mp3");

//     init();
//     somMenu.playloop();

//     while (true) {
        
//         system("clear");

//         draw(screen, 0 ,0);
//         show(&screen);
//         char entrada = getTeclado().getch();

//         if(entrada == 'w' || entrada == 'W'){
//             if(pArrow->getLinha() < pStart->getLinha())
//                 pArrow->moveTo(21);
//         }
//     }
// }

// void FaseMenu::init(){
//     Sprite screen("src/imgs/screen.txt");
//     Sprite helicoptero("src/imgs/helicopteroMenu.txt");

//     helicoptero.draw(screen, 5, 66);

//     this->setBackground(&screen);

//     std::list<ObjetoDeJogo*> lista;

//     pStart = new Text(ObjetoDeJogo(Sprite("src/imgs/start.txt"), 20, 78));
//     pHelp = new Text(ObjetoDeJogo(Sprite("src/imgs/start.txt"), 25, 78));
//     pExit = new Text(ObjetoDeJogo(Sprite("src/imgs/exit.txt"), 30, 78));
//     pArrow = new Text(ObjetoDeJogo(Sprite("src/imgs/seta.txt"), 18, 78));

//     lista.push_back(pStart);
//     lista.push_back(pHelp);
//     lista.push_back(pExit);
//     lista.push_back(pArrow);


//     this->setListaObjetos(lista);

// }