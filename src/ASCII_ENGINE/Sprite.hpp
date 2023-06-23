#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "SpriteBase.hpp"

class Sprite : public SpriteBase {

    public:
        Sprite(std::string caminho) : 
            SpriteBase(caminho) {}
        Sprite(){}
        virtual ~Sprite(){}

        virtual SpriteBase *copy();

        virtual void update(){}  
        virtual void draw(SpriteBase &screen, unsigned coluna, unsigned linha);

};

#endif