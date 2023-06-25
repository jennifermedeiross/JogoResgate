#ifndef FASEMENU_HPP
#define FASEMENU_HPP

#include "ASCII_ENGINE/Fase.hpp"

class FaseMenu : public Fase{

    private:
        ObjetoDeJogo *pStart;
        ObjetoDeJogo *pHelp;
        ObjetoDeJogo *pAbout;
        ObjetoDeJogo *pExit;
        ObjetoDeJogo *pSelector;

    public:
        FaseMenu(std::string state) : Fase(state){}
        ~FaseMenu(){
            Fase::~Fase();
            delete pStart;
            delete pHelp;
            delete pAbout;
            delete pExit;
            delete pSelector;
        }

        virtual void run();
        void moveRigth(ObjetoDeJogo &);
        void moveLeft(ObjetoDeJogo &);

        //GAMEBASE
        virtual void init();


};

#endif