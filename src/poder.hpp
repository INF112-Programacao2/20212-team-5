#ifndef PODER_H
#define PODER_H

#include "allegro.cpp"
#include "main.hpp"
#include "poder.hpp"
#include "pontuacao.cpp"

class Doce {
    public:
        ALLEGRO_BITMAP *doceLaranja = dlaranja;
        ALLEGRO_BITMAP *doceVermelho = dvermelho;
        ALLEGRO_BITMAP *doceAzul = dazul;
        ALLEGRO_BITMAP *doceVerde = dverde;
        ALLEGRO_BITMAP *doceRoxo = droxo;
        ALLEGRO_BITMAP *doceAmarelo = damarelo;
        void getDoce(int cor,int i, int j, int q);
        
};





class Poder {
    private:
     ////////////////////////////////
    protected:
     ////////////////////////////////
    public:
     ////////////////////////////////
};

#endif
