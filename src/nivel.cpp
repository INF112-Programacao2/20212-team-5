#ifndef NIVEL_CPP
#define NIVEL_CPP

#include "main.hpp"
#include "nivel.hpp"
#include "inicializa.hpp"
#include "pontuacao.cpp"
#include "poder.cpp"


#include <iostream> //TEMPORARIO  -- SOMENTE DEBUG

int Mapa::getCoordenada(int x, int i){
    return this->MAPA[x][i];
}

int Nivel::faseUm(ALLEGRO_EVENT &ev){
    Pontos Pontos;
    Doce Doce;
    Mapa Mapa;
    sorteia(Mapa.MAPA);
    pontuacao += Pontos.getPontuacao();
    while(!sair){
            al_wait_for_event(event_queue, &ev);
            
            if(ev.type == ALLEGRO_EVENT_TIMER){
            
                redraw = true;
            }
            else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                sair=true;
                        break;
                    }
            else if(ev.type == ALLEGRO_EVENT_KEY_UP){
                if(ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE){
                        break;
                    }
            }
            else if(ev.type== ALLEGRO_EVENT_MOUSE_AXES){ //SE PASSAR O PONTEIRO EM CIMA DO DISPLAY

                    mouse_x=(ev.mouse.x); //atribui os valores mouse_x e mouse_y ás coordenadas do mouse no display
                    mouse_y=(ev.mouse.y);

            }
            else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
                if(ev.mouse.button & 1){ 
                    pressao=true;  
                    std::cout<<"CLICK"<<std::endl;
                }
            }
            else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    pressao=false;              
            }
            if(redraw && al_is_event_queue_empty(event_queue)){
            
                redraw = false;
                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_bitmap(fundo,0,0,0);
                al_draw_bitmap(mapa,0+OFFSETX,0+OFFSETY,0);
                al_set_mouse_cursor(display, cursor);
                
                Pontos.escrevePontuacao(font);
                Pontos.escreveMovRestantes(font);
                Pontos.escreveObjRestantes(font);


                for (int i=0; i<8; i++){
                    for (int j=0; j<8; j++){
                        switch(Mapa.getCoordenada(i,j)){
                            case 0:
                                Doce.getDoce(1,i,j,q);
                                break;
                            case 1:
                                Doce.getDoce(5,i,j,q); 
                                break;
                            case 2:
                                Doce.getDoce(4,i,j,q);
                                break; 
                            case 3:
                                Doce.getDoce(2,i,j,q);
                                break;
                            case 4:
                                Doce.getDoce(3,i,j,q);
                                break;
                            case 5:
                                Doce.getDoce(5,i,j,q);
                                break;
                    }
                }
                al_flip_display();
            }
    }
}




#endif