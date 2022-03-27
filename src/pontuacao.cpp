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

/* Funções de escrita */
void Pontos::escrevePontuacao(ALLEGRO_FONT *font){
    al_draw_textf(font, al_map_rgb(255,0,0),800,720, 0, "Pontuação:");
    al_draw_textf(font, al_map_rgb(255,0,0),1300,720, 0, "%d", this->pontuacao);   
}

void Pontos::escreveObjRestantes(ALLEGRO_FONT *font){
    al_draw_textf(font, al_map_rgb(255,0,0),800,780, 0, "Objetivos Restantes:");
    al_draw_textf(font, al_map_rgb(255,0,0),1300,780, 0, "%d", this->objrestantes);   
}

void Pontos::escreveMovRestantes(ALLEGRO_FONT *font){
    al_draw_textf(font, al_map_rgb(255,0,0),800,820, 0, "Movimentos Restantes:");
    al_draw_textf(font, al_map_rgb(255,0,0),1300,820, 0, "%d", this->movRestantes);   
}

void PontosDoce::pontosDoce(int escolha, int multiplicador){
    switch(escolha){
        case 0:
            Pontos::aumentarPontuacao((this->pontosDoces[0])*this->multiplicador[multiplicador]);
            break;
        case 1:
            Pontos::aumentarPontuacao((this->pontosDoces[1])*this->multiplicador[multiplicador]);
            break;
        case 2:
            Pontos::aumentarPontuacao((this->pontosDoces[2])*this->multiplicador[multiplicador]);
            break;
        case 3:
            Pontos::aumentarPontuacao((this->pontosDoces[3])*this->multiplicador[multiplicador]);
            break;
        case 4:
            Pontos::aumentarPontuacao((this->pontosDoces[4])*this->multiplicador[multiplicador]);
            break;
    } 
}




#endif 