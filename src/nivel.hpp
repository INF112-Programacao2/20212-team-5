#ifndef NIVEL_H
#define NIVEL_H

#include "allegro.cpp"
#include "pontuacao.hpp"
#include "poder.hpp"


class Nivel {
    
    public:
        int faseUm(ALLEGRO_EVENT &ev);
        
};

class Mapa {
    public:
        int MAPA[18][7] = {
            0, 2 ,3,0,5,0,0,
            1, 5 ,3,5,6,5,6,
            2, 1 ,6,0,5,3,6,
        
            3, 2 ,5,5,1,2,0,
            3, 5 ,2,1,0,2,1,
            5, 1 ,3,0,0,1,0,
        
            1, 2 ,1,0,1,2,1,
            6, 1 ,2,6,6,5,0,
            6, 3 ,1,3,5,1,2,
            0, 2 ,3,0,5,0,0,
            1, 5 ,3,5,6,5,6,
            2, 1 ,6,0,5,3,6,
        
            3, 2 ,5,5,2,2,0,
            3, 5 ,2,1,6,6,1,
            5, 1 ,3,0,0,1,0,
        
            1, 2 ,1,0,1,2,1,
            6, 1 ,2,6,6,1,0,
            6, 3 ,1,3,5,1,2,
        };
        void funcao_troca_doces(int y_esq, int x_esq, int y_dir, int x_dir);
        int getMapa();
        int getCoordenada(int x, int i);
        void setMapa(int escolha);
};


#endif