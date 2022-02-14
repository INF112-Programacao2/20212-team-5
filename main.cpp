/*
        Bem vindo ao jogo do Candy Crush SAGA
    Trabalho final de INF112, consiste em recriar o game CandyCrush em C++, disponível para computadores Windows/Linux x64
FLAGS NECESSÁRIAS PARA O COMPILADOR/LINKADOR -> -lallegro -lallegro_image -lallegro_font -lallegro_ttf
*/



#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>   //Importação das funções de FONTE do allegro -> usar junto com 'allegro_ttf.h' para carregar fontes ttf(TrueType Font) 
#include <allegro5/allegro_ttf.h>    //Ao importar esses dois arquivos, adicionar as flags -lallegro_font -lallegro_ttf ao linkador
#include <iostream>
#include <stdlib.h>

using namespace std;

const float FPS = 10;
const int SCREEN_W = 500;
const int SCREEN_H = 550;
const int QUAD_SIZE = 20;


ALLEGRO_COLOR *cor = NULL;        // Ponteiro de COR para a fonte
ALLEGRO_FONT *font = NULL;        // Ponteiro de FONTE para inicializar o objeto
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;



bool sair = false;
bool redraw = true;


int inicializa() {
    
    if(!al_init())
    {
        cout << "Falha ao carregar Allegro" << endl;
        return 0;
    }

    if(!al_install_keyboard())
    {
        cout << "Falha ao inicializar o teclado" << endl;
        return 0;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        cout << "Falha ao inicializar o temporizador" << endl;
        return 0;
    }

    if(!al_init_image_addon())
    {
        cout <<"Falha ao iniciar al_init_image_addon!" << endl;
        return 0;
    }
    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        cout << "Falha ao inicializar a tela" << endl;
        al_destroy_timer(timer);
        return 0;
    }

    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        cout << "Falha ao criar a fila de eventos" << endl;
        al_destroy_display(display);

        return 0;
    }
    al_init_font_addon();    // INICIALIZAR AS FUNÇÕES DE FONTE 
    al_init_ttf_addon();     // INICIALIZAR ESTE ADDON -APÓS- INICIALIZAR O font_addon
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

    return 1;
}

int main(int argc, char **argv)
{
	if(!inicializa()) return -1;
    while(!sair)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

       		
			redraw = false;
            al_clear_to_color(al_map_rgb(0,255,0));

	
			al_flip_display();
        

	}

    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}
