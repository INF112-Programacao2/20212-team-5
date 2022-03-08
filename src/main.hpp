#ifndef MAIN_HPP
#define MAIN_HPP

#include "allegro.h"
#include "inicializa.hpp"

const float FPS = 10;
const int SCREEN_W = 1000;
const int SCREEN_H = 561;
const int QUAD_SIZE = 20;
const int OFFSETX = 500;
const int OFFSETY = 100;

const char *nome = NULL;

const char *FaseUm = "Fase Um";
const char *FaseDois = "Fase Dois";


ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *menu = NULL;
ALLEGRO_BITMAP *mapa= NULL;
ALLEGRO_BITMAP *mouse=NULL;
ALLEGRO_BITMAP *fundo = NULL;
ALLEGRO_BITMAP *logo = NULL;
ALLEGRO_BITMAP *botao = NULL;
ALLEGRO_MOUSE_CURSOR *cursor = NULL;
ALLEGRO_FONT *font = NULL;

//pecas
ALLEGRO_BITMAP *docesimplesamarelo = NULL;
ALLEGRO_BITMAP *docesimplesazul = NULL;
ALLEGRO_BITMAP *docesimpleslaranja = NULL;
ALLEGRO_BITMAP *docesimplesroxo = NULL;
ALLEGRO_BITMAP *docesimplesverde = NULL;
ALLEGRO_BITMAP *docesimplesvermelho = NULL;

//bomba relogio
ALLEGRO_BITMAP *bombarelogioamarelo = NULL;
ALLEGRO_BITMAP *bombarelogioazul = NULL;
ALLEGRO_BITMAP *bombarelogiolaranja = NULL;
ALLEGRO_BITMAP *bombarelogioroxo = NULL;
ALLEGRO_BITMAP *bombarelogioverde = NULL;
ALLEGRO_BITMAP *bombarelogiovermelho = NULL;

//especial horizontal
ALLEGRO_BITMAP *especialhorizontalamarelo = NULL;
ALLEGRO_BITMAP *especialhorizontalazul = NULL;
ALLEGRO_BITMAP *especialhorizontallaranja = NULL;
ALLEGRO_BITMAP *especialhorizontalroxo = NULL;
ALLEGRO_BITMAP *especialhorizontalverde = NULL;
ALLEGRO_BITMAP *especialhorizontalvermelho = NULL;

//especial vertical
ALLEGRO_BITMAP *especialverticalamarelo = NULL;
ALLEGRO_BITMAP *especialverticalazul = NULL;
ALLEGRO_BITMAP *especialverticallaranja = NULL;
ALLEGRO_BITMAP *especialverticalroxo = NULL;
ALLEGRO_BITMAP *especialverticalverde = NULL;
ALLEGRO_BITMAP *especialverticalvermelho = NULL;

//pacote fish
ALLEGRO_BITMAP *pacotefishamarelo = NULL;
ALLEGRO_BITMAP *pacotefishazul = NULL;
ALLEGRO_BITMAP *pacotefishlaranja = NULL;
ALLEGRO_BITMAP *pacotefishroxo = NULL;
ALLEGRO_BITMAP *pacotefishverde = NULL;
ALLEGRO_BITMAP *pacotefishvermelho = NULL;

//peixe especial
ALLEGRO_BITMAP *peixeespecialamarelo = NULL;
ALLEGRO_BITMAP *peixeespecialazul = NULL;
ALLEGRO_BITMAP *peixeespeciallaranja = NULL;
ALLEGRO_BITMAP *peixeespecialroxo = NULL;
ALLEGRO_BITMAP *peixeespecialverde = NULL;
ALLEGRO_BITMAP *peixeespecialvermelho = NULL;

//especiais
ALLEGRO_BITMAP *rosquinharosaespecial = NULL;
ALLEGRO_BITMAP *brigadeiroespecial= NULL;


bool redraw = true;   
bool sair = false;
bool pressao=false;
int mouse_x, mouse_y;
int MAPA[8][8];
int q = 62;
int keyboardState = 0;
int pontuacao = 0;

int jogo(ALLEGRO_EVENT &ev);


#endif