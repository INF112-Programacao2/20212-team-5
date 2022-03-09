#ifndef PONTUACAO_HPP
#define PONTUACAO_HPP

#include "allegro.cpp"
#include "pontuacao.hpp"


/* Pontuação geral */
int Pontos::getPontuacao(){
    int pontuacao = this->pontuacao;
    return pontuacao;
}

void Pontos::setPontuacao(int i){
    this->pontuacao = i;
}

void Pontos::aumentarPontuacao(int i){
    this->pontuacao += i;
}

void Pontos::diminuirPontuacao(int i){
    this->pontuacao -= i;
}

/* Objetivos restantes */
int Pontos::getObjRestantes(){
    return this->objrestantes;
}

void Pontos::setObjRestantes(int i){
    this->objrestantes = i;
}

void Pontos::aumentarObjRestantes(){
    this->objrestantes += 1;
}

void Pontos::diminuirObjRestantes(){
    this->objrestantes -= 1;
}

/* Movimentos restantes */

int Pontos::getMovRestantes(){
    return this->movRestantes;
}

void Pontos::setMovRestantes(int i){
    this->movRestantes = i;
}

void Pontos::aumentarMovRestantes(){
    this->movRestantes += 1;
}

void Pontos::diminuirMovRestantes(){
    this->movRestantes -= 1;
}

void Pontos::escrevePontuacao(ALLEGRO_FONT *font){
    al_draw_textf(font, al_map_rgb(255,0,0),330,520, 0, "%d", this->pontuacao);   
}

void Pontos::escreveObjRestantes(ALLEGRO_FONT *font){
    al_draw_textf(font, al_map_rgb(255,0,0),300,520, 0, "%d", this->objrestantes);   
}

void Pontos::escreveMovRestantes(ALLEGRO_FONT *font){
    al_draw_textf(font, al_map_rgb(255,0,0),220,520, 0, "%d", this->movRestantes);   
}




#endif 