#ifndef MENU_CPP
#define MENU_CPP

#include "menu.hpp"
#include "nivel.cpp"
#include "inicializa.cpp"


int mainmenu(){
    /*
        ESTA ESTRUTURA PERMITE O JOGO INICIALIZAR UMA FILA DE EVENTOS QUE PODE SER QUEBRADA SEM DESLIGAR O JOGO
        EXEMPLO: O jogador inicia o tabuleiro e quando mandamos um BREAK na função jogo(), o programa retorna ao menu inicial, por conta da função Main, que está em um loop
    */
    ALLEGRO_EVENT event;                        //INICIA UMA ÚNICA FILA DE EVENTOS
    Nivel nivel;
    
    int botao_x = 600;
    int botao1_y = 220;
    int botao2_y = 320;
    

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(logo,0,50,0);
    al_draw_bitmap(botao,botao_x,botao1_y,0);
    al_draw_bitmap(botao,botao_x,botao2_y,0);
    

    al_flip_display();
    al_wait_for_event(event_queue, &event);     //ESPERA POR UM EVENTO (No caso da condição abaixo, iniciará o jogo). SE FOR QUEBRADO(receber um break), A CONDIÇÃO RETORNA O PROGRAMA AO MENU INICIAR
    if(event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode==ALLEGRO_KEY_UP){
        if(keyboardState<3){
            keyboardState += 1;
        }
    }
    if(event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode==ALLEGRO_KEY_DOWN){
        if(keyboardState>0){
            keyboardState -= 1;
        }
    }

    if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.button == 1){
        /* if (mouse_x >= botao_x &&
            mouse_x <= botao_x + al_get_bitmap_width(botao)-30 &&
            mouse_y >= botao1_y &&
            mouse_y <= botao1_y + al_get_bitmap_height(botao)-30)  mapeando primeiro botão, para ser o "INICIAR"*/
        std::cout << "Click no menu!" << std::endl;
        if(keyboardState == 1 /* temporário ->*/ || keyboardState == 2 || keyboardState == 3 || keyboardState == 0){
        sorteia(MAPA);
        nivel.faseUm(event);
        }
    }
    //if keyboardState == 2 { segundaFase() }
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
