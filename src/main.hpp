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

ALLEGRO_BITMAP *telaPause = NULL;
ALLEGRO_BITMAP *botaoSim = NULL;
ALLEGRO_BITMAP *botaoNao = NULL;
ALLEGRO_BITMAP *fasesJogo = NULL;
ALLEGRO_SAMPLE *musica = NULL;
ALLEGRO_SAMPLE_INSTANCE *inst_musica = NULL;

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

//referente a poder
ALLEGRO_BITMAP *Pirulito = NULL;
ALLEGRO_BITMAP *fundosugar = NULL;
ALLEGRO_BITMAP *Festa = NULL;
ALLEGRO_BITMAP *fundorosa = NULL;
ALLEGRO_BITMAP *Maozinha = NULL;
ALLEGRO_BITMAP *Muda1 = NULL;
ALLEGRO_BITMAP *Nave = NULL;

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


int jogo(ALLEGRO_EVENT &ev);




#endif