#ifndef ESCREVE_CPP
#define ESCREVE_CPP

#include "allegro.cpp"

void escreveArquivo(){
    ALLEGRO_FILE *arquivo = NULL;
    arquivo = al_fopen("test.txt", "w");
    al_fputs(arquivo, "SaveGame Dia 21");
}

#endif
