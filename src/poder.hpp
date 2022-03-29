#ifndef PODER_H
#define PODER_H

#include "allegro.cpp"
#include "main.hpp"
#include "poder.hpp"
#include "pontuacao.cpp"


class Pecas {
    public:
        virtual int pontosDoce()=0;
        virtual void getDoce()=0;

};

class Doce{
    int _pontoPecaNormal = 10;
    int _objetivosDeFase[6] = {0,0,0};
    protected:
        ALLEGRO_BITMAP *doceLaranja = dlaranja;
        ALLEGRO_BITMAP *doceVermelho = dvermelho;
        ALLEGRO_BITMAP *doceAzul = dazul;
        ALLEGRO_BITMAP *doceVerde = dverde;
        ALLEGRO_BITMAP *doceRoxo = droxo;
        ALLEGRO_BITMAP *doceAmarelo = damarelo;
    public:
        int pontosDoce(){ return this->_pontoPecaNormal; };
        void getDoce(int cor,int i, int j, int q);
        void passObjetivos(Pontos &pontuacao);
        
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
