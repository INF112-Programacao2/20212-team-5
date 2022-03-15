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
        int MAPA[8][8];
        int getMapa();
        int getCoordenada(int x, int i);
        void setMapa(int escolha);
};


#endif