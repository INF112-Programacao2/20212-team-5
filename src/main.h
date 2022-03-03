#ifndef MAIN_H
#define MAIN_H

const float FPS = 10;
const int SCREEN_W = 950;
const int SCREEN_H = 950;
const int QUAD_SIZE = 20;
const int OFFSETX = 240;
const int OFFSETY = 210;
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
ALLEGRO_MOUSE_CURSOR *cursor = NULL;
ALLEGRO_BITMAP *Pirulito = NULL;
ALLEGRO_BITMAP *fundosugar = NULL;
ALLEGRO_BITMAP *Festa = NULL;
ALLEGRO_BITMAP *fundorosa = NULL;
ALLEGRO_BITMAP *Maozinha = NULL;
ALLEGRO_BITMAP *Muda1 = NULL;
ALLEGRO_BITMAP *Nave = NULL;

bool redraw = true;   
bool sair = false;
bool pressao=false;
int mouse_x, mouse_y;
int MAPA[8][8];
int q = 62;
int keyboardState = 0;


int inicializa();
int jogo(ALLEGRO_EVENT &ev);
int desinicializa();
int mainmenu();


#endif