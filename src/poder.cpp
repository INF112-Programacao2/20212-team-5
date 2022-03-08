#ifndef PODER_CPP
#define PODER_CPP

#include "poder.hpp"

void Doce::getDoce(int cor,int i, int j, int q){
    switch(cor){
        case 1:
            al_draw_bitmap(this->doceLaranja, j*q, i*q, 0);
        case 2:
            al_draw_bitmap(this->doceVermelho, j*q, i*q, 0);
        case 3:
            al_draw_bitmap(this->doceAzul, j*q, i*q, 0);
        case 4:
            al_draw_bitmap(this->doceVerde, j*q, i*q, 0);
        case 5:
            al_draw_bitmap(this->doceRoxo, j*q, i*q, 0);
        case 6:
            al_draw_bitmap(this->doceAmarelo, j*q, i*q, 0);
        default:
            al_draw_bitmap(this->doceLaranja, j*q, i*q, 0);
    }
    
}


#endif