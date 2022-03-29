#ifndef MENU_CPP
#define MENU_CPP

#include "menu.hpp"
#include "nivel.cpp"
#include "inicializa.cpp"


int Menu::mainmenu(){
    /*
        ESTA ESTRUTURA PERMITE O JOGO INICIALIZAR UMA FILA DE EVENTOS QUE PODE SER QUEBRADA SEM DESLIGAR O JOGO
        EXEMPLO: O jogador inicia o tabuleiro e quando mandamos um BREAK na função jogo(), o programa retorna ao menu inicial, por conta da função Main, que está em um loop
    */
    ALLEGRO_EVENT event;                        //INICIA UMA ÚNICA FILA DE EVENTOS
    Pontos EscreverFase;

    Nivel nivel;
    int fase = 0;
    
    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(logo,0,50,0);
    al_draw_bitmap(botao,600,220,0);
    al_draw_bitmap(botao,600,320,0);
    EscreverFase.escreverFase(font, keyboardState);
    

    al_flip_display();
    al_wait_for_event(event_queue, &event);     //ESPERA POR UM EVENTO (No caso da condição abaixo, iniciará o jogo). SE FOR QUEBRADO(receber um break), A CONDIÇÃO RETORNA O PROGRAMA AO MENU INICIAR
    if(event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode==ALLEGRO_KEY_UP){
        if(keyboardState>0){
            keyboardState -= 1;
            EscreverFase.escreverFase(font, keyboardState);
        }
    }
    if(event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode==ALLEGRO_KEY_DOWN){
        if(keyboardState<3){
            keyboardState += 1;
            EscreverFase.escreverFase(font, keyboardState);
        }
    }
    

    if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.button == 1){
        if(keyboardState == 1 /* temporário ->*/ || keyboardState == 3 || keyboardState == 0){
            fase=1;
            
            nivel.faseUm(event, fase);
        }
        if (keyboardState == 2){ fase=2;nivel.faseDois(event, fase);}
    }
    
    
    //if keyboardState == 3 { terceiraFase() }
    //if keyboardState == 4 { quartaFase() }

    else if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode==ALLEGRO_KEY_ESCAPE){
                sair=true;
                return sair;
        }
    }
    
}

#endif