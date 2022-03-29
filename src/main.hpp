#ifndef MAIN_HPP
#define MAIN_HPP

#include "allegro.cpp"
#include "inicializa.hpp"

const float FPS = 10;
const int SCREEN_W = 1650;
const int SCREEN_H = 980;
const int QUAD_SIZE = 20;
const int OFFSETX = 700;
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

ALLEGRO_BITMAP *dlaranja = NULL;
ALLEGRO_BITMAP *droxo = NULL;
ALLEGRO_BITMAP *dverde = NULL;
ALLEGRO_BITMAP *dvermelho = NULL;
ALLEGRO_BITMAP *damarelo = NULL;
ALLEGRO_BITMAP *dazul = NULL;

//--------------auxiliares----------------------//
int Y_click_esq=0;
int X_click_esq=0;

int Y_click_dir=0;
int X_click_dir=0;
int aux_map;

int xtrio[64];
int ytrio[64];

bool vertical=false;
bool horizontal=false;

int moves=0;

bool redraw = true;   
bool sair = false;
bool pressao=false;
int mouse_x, mouse_y;
int MAPA[8][8];
int q = 110;
bool pressao_dir = false;
int definir_numero_de_movimentos_do_nivel = 50;
int keyboardState = 0;
int pontuacao = 0;

int mapaUm[18][7] = {
            0, 2 ,3,0,5,0,0,
            1, 5 ,3,5,6,5,6,
            2, 1 ,6,0,5,3,6,
        
            3, 2 ,5,5,1,2,0,
            3, 5 ,2,1,0,2,1,
            5, 1 ,3,0,0,1,0,
        
            1, 2 ,1,0,1,2,1,
            6, 1 ,2,6,6,5,0,
            6, 3 ,1,3,5,1,2,
            0, 2 ,3,0,5,0,0,
            1, 5 ,3,5,6,5,6,
            2, 1 ,6,0,5,3,6,
        
            3, 2 ,5,5,2,2,0,
            3, 5 ,2,1,6,6,1,
            5, 1 ,3,0,0,1,0,
        
            1, 2 ,1,0,1,2,1,
            6, 1 ,2,6,6,1,0,
            6, 3 ,1,3,5,1,2,
            };

int mapaDois[18][7] = {
            2,2,1,4,4,4,4,
            1,1,2,4,4,4,4,
            2,2,3,4,4,4,4,

            3,3,2,4,4,4,4,
            3,1,6,4,4,4,4,
            1,6,0,4,4,4,4,
            1,1,6,4,4,4,4,
            3,3,1,4,4,4,4,

            2,3,6,4,4,4,4,
            3,2,6,4,4,4,4,
            2,3,3,4,4,4,4,
            1,1,6,4,4,4,4,
            6,6,1,4,4,4,4,

            6,1,5,4,4,4,4,
            1,6,2,4,4,4,4,
            6,1,2,4,4,4,4,
            3,3,1,4,4,4,4,
            1,1,2,4,4,4,4,
};


int jogo(ALLEGRO_EVENT &ev);




#endif