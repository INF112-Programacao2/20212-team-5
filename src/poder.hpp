#ifndef PODER_H
#define PODER_H

#include "allegro.cpp"
#include "main.hpp"
#include "poder.hpp"
#include "pontuacao.cpp"

class Peca {
    public:
        int _pontoPeca;
        ALLEGRO_BITMAP *doceLaranja = NULL;
        ALLEGRO_BITMAP *doceVermelho = NULL;
        ALLEGRO_BITMAP *doceAzul = NULL;
        ALLEGRO_BITMAP *doceVerde = NULL;
        ALLEGRO_BITMAP *doceRoxo = NULL;
        ALLEGRO_BITMAP *doceAmarelo = NULL;
        ALLEGRO_BITMAP *doceEspecialHorizontalLaranja = NULL;
        ALLEGRO_BITMAP *doceEspecialHorizontalVerde = NULL;
        ALLEGRO_BITMAP *doceEspecialHorizontalRoxo = NULL;
        ALLEGRO_BITMAP *doceEspecialHorizontalVermelho = NULL;
        ALLEGRO_BITMAP *doceEspecialVerticalAzul = NULL;
        ALLEGRO_BITMAP *doceEspecialVerticalAmarelo = NULL;
        ALLEGRO_BITMAP *brigadeiroEspecial= NULL;
        int pontoPeca();
        int setPonto();
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
        
        int pontoPeca(){ return this->_pontoPeca; };
        int setPonto(){ this->_pontoPeca = 10;};
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
            this->doceEspecialHorizontalLaranja = especialhorizontallaranja;
            this->doceEspecialHorizontalVerde = especialhorizontalvermelho;
            this->doceEspecialHorizontalRoxo = especialhorizontalroxo;
            this->doceEspecialVerticalAzul = especialverticalazul;
            this->doceEspecialVerticalAmarelo = especialverticalamarelo;
            this->brigadeiroEspecial = brigadeiroespecial;
            this->_pontoPeca = 30;
        };
        
        int pontoPeca(){ return this->_pontoPeca; };
        int setPonto(int i){ this->_pontoPeca = (30*i);};
        void getDoce(int cor,int i, int j, int q);
};

class Poder {
    private:
    int _Doce;
    public:
    void DesenhoPoder();
    void Troca();
    void Ovini();
    void Pincel_listrado();
    void Martelo_doce();
    void Booster();
};

#endif