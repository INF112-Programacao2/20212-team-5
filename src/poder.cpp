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

void Poder::Troca(){
     if ((mapa[i][j]=1)&&(mapa[i][j]=2)){
        al_draw_bitmap(this-> docesimplesverde ,j*q,i*q,0);
    }
    if ((mapa[i][j]=1)&&(mapa[i][j]=3)){
        al_draw_bitmap(this-> docesimplesvermelho ,j*q,i*q,0);
    }
    if ((mapa[i][j]=1)&&(mapa[i][j]=4)){
        al_draw_bitmap(this-> docesimplesverde ,j*q,i*q,0);
    }
    if ((mapa[i][j]=1)&&(mapa[i][j]=5)){
        al_draw_bitmap(this-> docesimplesamarelo ,j*q,i*q,0);
    }
    if ((mapa[i][j]=1)&&(mapa[i][j]=6)){
        al_draw_bitmap(this-> docesimplesazul ,j*q,i*q,0);
    }
    if ((mapa[i][j]=1)&&(mapa[i][j]=1)){
        al_draw_bitmap(this-> docesimpleslaranja ,j*q,i*q,0);
    }

    if ((mapa[i][j]=2)&&(mapa[i][j]=2)){
        al_draw_bitmap(this-> docesimplesverde ,j*q,i*q,0);
    }
    if ((mapa[i][j]=2)&&(mapa[i][j]=3)){
        al_draw_bitmap(this-> docesimplesvermelho ,j*q,i*q,0);
    }
    if ((mapa[i][j]=2)&&(mapa[i][j]=4)){
        al_draw_bitmap(this-> docesimplesverde ,j*q,i*q,0);
    }
    if ((mapa[i][j]=2)&&(mapa[i][j]=5)){
        al_draw_bitmap(this-> docesimplesamarelo ,j*q,i*q,0);
    }
    if ((mapa[i][j]=2)&&(mapa[i][j]=6)){
        al_draw_bitmap(this-> docesimplesazul ,j*q,i*q,0);
    }
    if ((mapa[i][j]=2)&&(mapa[i][j]=1)){
        al_draw_bitmap(this-> docesimpleslaranja ,j*q,i*q,0);
    }

    if ((mapa[i][j]=3)&&(mapa[i][j]=2)){
        al_draw_bitmap(this-> docesimplesverde ,j*q,i*q,0);
    }
    if ((mapa[i][j]=3)&&(mapa[i][j]=3)){
        al_draw_bitmap(this-> docesimplesvermelho ,j*q,i*q,0);
    }
    if ((mapa[i][j]=3)&&(mapa[i][j]=4)){
        al_draw_bitmap(this-> docesimplesverde ,j*q,i*q,0);
    }
    if ((mapa[i][j]=3)&&(mapa[i][j]=5)){
        al_draw_bitmap(this-> docesimplesamarelo ,j*q,i*q,0);
    }
    if ((mapa[i][j]=3)&&(mapa[i][j]=6)){
        al_draw_bitmap(this-> docesimplesazul ,j*q,i*q,0);
    }
    if ((mapa[i][j]=3)&&(mapa[i][j]=1)){
        al_draw_bitmap(this-> docesimpleslaranja ,j*q,i*q,0);
    }

    if ((mapa[i][j]=5)&&(mapa[i][j]=2)){
        al_draw_bitmap(this-> docesimplesverde ,j*q,i*q,0);
    }
    if ((mapa[i][j]=5)&&(mapa[i][j]=3)){
        al_draw_bitmap(this-> docesimplesvermelho ,j*q,i*q,0);
    }
    if ((mapa[i][j]=5)&&(mapa[i][j]=4)){
        al_draw_bitmap(this-> docesimplesverde ,j*q,i*q,0);
    }
    if ((mapa[i][j]=5)&&(mapa[i][j]=5)){
        al_draw_bitmap(this-> docesimplesamarelo ,j*q,i*q,0);
    }
    if ((mapa[i][j]=5)&&(mapa[i][j]=6)){
        al_draw_bitmap(this-> docesimplesazul ,j*q,i*q,0);
    }
    if ((mapa[i][j]=5)&&(mapa[i][j]=1)){
        al_draw_bitmap(this-> docesimpleslaranja ,j*q,i*q,0);
    }

    if ((mapa[i][j]=6)&&(mapa[i][j]=2)){
        al_draw_bitmap(this-> docesimplesverde ,j*q,i*q,0);
    }
    if ((mapa[i][j]=6)&&(mapa[i][j]=3)){
        al_draw_bitmap(this-> docesimplesvermelho ,j*q,i*q,0);
    }
    if ((mapa[i][j]=6)&&(mapa[i][j]=4)){
        al_draw_bitmap(this-> docesimplesverde ,j*q,i*q,0);
    }
    if ((mapa[i][j]=6)&&(mapa[i][j]=5)){
        al_draw_bitmap(this-> docesimplesamarelo ,j*q,i*q,0);
    }
    if ((mapa[i][j]=6)&&(mapa[i][j]=6)){
        al_draw_bitmap(this-> docesimplesazul ,j*q,i*q,0);
    }
    if ((mapa[i][j]=6)&&(mapa[i][j]=1)){
        al_draw_bitmap(this-> docesimpleslaranja ,j*q,i*q,0);
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



