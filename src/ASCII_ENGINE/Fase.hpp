#ifndef FASE_HPP
#define FASE_HPP

#include "GameBase.hpp"
#include "SpriteBase.hpp"
#include "Sprite.hpp"
#include "SpriteAnimado.hpp"
#include "ObjetoDeJogo.hpp"

class Fase : public GameBase
{
    private:
        SpriteBase *background;
        std::list<ObjetoDeJogo*> listaObjetos;

    public:
        Fase(SpriteBase background, std::list<ObjetoDeJogo*>listaObjetos) :
            background(new SpriteBase(background)), listaObjetos(listaObjetos){}
        
        virtual ~Fase() {}

        void run(){}
        void show(){}

        // GETTERS E SETTERS
        SpriteBase *getBackground(){ return this->background; }
        std::list<ObjetoDeJogo*> getListaDeObjetos() { return this->listaObjetos; }

        // GAMEBASE
        virtual void init(){}
        virtual void update(){}
        virtual void draw(SpriteBase&, unsigned, unsigned){}
};

#endif