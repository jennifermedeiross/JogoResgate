#ifndef OBJETODEJOGO_HPP
#define OBJETODEJOGO_HPP

#include "GameBase.hpp"
#include "SpriteBase.hpp"
#include "Sprite.hpp"
#include "SpriteAnimado.hpp"

class ObjetoDeJogo : public GameBase
{
    private:
        std::string nome;
        SpriteBase spriteObj;
        bool ativo;
        unsigned coluna, linha; //x e y, respectivamente

    public:
        ObjetoDeJogo(std::string nome, Sprite sprite, unsigned coluna, unsigned linha) :
            nome(nome), spriteObj(sprite), coluna(coluna), linha(linha) {}

        ObjetoDeJogo(std::string nome, SpriteAnimado sprite, unsigned coluna, unsigned linha) :
            nome(nome), spriteObj(sprite), coluna(coluna), linha(linha) {}

        virtual ~ObjetoDeJogo() {}

        bool colideCom(ObjetoDeJogo &) const;
        void moveTo(unsigned, unsigned);
        void moveLeft();
        void moveRigth();
        void moveDown();
        void moveUp();

        // GETTERS E SETTERS
        std::string getNome() const{ return this->nome; }
        SpriteBase getSpriteObj(){ return this->spriteObj; }
        unsigned getLinha() const { return this->linha; }
        unsigned getColuna() const { return this->coluna; }

        void setNome(std::string);
        void setSpriteObj(SpriteBase&);
        void setLinha(unsigned);
        void setColuna(unsigned);
        
        void ativar();
        void desativar();

        // GAMEBASE
        virtual void init(){}
        virtual void update(){}
        virtual void draw(SpriteBase &screen, unsigned x, unsigned y){
            if(ativo){
                getSpriteObj().draw(screen, x, y);
            }
        } // Precisa de ajustes
    };

#endif