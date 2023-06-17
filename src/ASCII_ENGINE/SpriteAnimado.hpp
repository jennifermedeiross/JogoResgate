#ifndef SPRITEANIMADO_HPP
#define SPRITEANIMADO_HPP

#include "SpriteBase.hpp"

class SpriteAnimado : public SpriteBase {
    
    public:
        SpriteAnimado(){}

        virtual ~SpriteAnimado(){}
        
        virtual void draw(SpriteBase &screen, unsigned coluna, unsigned linha){}

};

#endif