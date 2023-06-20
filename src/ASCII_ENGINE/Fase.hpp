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
        Fase(){}
        
        virtual ~Fase() { delete background; }

        virtual void run() = 0;
        void show(SpriteBase *);

        // GETTERS E SETTERS
        SpriteBase *getBackground(){ return this->background; }
        std::list<ObjetoDeJogo*> getListaDeObjetos() { return this->listaObjetos; }

        void setBackground(SpriteBase *);
        void setListaObjetos(std::list<ObjetoDeJogo*>);

        // GAMEBASE
        virtual void init() = 0;
        virtual void update(){}
        virtual void draw(SpriteBase&, unsigned, unsigned);
};

#endif