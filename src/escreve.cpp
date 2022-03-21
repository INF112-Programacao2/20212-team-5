#ifndef ESCREVE_CPP
#define ESCREVE_CPP

#include "allegro.cpp"
#include <iostream>
#include <string>

void leArquivo(){
    ALLEGRO_FILE *arquivo = NULL;
    //char texto;
    char buffer[1000];
    arquivo = al_fopen("test.txt", "r");
    //texto = al_fgets(arquivo, buffer, al_fsize(arquivo));
    
    
}

void escreveArquivo(){
    ALLEGRO_FILE *arquivo = NULL;
    arquivo = al_fopen("test.txt", "w");
    al_fputs(arquivo, "SaveGame Dia 21");
}

#endif
