#ifndef PODER_CPP
#define PODER_CPP

#include "poder.hpp"

void Doce::getDoce(int cor,int i, int j, int q){
    switch(cor){
        case 1:
            al_draw_bitmap(this->doceLaranja, j*q, i*q, 0);
            break;
        case 2:
            al_draw_bitmap(this->doceVermelho, j*q, i*q, 0);
            break;
        case 3:
            al_draw_bitmap(this->doceAzul, j*q, i*q, 0);
            break;
        case 4:
            al_draw_bitmap(this->doceVerde, j*q, i*q, 0);
            break;
        case 5:
            al_draw_bitmap(this->doceRoxo, j*q, i*q, 0);
            break;
        case 6:
            al_draw_bitmap(this->doceAmarelo, j*q, i*q, 0);
            break;
        default:
            al_draw_bitmap(this->doceLaranja, j*q, i*q, 0);
            break;
    }
    
}




#endif