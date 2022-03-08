#ifndef PONTUACAO_HPP
#define PONTUACAO_HPP

#include "allegro.cpp"
#include "pontuacao.hpp"



int Pontos::getPontuacao(){
    int pontuacao = this->pontuacao;
    return pontuacao;
}

int Pontos::addPontuacao(int i){
    this->pontuacao += i;
    return this->pontuacao;
}

void Pontos::removePontuacao(int i){
    this->pontuacao -= i;
}

int Pontos::getObjRestantes(){
    return this->objrestantes;
}

void Pontos::setObjRestantes(int i){
    this->objrestantes = i;
}

void Pontos::diminuirObjRestantes(){
    this->objrestantes -= 1;
}

void Pontos::aumentarObjRestantes(){
    this->objrestantes += 1;
}

void Pontos::escrevePontuacao(ALLEGRO_FONT *font){
    al_draw_textf(font, al_map_rgb(255,0,0),330,520, 0, "%d", this->pontuacao);   
}

void Pontos::escreveObjRestantes(ALLEGRO_FONT *font){
    al_draw_textf(font, al_map_rgb(255,0,0),330,520, 0, "%d", this->pontuacao);   
}

void Pontos::escreveMovRestantes(ALLEGRO_FONT *font){
    al_draw_textf(font, al_map_rgb(255,0,0),330,520, 0, "%d", this->pontuacao);   
}



#endif 