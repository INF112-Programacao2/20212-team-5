#ifndef NIVEL_H
#define NIVEL_H

#include "allegro.cpp"
#include "pontuacao.hpp"
#include "poder.hpp"
#include "mapa.cpp"

class Nivel{
    public:
        int faseUm(ALLEGRO_EVENT &ev, int fase);
        int faseDois(ALLEGRO_EVENT &ev, int fase);
        int faseTres(ALLEGRO_EVENT &ev, int fase);
        int faseQuatro(ALLEGRO_EVENT &ev, int fase);
        int faseCinco(ALLEGRO_EVENT &ev, int fase);
};


#endif