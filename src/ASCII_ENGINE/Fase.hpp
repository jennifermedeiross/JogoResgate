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
        SpriteBase background;
        std::list<ObjetoDeJogo*> listaObjetos;

    public:
        Fase(/* args */);
        ~Fase();

};

#endif