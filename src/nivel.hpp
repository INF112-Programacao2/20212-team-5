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

/*
class Mapa {
    private:
     ////////////////////////////////
    protected:
     ////////////////////////////////
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
        // Ordem de verificação da função check, (função especial vem antes) função 5 -> 4 -> 3
        void funcao_check_5(int i, int j);
        void funcao_check_4(int i, int j);
        void funcao_check_3(int i,int j);
        int  funcao_cair_doces(int check_type, int x, int y);

        void funcao_troca_doces(int y_esq, int x_esq, int y_dir, int x_dir, Pontos &pontos);
        int getMapa();
        int getCoordenada(int x, int i);
        void setMapa(int escolha);

};

*/


#endif
