#ifndef NIVEL_CPP
#define NIVEL_CPP

#include "main.h"
#include "nivel.hpp"
#include "pontuacao.cpp"
#include <iostream> //TEMPORARIO  -- SOMENTE DEBUG

int Nivel::faseUm(ALLEGRO_EVENT &ev){
    Pontos Pontos;
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
                al_draw_bitmap(mapa,0+OFFSETX,0+OFFSETY,0);
                al_set_mouse_cursor(display, cursor);
                

                for (int i=0; i<8; i++){
                    for (int j=0; j<8; j++){
                        if(MAPA[i][j]==0){ //Se for 0, desenha a peça laranha
                            al_draw_bitmap(dlaranja,j*q,i*q,0);//função desenha
                        }
                        if(MAPA[i][j]==1){ //Se for 1, desenha a peça roxa;
                           al_draw_bitmap(droxo,j*q,i*q,0); //função desenha
                        }
                        //if(mouse_y/q==i && mouse_x/q==j && pressao==true){ //Se a posição do mouse for a mesma da peça desenhada---->desenha a peça laranja (testando)
                        //        al_draw_bitmap(dlaranja,(j*q)+OFFSETX+3,(i*q)+OFFSETY+3,0);
                        //   }
                        //}
                        if(MAPA[i][j]==2){//Se for 2, desenha a peça verde;
                            al_draw_bitmap(dverde,j*q,i*q,0); //função desenha
                            
                        }
                        if(MAPA[i][j]==3){//Se for 2, desenha a peça verde;
                            al_draw_bitmap(dvermelho,j*q,i*q,0); //função desenha
                        }
                        if(MAPA[i][j]==4){//Se for 2, desenha a peça verde;
                            al_draw_bitmap(dazul,j*q,i*q,0); //função desenha
                        }
                        //    if(mouse_y/q==i && mouse_x/q==j && pressao==true){ //Se a posição do mouse for a mesma da peça desenhada---->desenha a peça laranja (testando)
                        //        al_draw_bitmap(dlaranja,(j*q)+OFFSETX+3,(i*q)+OFFSETY+3,0);
                        //    }                        
                        
                    }
                }
                al_draw_textf(font, al_map_rgb(255,0,0),330,520, 0, "%d", pontuacao);
		    	//al_draw_bitmap(dlaranja,j*q,i*q,0); //desenha a cabeca da cobra
                al_flip_display();

            }
    }
}

#endif