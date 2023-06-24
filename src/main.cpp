#include "ASCII_ENGINE/SpriteBase.hpp"
#include "ASCII_ENGINE/Sprite.hpp"
#include "ASCII_ENGINE/SpriteAnimado.hpp"
#include "ASCII_ENGINE/ObjetoDeJogo.hpp"
#include "ASCII_ENGINE/Fase.hpp"
#include "Pessoa.hpp"
#include "Heroi.hpp"
#include "Combustivel.hpp"
#include "Base.hpp"
#include "FaseGame.hpp"
#include "FaseMenu.hpp"

int main() {
    FaseGame fase("FaseGame");
    fase.run();

    return 0;
}
