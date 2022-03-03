/*
                                            Bem vindo ao jogo do Candy Crush SAGA
            Trabalho final de INF112, consiste em recriar o game CandyCrush em C++, disponível para computadores Windows/Linux x64
                    FLAGS NECESSÁRIAS PARA O COMPILADOR/LINKADOR -> -lallegro -lallegro_image -lallegro_font -lallegro_ttf
*/

#include <stdlib.h>
#include "main.h"
#include "allegro.h"
#include "inicializa.h"


int main(int argc, char **argv){
	if(!inicializa()) return -1;
    srand(time(NULL));
    while(!sair){
        mainmenu();
    }
    
    
    desinicializa();
                
    
    return 0;
}