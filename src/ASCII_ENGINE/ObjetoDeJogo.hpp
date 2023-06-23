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
        ObjetoDeJogo(const Sprite &sprite, unsigned coluna, unsigned linha) :
            spriteObj(new Sprite(sprite)), coluna(coluna), linha(linha), ativo(true) {}

        ObjetoDeJogo(const SpriteAnimado &sprite, unsigned coluna, unsigned linha) :
            spriteObj(new SpriteAnimado(sprite)), coluna(coluna), linha(linha), ativo(true) {}
        
        ObjetoDeJogo(const ObjetoDeJogo &);

        virtual ~ObjetoDeJogo() { delete spriteObj; }

        bool colideCom(ObjetoDeJogo &) const;
        virtual void moveTo(unsigned, unsigned);
        virtual void moveLeft();
        virtual void moveRigth();
        virtual void moveDown();
        virtual void moveUp();

        // GETTERS E SETTERS
        SpriteBase *getSpriteObj(){ return this->spriteObj; }
        unsigned getLinha() const { return this->linha; }
        unsigned getColuna() const { return this->coluna; }
        bool getAtivo() const { return this->ativo; }

        void setSpriteObj(SpriteBase&);
        void setLinha(unsigned);
        void setColuna(unsigned);
        
        void ativar();
        void desativar();

        // GAMEBASE
        virtual void init(){}
        virtual void update();
        virtual void draw(SpriteBase&, unsigned, unsigned);
    };

#endif