#ifndef SPRITEANIMADO_HPP
#define SPRITEANIMADO_HPP

#include "SpriteBase.hpp"
#include "Sprite.hpp"

class SpriteAnimado : public SpriteBase {
    private:
        std::vector<Sprite> sprites;
        int spriteAtual, alturaSprites, quantidadeSprites;

    public:
        SpriteAnimado(std::string caminho) : 
            SpriteBase(caminho), spriteAtual(0) {}

        virtual ~SpriteAnimado(){}

        virtual SpriteBase *copy(){ return new SpriteAnimado(*this); }

        Sprite getSpriteAtual() const { return sprites[spriteAtual]; }
        void dividirSprites();
        void lerMedidas();

        virtual void update();
        virtual void draw(SpriteBase &screen, unsigned coluna, unsigned linha);

};

#endif