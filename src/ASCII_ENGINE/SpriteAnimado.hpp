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
            SpriteBase(caminho), spriteAtual(0){
                lerMedidas();
                dividirSprites();
                setAltura(getSpriteAtual().size());
                setLargura(getSpriteAtual()[0].size());
                setSprite(getSpriteAtual());
            }

        virtual ~SpriteAnimado(){}

        virtual SpriteBase *copy(){ return new SpriteAnimado(*this); }

        std::vector<std::string> getSpriteAtual() const { return sprites[spriteAtual].getSprite(); }
        void dividirSprites();
        void lerMedidas();
        void imprimirSpriteAnimado();

        virtual void update();
        virtual void draw(SpriteBase &screen, unsigned coluna, unsigned linha);

};

#endif