#ifndef PODER_H
#define PODER_H

#include "allegro.cpp"
#include "main.hpp"
#include "poder.hpp"

class DoceLaranja{
    public:
        ALLEGRO_BITMAP *doceLaranja = dlaranja;
        void getDoceLaranja(int i, int j, int q);
        

};

class DoceVermelho {
    public:
        ALLEGRO_BITMAP *doceVermelho = dvermelho;
        void getDoceVermelho(int i, int j, int q);

};

class DoceAzul {
    public:
        ALLEGRO_BITMAP *doceAzul = dazul;
        void getDoceAzul(int i, int j, int q);

};

class DoceVerde{
    public:
        ALLEGRO_BITMAP *doceVerde = dverde;
        void getDoceVerde(int i, int j, int q);

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
