#ifndef PODER_CPP
#define PODER_CPP

#include "poder.hpp"

void DoceLaranja::getDoceLaranja(int i, int j, int q){
    al_draw_bitmap(this->doceLaranja, j*q, i*q, 0);
}
void DoceVermelho::getDoceVermelho(int i, int j, int q){
    al_draw_bitmap(this->doceVermelho, j*q, i*q, 0);
}
void DoceAzul::getDoceAzul(int i, int j, int q){
    al_draw_bitmap(this->doceAzul, j*q, i*q, 0);
}
void DoceVerde::getDoceVerde(int i, int j, int q){
    al_draw_bitmap(this->doceVerde, j*q, i*q, 0);


#endif