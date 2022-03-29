#ifndef MAPA_HPP
#define MAPA_HPP

#include "allegro.cpp"
#include "pontuacao.hpp"
#include "poder.hpp"


class Mapa {
    public:
        int MAPA[18][7];
        int setCoordenada(int escolha);
        int clearCoordenada();
        // Ordem de verificação da função check, (função especial vem antes) função 5 -> 4 -> 3
        void funcao_check_5(int i, int j, Pontos &pontos);
        void funcao_check_4(int i, int j, Pontos &pontos);
        void funcao_check_3(int i,int j, Pontos &pontos);
        int  funcao_cair_doces(int check_type, int x, int y);

        void funcao_troca_doces(int y_esq, int x_esq, int y_dir, int x_dir, Pontos &pontos);
        
        int getMapa();
        int getCoordenada(int x, int i);
        void setMapa(int escolha);

};


#endif