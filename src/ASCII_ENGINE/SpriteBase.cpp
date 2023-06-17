#include "SpriteBase.hpp"

SpriteBase::SpriteBase(std::string caminho){
    setCaminho(caminho);
    vetorizarArquivo();
}

void SpriteBase::vetorizarArquivo() {
    std::ifstream arquivo(this->getCaminho());

    if (arquivo.is_open()){
        std::string line;
        while (getline(arquivo, line))
        {
            this->sprite.push_back(line);
        }
        arquivo.close();
    }
}

void SpriteBase::imprimir(){
    for (std::string  linha : this->getSprite()){
        std::cout << linha << std::endl;
    }
}

void SpriteBase::setCaminho(std::string caminho){
    this->caminho = caminho;
}

void SpriteBase::setSprite(std::vector<std::string> novoSprite){
    this->sprite = novoSprite;
}
