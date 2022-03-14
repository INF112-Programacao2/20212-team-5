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

const float FPS = 2;
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


bool redraw = true;   
bool sair = false;
bool pressao=false;
bool pressao_dir=false;
int mouse_x, mouse_y;

//--------------auxiliares----------------------//
int Y_click_esq=0;
int X_click_esq=0;

int Y_click_dir=0;
int X_click_dir=0;
int aux_map;

int xtrio[64];
int ytrio[64];



int pontos=0;
int k=0;
//-------------------------------------------//
 


//INICIALIZANDO O MAPA 
int MAPA[8][8]={
    0,1,2,0,0,1,1,2,
    1,2,1,0,1,2,1,2,
    2,0,0,1,0,2,2,0,
    0,1,2,0,0,1,1,2,
    1,2,1,0,1,2,1,2,
    2,0,0,1,0,2,2,0,
    0,1,2,0,0,1,1,2,
    1,2,1,0,1,2,1,2,

};




int q = 62;   
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

    mapa = al_load_bitmap("tab.bmp");
    if(!mapa)
    {
        cout << "Falha ao carregar o mapa!" << endl;
        al_destroy_display(display);
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
    dlaranja = al_load_bitmap("dlaranja.tga"); //carrega a imagem da cabeca
	if(!dlaranja)
    {
        cout << "Falha ao carregar o doce laranja!" << endl;
        al_destroy_display(display);
        return 0;
    }

    
    droxo = al_load_bitmap("droxo.tga"); //carrega a imagem da cabeca
	if(!droxo)
    {
        cout << "Falha ao carregar o doce roxo" << endl;
        al_destroy_display(display);
        return 0;
    }

    dverde = al_load_bitmap("dverde.tga"); //carrega a imagem da cabeca
	if(!droxo)
    {
        cout << "Falha ao carregar o doce verde" << endl;
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
        }
        else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) //se der o click no mouse
        {
            if(ev.mouse.button & 1){ // &1 = botão esquerdo
                pressao=true;   //pressionado= TRUE
                if(pressao==true){
                   
                   Y_click_esq=mouse_y/q;  //auxiliar guarda a coordenada X do último click;*
        
                   X_click_esq=mouse_x/q; //auxiliar guarda a coordenada X do último click; *   
                }
                
                
            }
            if(ev.mouse.button & 2){ // &1 = botão direito
                
                pressao_dir=true;   //Se pressionar o botão direito, pressão dir= true
                
                if(pressao_dir==true){  
                    
                    Y_click_dir=mouse_y/q;
                    X_click_dir=mouse_x/q;
                    
                    if(abs(Y_click_esq - Y_click_dir)==1 || abs(X_click_esq-X_click_dir)==1 ){ //verifica se a diferença entre o primeiro click e o segundo click ==1;
                        if(!(abs(Y_click_esq - Y_click_dir)==1 & abs(X_click_esq-X_click_dir)==1)){ //verifica se o segundo clkick está na diagonal, se as 2 coordenadas mudam ao mesmo tempo;
                            
                            
                            aux_map=MAPA[Y_click_esq][X_click_esq];       
                            MAPA[Y_click_esq][X_click_esq]=MAPA[Y_click_dir][X_click_dir];//posição do click esquerdo vai ser igual a posição do click direito;*
                            MAPA[Y_click_dir][X_click_dir]=aux_map;//posição do click direito vai ser igual a posição do auxiliar*
                            
                            cout<<"OK"<<endl;

                           
                        }
                        else{
                        cout<<"Não"<<endl;
                        }
                    }
                    
                    cout<<"pontos: "<<pontos<<endl;
                   
                }




            } 
        }
        else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {       
                pressao=false;
                pressao_dir=false;
                              

        }
        if(redraw && al_is_event_queue_empty(event_queue)) //se REDRAW (redesenhar for true e a fila estiver vazia)
        {
            redraw = false;

            al_clear_to_color(al_map_rgb(0,0,0));
            
            al_draw_bitmap(mapa,0,0,0);
            
            //al_draw_bitmap(dlaranja,mouse_x,mouse_y,0); //vai desenhar uma peça laranha no mouse, apenas para teste nao achei um ponteiro top ainda kkkkkk
    

    //SPAWN DAS PEÇAS 
            for (int i=0; i<8; i++){
                for (int j=0; j<8; j++){
                     int auxteste;
                    if(MAPA[i][j]==0){ //Se for 0, desenha a peça laranha
                        al_draw_bitmap(dlaranja,j*q,i*q,0);
                        
                    }
                    if(MAPA[i][j]==1){ //Se for 1, desenha a peça roxa;
                       al_draw_bitmap(droxo,j*q,i*q,0); //função desenha
                    }
                    

                    if(MAPA[i][j]==2){//Se for 2, desenha a peça verde;
                        al_draw_bitmap(dverde,j*q,i*q,0); //função desenha
                    }

                    
                   
                    
            }



        }
       
            
        al_flip_display();
    
        }
    }

        al_clear_to_color(al_map_rgb(0,255,0));
        al_draw_bitmap(menu, 0,0,0);
		al_flip_display();

	

    al_destroy_bitmap(dlaranja);
    al_destroy_bitmap(droxo);
    al_destroy_bitmap(dverde);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    
    return 0;
}
