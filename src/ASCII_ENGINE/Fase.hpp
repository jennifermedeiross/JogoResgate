#ifndef FASE_HPP
#define FASE_HPP

#include "GameBase.hpp"
#include "SpriteBase.hpp"
#include "Sprite.hpp"
#include "SpriteAnimado.hpp"
#include "ObjetoDeJogo.hpp"
#include "Sound.hpp"
#include "Teclado.hpp"

class Fase : public GameBase
{
    private:
        Teclado teclado; // manipulação do teclado
        SpriteBase *background;
        std::list<ObjetoDeJogo*> listaObjetos;
        std::string STATE; // deve ser o nome exato da classe derivada

    public:
        Fase(std::string state) : STATE(state) {}
        
        virtual ~Fase() { 
            delete background;
            for (auto it = listaObjetos.begin(); it != listaObjetos.end(); ++it) {
                delete *it;
            }
            listaObjetos.clear();
        }

        virtual void run() = 0;
        void show(SpriteBase *);

        // GETTERS E SETTERS
        Teclado getTeclado() const { return this->teclado; }
        SpriteBase *getBackground(){ return this->background; }
        std::list<ObjetoDeJogo*> getListaDeObjetos() { return this->listaObjetos; }
        std::string faseState() const { return this->STATE; }

        void setBackground(SpriteBase *);
        void setListaObjetos(std::list<ObjetoDeJogo*>);
        void setState(std::string);

        // GAMEBASE
        virtual void init() = 0;
        virtual void update();
        virtual void draw(SpriteBase&, unsigned, unsigned);
};

#endif