#ifndef PODER_H
#define PODER_H

#include "allegro.cpp"
#include "main.hpp"
#include "poder.hpp"
#include "pontuacao.cpp"

class Doce {
    public:
        ALLEGRO_BITMAP *doceLaranja = doceLaranja;
        ALLEGRO_BITMAP *doceVermelho = doceVermelho;
        ALLEGRO_BITMAP *doceAzul = doceAzul;
        ALLEGRO_BITMAP *doceVerde = doceVerde;
        ALLEGRO_BITMAP *doceRoxo = doceRoxo;
        ALLEGRO_BITMAP *doceAmarelo = doceAmarelo;
        void getDoce(int cor,int i, int j, int q);
        
};





class Poder {
    private:
    int _Doce;
    protected:
     ////////////////////////////////
    public:
    Poder();
    void Troca();
    void Ovini();
    void Pincel_listrado();
    void Martelo_doce();
    void Booster();
};

#endif
