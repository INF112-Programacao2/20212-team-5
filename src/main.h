#ifndef MAIN_H
#define MAIN_H

#include "allegro.h"
#include "inicializa.h"

const float FPS = 10;
const int SCREEN_W = 1000;
const int SCREEN_H = 561;
const int QUAD_SIZE = 20;
const int OFFSETX = 500;
const int OFFSETY = 100;

const char *nome = NULL;


ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *menu = NULL;
ALLEGRO_BITMAP *mapa= NULL;
ALLEGRO_BITMAP *mouse=NULL;
ALLEGRO_BITMAP *dlaranja = NULL;
ALLEGRO_BITMAP *droxo = NULL;
ALLEGRO_BITMAP *dverde = NULL;
ALLEGRO_BITMAP *dvermelho = NULL;
ALLEGRO_BITMAP *dazul = NULL;
ALLEGRO_MOUSE_CURSOR *cursor = NULL;



bool redraw = true;   
bool sair = false;
bool pressao=false;
int mouse_x, mouse_y;
int MAPA[8][8];
int q = 62;
int keyboardState = 0;


int jogo(ALLEGRO_EVENT &ev);


#endif