#ifndef SPRITEBASE_HPP
#define SPRITEBASE_HPP

#include "GameBase.hpp"

class SpriteBase : public GameBase{
    private:
        std::string caminho;
        std::vector<std::string> sprite;

    public:
        SpriteBase(){}
        SpriteBase(std::string);
        virtual ~SpriteBase(){};
        
        void vetorizarArquivo();
        void imprimir();

        std::string getCaminho() const { return this->caminho; }
        std::vector<std::string> getSprite() const { return this->sprite; }

        void setCaminho(std::string);
        void setSprite(std::vector<std::string>);
        
        // GAMEBASE
        virtual void init(){}
        virtual void update(){}
        virtual void draw(SpriteBase&, unsigned, unsigned){}

};

#endif
