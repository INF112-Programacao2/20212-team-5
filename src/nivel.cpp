#ifndef NIVEL_CPP
#define NIVEL_CPP

#include "main.hpp"
#include "nivel.hpp"
#include "pontuacao.cpp"
#include "poder.cpp"
#include "mapa.cpp"


#include <iostream> //TEMPORARIO  -- SOMENTE DEBUG


int Nivel::faseUm(ALLEGRO_EVENT &ev, int fase){
    Pontos Pontos;
    Doce Doce;

    Mapa Mapa;
    Mapa.setCoordenada(1);
    //sorteia(Mapa.MAPA);

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
                    if(pressao==true){
                        //cout<<Y_click_esq<<"OLHAesq "<< X_click_esq<<endl;
                       Y_click_esq=mouse_y/q+9;  //auxiliar guarda a coordenada X do último click;*

                       X_click_esq=mouse_x/q+1; //auxiliar guarda a coordenada X do último click; *   
                    }


                }
                if(ev.mouse.button & 2){ // &1 = botão direito  
                    pressao_dir=true;   //Se pressionar o botão direito, pressão dir= true

                        if(pressao_dir==true){  
                        
                            Y_click_dir=mouse_y/q+9; //2 adicionado ÀS 09:47
                            X_click_dir=mouse_x/q+1;
                            Mapa.funcao_troca_doces(Y_click_esq,X_click_esq,Y_click_dir,X_click_dir, Pontos);


                        }

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
                Pontos.escreverFase(font,fase);


                for (int i=11; i<17; i++){
                    for (int j=0; j<7; j++){
                        if(Mapa.getCoordenada(i,j)==0){
                            Doce.getDoce(0,i,j,q); 
                        }
                        if(Mapa.getCoordenada(i,j)==1){
                            Doce.getDoce(1,i,j,q);
                        }
                        if(Mapa.getCoordenada(i,j)==2){
                            Doce.getDoce(2,i,j,q);
                        }
                        if(Mapa.getCoordenada(i,j)==3){
                            Doce.getDoce(3,i,j,q);
                        }
                        if(Mapa.getCoordenada(i,j)==4){
                            Doce.getDoce(4,i,j,q);
                        } 
                        if(Mapa.getCoordenada(i,j)==5){
                            Doce.getDoce(5,i,j,q);
                        }
                        if(Mapa.getCoordenada(i,j)==6){
                            Doce.getDoce(6,i,j,q);
                        }
                        Mapa.funcao_check_5(i, j, Pontos);
                        Mapa.funcao_check_4(i, j, Pontos);
                        Mapa.funcao_check_3(i, j, Pontos);
                        
                    }
                }
                
                al_flip_display();

            }
    }
}

int Nivel::faseDois(ALLEGRO_EVENT &ev, int fase){
    Pontos Pontos;
    Doce Doce;

    Mapa Mapa;
    //sorteia(Mapa.MAPA);
    Mapa.setCoordenada(2);
    pontuacao += Pontos.getPontuacao();
    while(!sair){
        al_wait_for_event(event_queue, &ev);
         if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                sair=true;
                    Mapa.clearCoordenada();
                        break;
                    }
            else if(ev.type == ALLEGRO_EVENT_KEY_UP){
                if(ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE){
                        Mapa.clearCoordenada();
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
                    //cout<<Y_click_esq<<"OLHAesq "<< X_click_esq<<endl;
                   Y_click_esq=mouse_y/q+11;  //auxiliar guarda a coordenada X do último click;*
                   X_click_esq=mouse_x/q-6; //auxiliar guarda a coordenada X do último click; *   

                }


            }
            if(ev.mouse.button & 2){ // &1 = botão direito

                pressao_dir=true;   //Se pressionar o botão direito, pressão dir= true

                if(pressao_dir==true){  

                    Y_click_dir=mouse_y/q+11; //2 adicionado ÀS 09:47
                    X_click_dir=mouse_x/q-6;

                    Mapa.funcao_troca_doces(Y_click_esq,X_click_esq,Y_click_dir,X_click_dir,Pontos);
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
            al_draw_bitmap(fundo,0,0,0);
            al_draw_bitmap(mapa,0+OFFSETX,0+OFFSETY,0);
            al_set_mouse_cursor(display, cursor);
            //al_draw_bitmap(mapa,700,100,0);
                Pontos.escrevePontuacao(font);
                Pontos.escreveMovRestantes(font);
                Pontos.escreveObjRestantes(font);
                Pontos.escreverFase(font,fase);


                for (int i=11; i<17; i++){
                    for (int j=0; j<7; j++){
                        if(Mapa.getCoordenada(i,j)==0){
                            Doce.getDoce(0,i,j,q); 
                        }
                        if(Mapa.getCoordenada(i,j)==1){
                            Doce.getDoce(1,i,j,q);
                        }
                        if(Mapa.getCoordenada(i,j)==2){
                            Doce.getDoce(2,i,j,q);
                        }
                        if(Mapa.getCoordenada(i,j)==3){
                            Doce.getDoce(3,i,j,q);
                        }
                        if(Mapa.getCoordenada(i,j)==4){
                            Doce.getDoce(4,i,j,q);
                        } 
                        if(Mapa.getCoordenada(i,j)==5){
                            Doce.getDoce(5,i,j,q);
                        }
                        if(Mapa.getCoordenada(i,j)==6){
                            Doce.getDoce(6,i,j,q);
                        }
                        Mapa.funcao_check_5(i, j, Pontos);
                        Mapa.funcao_check_4(i, j, Pontos);
                        Mapa.funcao_check_3(i, j, Pontos);
                        
                    }
                }
        al_flip_display();
        } 
    }
}

#endif