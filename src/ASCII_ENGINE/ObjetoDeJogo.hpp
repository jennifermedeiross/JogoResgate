#ifndef OBJETODEJOGO_HPP
#define OBJETODEJOGO_HPP

#include "GameBase.hpp"
#include "SpriteBase.hpp"
#include "Sprite.hpp"
#include "SpriteAnimado.hpp"

class ObjetoDeJogo : public GameBase
{
    private:
        SpriteBase *spriteObj;
        bool ativo;
        unsigned coluna, linha; //x e y, respectivamente

    public:
        ObjetoDeJogo(Sprite sprite, unsigned coluna, unsigned linha) :
            spriteObj(new Sprite(sprite)), coluna(coluna), linha(linha), ativo(true) {}

        ObjetoDeJogo(SpriteAnimado sprite, unsigned coluna, unsigned linha) :
            spriteObj(new SpriteAnimado(sprite)), coluna(coluna), linha(linha), ativo(true) {}

        virtual ~ObjetoDeJogo() { delete spriteObj; }

        bool colideCom(ObjetoDeJogo &) const;
        void moveTo(unsigned, unsigned);
        void moveLeft();
        void moveRigth();
        void moveDown();
        void moveUp();

        // GETTERS E SETTERS
        SpriteBase *getSpriteObj(){ return this->spriteObj; }
        unsigned getLinha() const { return this->linha; }
        unsigned getColuna() const { return this->coluna; }

        void setSpriteObj(SpriteBase&);
        void setLinha(unsigned);
        void setColuna(unsigned);
        
        void ativar();
        void desativar();

        // GAMEBASE
        virtual void init(){}
        virtual void update(){}
        virtual void draw(SpriteBase&, unsigned, unsigned);
    };

#endif