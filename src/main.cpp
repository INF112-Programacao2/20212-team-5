/*
                                            Bem vindo ao jogo do Candy Crush SAGA
            Trabalho final de INF112, consiste em recriar o game CandyCrush em C++, disponível para computadores Windows/Linux x64
                    FLAGS NECESSÁRIAS PARA O COMPILADOR/LINKADOR -> -lallegro -lallegro_image -lallegro_font -lallegro_ttf
*/

#include <stdlib.h>
#include "main.hpp"
#include "inicializa.cpp"
#include "nivel.cpp"
#include "menu.cpp"

//Ponto de entrada do programa
// Abre uma instância de Menu que irá ser usada globalmente nesse programa
// Liga a função "inicializa", para montar a interface gráfica


int main(int argc, char **argv){
    Menu Menu;
	if(!inicializa()) return -1;
    srand(time(NULL));
    while(!sair){
        Menu.mainmenu();
    }
    desinicializa();
    return 0;
}