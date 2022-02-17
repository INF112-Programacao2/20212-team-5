/*
                                            Bem vindo ao jogo do Candy Crush SAGA
            Trabalho final de INF112, consiste em recriar o game CandyCrush em C++, disponível para computadores Windows/Linux x64
                    FLAGS NECESSÁRIAS PARA O COMPILADOR/LINKADOR -> -lallegro -lallegro_image -lallegro_font -lallegro_ttf
*/



#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>   
#include <allegro5/allegro_ttf.h>    
#include <iostream>
#include <stdlib.h>

using namespace std;

const float FPS = 10;
const int SCREEN_W = 950;
const int SCREEN_H = 950;
const int QUAD_SIZE = 20;


ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *menu = NULL;
ALLEGRO_BITMAP *mouse=NULL;

bool redraw = true;   
bool sair = false;
bool pressao=false;
int mouse_x, mouse_y;

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

    mouse=al_load_bitmap("CandyCrushResources/personagem.png"); 
    if(!al_install_mouse())
    {
        cout << "Falha ao inicializar o mouse" << endl;
        return 0;
    }



    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        cout << "Falha ao criar a fila de eventos" << endl;
        al_destroy_display(display);

        return 0;
    }
    menu = al_load_bitmap("CandyCrushResources/menu.bmp");
    if(!menu){
        cout << "FALHA AO CARREGAR O MENU" << endl;

        al_destroy_display(display);
        
        return 0;
    }
    //al_init_font_addon();  // marcado para possibilitar a execução
    //al_init_ttf_addon();  //  marcado para possibilitar a execução
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

    return 1;
}


int main(int argc, char **argv){
	if(!inicializa()) return -1;
    while(!sair){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
         if(ev.type == ALLEGRO_EVENT_TIMER)
        {
        
            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
            
            }
        }
	    //<------------------------------------------------------->

        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                sair = true;
                break;
            }
        }
        else if(ev.type== ALLEGRO_EVENT_MOUSE_AXES) //SE PASSAR O PONTEIRO EM CIMA DO DISPLAY
        {
                mouse_x=(ev.mouse.x); //atribui os valores mouse_x e mouse_y ás coordenadas do mouse no display
                mouse_y=(ev.mouse.y);
                

                cout<<mouse_x<<" "<< mouse_y<<endl;
                
                
        }
        else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) //se der o click no mouse
        {
            if(ev.mouse.button & 1){ // &1 = botão esquerdo
                pressao=true;   //pressionado= TRUE
                cout<<"CLICK"<<endl;
            }
             
        }
        else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {       
                pressao=false;              

        }

        al_clear_to_color(al_map_rgb(0,255,0));
        al_draw_bitmap(menu, 0,0,0);
		al_flip_display();

	}

    
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}
