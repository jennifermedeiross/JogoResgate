#include "SpriteBase.hpp"

SpriteBase::SpriteBase(std::string caminho){
    setCaminho(caminho);
    vetorizarArquivo();
    this->altura = getSprite().size();
    this->largura = getSprite()[0].size();
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

std::ostream& operator<<(std::ostream& out, const SpriteBase& spriteBase) {
    for (const std::string& linha : spriteBase.sprite) {
        out << linha << std::endl;
    }
    return out;
}

void SpriteBase::setCaminho(std::string caminho){
    this->caminho = caminho;
}

void SpriteBase::setSprite(std::vector<std::string> novoSprite){
    this->sprite = novoSprite;
}

void SpriteBase::setAltura(int altura){
    this->altura = altura;
}

void SpriteBase::setLargura(int largura){
    this->largura = largura;
}
