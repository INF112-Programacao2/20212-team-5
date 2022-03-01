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

#include "teste.h"

const float FPS = 10;
const int SCREEN_W = 950;
const int SCREEN_H = 950;
const int QUAD_SIZE = 20;


ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *menu = NULL;
ALLEGRO_BITMAP *mapa= NULL;
ALLEGRO_BITMAP *mouse=NULL;
ALLEGRO_BITMAP *dlaranja = NULL;
ALLEGRO_BITMAP *droxo = NULL;
ALLEGRO_BITMAP *dverde = NULL;
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

int inicializa() {
    
    if(!al_init())
    {
        std::cout << "Falha ao carregar Allegro" << std::endl;
        return 0;
    }

    if(!al_install_keyboard())
    {
        std::cout << "Falha ao inicializar o teclado" << std::endl;
        return 0;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        std::cout << "Falha ao inicializar o temporizador" << std::endl;
        return 0;
    }

    if(!al_init_image_addon())
    {
        std::cout <<"Falha ao iniciar al_init_image_addon!" << std::endl;
        return 0;
    }
    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        std::cout << "Falha ao inicializar a tela" << std::endl;
        al_destroy_timer(timer);
        return 0;
    }

    mapa = al_load_bitmap("CandyCrushRecursos/tab.bmp");
    if(!mapa)
    {
        std::cout << "Falha ao carregar o mapa!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    mouse=al_load_bitmap("CandyCrushRecursos/personagem.png"); 
    if(!al_install_mouse())
    {
        std::cout << "Falha ao inicializar o mouse" << std::endl;
        return 0;
    }



    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        std::cout << "Falha ao criar a fila de eventos" << std::endl;
        al_destroy_display(display);

        return 0;
    }
    menu = al_load_bitmap("CandyCrushRecursos/menu.bmp");
    if(!menu){
        std::cout << "FALHA AO CARREGAR O MENU" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }
    dlaranja = al_load_bitmap("CandyCrushRecursos/dlaranja.tga"); //carrega a imagem da cabeca
	if(!dlaranja)
    {
        std::cout << "Falha ao carregar o doce laranja!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    
    droxo = al_load_bitmap("CandyCrushRecursos/droxo.tga"); //carrega a imagem da cabeca
	if(!droxo)
    {
        std::cout << "Falha ao carregar o doce roxo" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    dverde = al_load_bitmap("CandyCrushRecursos/dverde.tga"); //carrega a imagem da cabeca
	if(!droxo)
    {
        std::cout << "Falha ao carregar o doce verde" << std::endl;
        al_destroy_display(display);
        return 0;
    }

     Pirulito = al_load_bitmap("Pirulito.bmp");
    if(!Pirulito)
    {
        std::cout << "Falha ao carregar o pirulo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    fundosugar = al_load_bitmap("fundosugar.bmp");
    if(!fundosugar)
    {
        std::cout << "Falha ao carregar o Fundo do doce!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    Festa = al_load_bitmap("Festa.bmp");
    if(!Festa)
    {
        std::cout << "Falha ao carregar ajuda festa!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    fundorosa = al_load_bitmap("fundorosa.bmp");
    if(!fundorosa)
    {
        std::cout << "Falha ao carregar fundo das ajudas!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    Maozinha = al_load_bitmap("Maozinha.bmp");
    if(!Maozinha)
    {
        std::cout << "Falha ao carregar ajuda mao!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    Muda1 = al_load_bitmap("Muda1.bmp");
    if(!Muda1)
    {
        std::cout << "Falha ao carregar ajuda que muda os doces!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    Nave = al_load_bitmap("Nave.bmp");
    if(!Nave)
    {
        std::cout << "Falha ao carregar ajuda nave!" << std::endl;
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
int jogo(ALLEGRO_EVENT &ev){
    
    while(!sair){
            al_wait_for_event(event_queue, &ev);
            if(ev.type == ALLEGRO_EVENT_TIMER){
            
                redraw = true;
            }
	        //<------------------------------------------------------->
            else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                        break;
                    }
            else if(ev.type == ALLEGRO_EVENT_KEY_UP){
                switch(ev.keyboard.keycode){
                    case ALLEGRO_KEY_ESCAPE:
                        sair = true;
                        break;
                    }
            }
            else if(ev.type== ALLEGRO_EVENT_MOUSE_AXES){ //SE PASSAR O PONTEIRO EM CIMA DO DISPLAY

                    mouse_x=(ev.mouse.x); //atribui os valores mouse_x e mouse_y ás coordenadas do mouse no display
                    mouse_y=(ev.mouse.y);


                    std::cout<<mouse_x<<" "<< mouse_y<<std::endl;
            }
            else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ //se der o click no mouse
                if(ev.mouse.button & 1){ // &1 = botão esquerdo
                    pressao=true;   //pressionado= TRUE
                    std::cout<<"CLICK"<<std::endl;
                }

            }
            else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_UP){
         
                    pressao=false;              

            }
            if(redraw && al_is_event_queue_empty(event_queue)){ //se REDRAW (redesenhar for true e a fila estiver vazia)
            
                redraw = false;

                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_bitmap(mapa,0,0,0);
                al_draw_bitmap(dlaranja,mouse_x,mouse_y,0); //vai desenhar uma peça laranha no mouse, apenas para teste nao achei um ponteiro top ainda kkkkkk
                al_draw_bitmap(Pirulito,0,0,2); 
                al_draw_bitmap(fundosugar,0,0,6); 
                al_draw_bitmap(Festa,0,0,8); 
                al_draw_bitmap(fundorosa,0,0,10); 
                al_draw_bitmap(Maozinha,0,0,12); 
                al_draw_bitmap(Muda1,0,0,14); 
                al_draw_bitmap(Nave,0,0,16); 

                for (int i=0; i<8; i++){
                    for (int j=0; j<8; j++){
                        if(MAPA[i][j]==0){ //Se for 0, desenha a peça laranha
                            al_draw_bitmap(dlaranja,j*q,i*q,0);//função desenha
                        }
                        if(MAPA[i][j]==1){ //Se for 1, desenha a peça roxa;
                           al_draw_bitmap(droxo,j*q,i*q,0); //função desenha

                           if(mouse_y/q==i && mouse_x/q==j && pressao==true){ //Se a posição do mouse for a mesma da peça desenhada---->desenha a peça laranja (testando)
                                al_draw_bitmap(dlaranja,j*q,i*q,0);
                           }
                        }
                        if(MAPA[i][j]==2){//Se for 2, desenha a peça verde;
                            al_draw_bitmap(dverde,j*q,i*q,0); //função desenha
                            if(mouse_y/q==i && mouse_x/q==j && pressao==true){ //Se a posição do mouse for a mesma da peça desenhada---->desenha a peça laranja (testando)
                                al_draw_bitmap(dlaranja,j*q,i*q,0);
                            }                        
                        }
                    }
                }
		    	//al_draw_bitmap(dlaranja,j*q,i*q,0); //desenha a cabeca da cobra
                al_flip_display();

            }
    }
}

int desinicializa(){
    al_destroy_bitmap(mapa);
    al_destroy_bitmap(mouse);
    al_destroy_bitmap(dlaranja);
    al_destroy_bitmap(droxo);
    al_destroy_bitmap(dverde);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_bitmap(Pirulito);
    al_destroy_bitmap(fundorosa);
    al_destroy_bitmap(Festa);
    al_destroy_bitmap(fundosugar);
    al_destroy_bitmap(Maozinha);
    al_destroy_bitmap(Muda1);
    al_destroy_bitmap(Nave);
    return 0;
}

int mainmenu(){
    
    ALLEGRO_EVENT event;
    al_draw_bitmap(menu,0,0,0);
    al_flip_display();
    al_wait_for_event(event_queue, &event);
    if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.button == 1){
        jogo(event);
    }
    
}


int main(int argc, char **argv){
	if(!inicializa()) return -1;
    while(!sair){
        mainmenu();
    }
    
    
    desinicializa();
                
    
    return 0;
}