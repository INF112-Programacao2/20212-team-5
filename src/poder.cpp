#ifndef PODER_CPP
#define PODER_CPP

#include "poder.hpp"

void Doce::getDoce(int cor,int i, int j, int q){
    switch(cor){
        case 0:
            al_draw_bitmap(this->doceLaranja, (j*q)+OFFSETX, ((i-11)*q)+OFFSETY, 0);
            break;
        case 1:
            al_draw_bitmap(this->doceRoxo, (j*q)+OFFSETX, ((i-11)*q)+OFFSETY, 0);
            break;
        case 2:
            al_draw_bitmap(this->doceVerde, (j*q)+OFFSETX, ((i-11)*q)+OFFSETY, 0);
            break;
        case 3:
            al_draw_bitmap(this->doceVermelho, (j*q)+OFFSETX, ((i-11)*q)+OFFSETY, 0); 
            break;
        case 4:
            break;
        case 5:
            al_draw_bitmap(this->doceAmarelo, (j*q)+OFFSETX, ((i-11)*q)+OFFSETY, 0);
            break;
        case 6:
            al_draw_bitmap(this->doceAzul, (j*q)+OFFSETX, ((i-11)*q)+OFFSETY, 0);
            break;
        default:
            al_draw_bitmap(this->doceLaranja, (j*q)+OFFSETX, ((i-11)*q)+OFFSETY, 0);
            break;
    }
}



void Poder::Ovini(){


}
void Poder::Pincel_listrado(){


}
void Poder::Martelo_doce(){


}
void Poder::Booster(){


}

#endif



