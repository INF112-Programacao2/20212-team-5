/*
                                            Bem vindo ao jogo do Candy Crush SAGA
            Trabalho final de INF112, consiste em recriar o game CandyCrush em C++, disponível para computadores Windows/Linux x64
                    FLAGS NECESSÁRIAS PARA O COMPILADOR/LINKADOR -> -lallegro -lallegro_image -lallegro_font -lallegro_ttf
*/
#include "escreve.cpp"
#include <stdlib.h>
#include "main.hpp"
#include "inicializa.cpp"
#include "nivel.cpp"
#include "menu.cpp"
#include "escreve.cpp"


using namespace std;

int main(int argc, char **argv){
    Menu Menu;
    
    leArquivo();
 //   char save[] = R"(
 //       {
 //       "Save": {
 //           "Fase":  4,
 //           "Pontuação": 0,
 //           "Movimentos":  [
 //               0, 1, 1, 1, 1, 1, 1, 1,
 //               0, 1, 1, 1, 1, 1, 1, 1,
 //               0, 1, 1, 1, 1, 1, 1, 1,
 //               0, 1, 1, 1, 1, 1, 1, 1,
 //               0, 1, 1, 1, 1, 1, 1, 1,
 //               0, 1, 1, 1, 1, 1, 1, 1,
 //               0, 1, 1, 1, 1, 1, 1, 1,
 //               0, 1, 1, 1, 1, 1, 1, 1
 //           ],
 //           "Morreu": false,
 //           "Poderes": [Ovni, 2], [Pirulito, 2],
 //           "Data": [21, 03, 2022]
 //       }
 //   }
 //   )";
 //   Arquivo << save;
 //   Arquivo.close();
 //   
	if(!inicializa()) return -1;
    srand(time(NULL));
    while(!sair){
        Menu.mainmenu();
    }
    desinicializa();
    return 0;
}