#ifndef MAPA_HPP
#define MAPA_HPP

#include "allegro.cpp"
#include "pontuacao.hpp"
#include "poder.hpp"


class Mapa {
        int MAPA[18][7];
    public:
        Mapa(int Mapa[][7]){
            for(int i=0;i<18;i++){
                for(int j=0;j<7;j++){
                    this->MAPA[i][j] = Mapa[i][j];
                }
            }
        }
        
        int setCoordenada(int escolha);
        int clearCoordenada();
        // Ordem de verificação da função check, (função especial vem antes) função 5 -> 4 -> 3
        void funcao_check_5(int i, int j, Pontos &pontos);
        void funcao_check_4(int i, int j, Pontos &pontos);
        void funcao_check_3(int i,int j, Pontos &pontos);
        int  funcao_cair_doces(int check_type, int x, int y);
        void funcao_cair_doce_listrado_vertical(int x, int y);
        void funcao_cairDoce_listrado_horizontal(int aux_5,int y_dir, int x_dir);
        void funcao_troca_doces(int y_esq, int x_esq, int y_dir, int x_dir, Pontos &pontos);

        int funcao_aux_check3_esp(int i, int j, int tipo_positivo, int tipo_listrado, int &n_doces);
        int funcao_aux_check4_esp(int i, int j, int tipo_positivo, int tipo_listrado, int &n_doces);
        int funcao_check_especial(int i, int j);
        
        int getMapa();
        int getCoordenada(int x, int i);
        void setMapa(int escolha);

};


#endif