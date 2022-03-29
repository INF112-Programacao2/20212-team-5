#ifndef PODER_H
#define PODER_H

#include "allegro.cpp"
#include "main.hpp"
#include "poder.hpp"
#include "pontuacao.cpp"

class Peca {
    
    int _pontoPeca;
    public:
        ALLEGRO_BITMAP *doceLaranja = NULL;
        ALLEGRO_BITMAP *doceVermelho = NULL;
        ALLEGRO_BITMAP *doceAzul = NULL;
        ALLEGRO_BITMAP *doceVerde = NULL;
        ALLEGRO_BITMAP *doceRoxo = NULL;
        ALLEGRO_BITMAP *doceAmarelo = NULL;
        virtual int pontoPeca()=0;
};

class Doce : public Peca{
    public:
        
        Doce (){
        this->doceLaranja = dlaranja;
        this->doceVermelho = dvermelho;
        this->doceAzul = dazul;
        this->doceVerde = dverde;
        this->doceRoxo = droxo;
        this->doceAmarelo = damarelo;
        };
        int _pontoPeca = 10;
        int pontoPeca(){ return this->_pontoPeca; };
        void getDoce(int cor,int i, int j, int q);
        
};

class DoceListrado : Peca{
    
    public:
        DoceListrado(){
            this->doceLaranja = dlaranja;
            this->doceVermelho = dvermelho;
            this->doceAzul = dazul;
            this->doceVerde = dverde;
            this->doceRoxo = droxo;
            this->doceAmarelo = damarelo;
        };
        int _pontoPeca = 30;
        int pontoPeca(){ return this->_pontoPeca; };
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
