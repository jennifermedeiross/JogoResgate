#ifndef SPRITEBASE_HPP
#define SPRITEBASE_HPP

#include "GameBase.hpp"

class SpriteBase : public GameBase{

    private:
        std::string caminho;
        std::vector<std::string> sprite;
        int altura, largura;

    public:
        SpriteBase(){}
        SpriteBase(std::string);
        virtual ~SpriteBase(){};
        
        friend std::ostream& operator<<(std::ostream&, const SpriteBase&);
        void vetorizarArquivo();

        std::string getCaminho() const { return this->caminho; }
        std::vector<std::string> getSprite() const { return this->sprite; }
        int getAltura() const { return this->altura; }
        int getLargura() const { return this->largura; }

        void setCaminho(std::string);
        void setSprite(std::vector<std::string>);
        void setAltura(int);
        void setLargura(int);

        virtual SpriteBase *copy() = 0;
        
        // GAMEBASE
        virtual void init(){}
        virtual void update() = 0;
        virtual void draw(SpriteBase&, unsigned, unsigned) = 0;

};

#endif
