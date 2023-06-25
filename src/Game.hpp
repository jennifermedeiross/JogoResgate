#ifndef GAME_HPP
#define GAME_HPP

#include "FaseGame.hpp"
#include "FaseMenu.hpp"

class Game {
        
    public:
        Game(){}
        ~Game(){}

        void run(){
            FaseGame faseGame("FaseGame");
            FaseMenu faseMenu("FaseMenu");

            faseMenu.run();

            while(true){

                if(faseMenu.faseState() == "FaseGame"){
                    faseGame.run();
                    if(faseGame.faseState() == "FaseMenu"){
                        faseMenu.run();
                    }
                }
                else if(faseMenu.faseState() == "end"){
                    break;
                }

            }
        }
};


#endif