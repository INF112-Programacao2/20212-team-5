#include "menu.hpp"
#include "main.hpp"
#include "nivel.cpp"
#include "inicializa.cpp"


void Menu::mainmenu(){
    /*
        ESTA ESTRUTURA PERMITE O JOGO INICIALIZAR UMA FILA DE EVENTOS QUE PODE SER QUEBRADA SEM DESLIGAR O JOGO
        EXEMPLO: O jogador inicia o tabuleiro e quando mandamos um BREAK na função jogo(), o programa retorna ao menu inicial, por conta da função Main, que está em um loop
    */
    ALLEGRO_EVENT event;                        //INICIA UMA ÚNICA FILA DE EVENTOS
    Nivel nivel;
    
    int botao_x = 600; //coordenada x do botao
    int botao1_y = 220; // coordenada y do botao
    int botao2_y = 320;
    

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(logo,0,50,0);
    al_draw_bitmap(botao,botao_x,botao1_y,0);
    al_draw_bitmap(botao,botao_x,botao2_y,0);

    al_draw_text ( font, al_map_rgb(0,0,0) , botao_x+35, botao1_y+7, 0, "Iniciar");
    al_draw_text ( font, al_map_rgb(0,0,0) , botao_x+30, botao2_y+7, 0, "Config.");
    

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
    //Encerra o Jogo ao clicar no x da janela
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        sair=true;
    }
    
    if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
        //Botao Iniciar
        if (event.mouse.button == 1 && 
            event.mouse.x  > botao_x &&
            event.mouse.x  < (botao_x + al_get_bitmap_width(botao)) &&
            event.mouse.y > botao1_y &&
            event.mouse.y < (botao1_y + al_get_bitmap_height(botao))){
            /* std::cout << "Click no iniciar!" << std::endl; */

            if(keyboardState == 1 /* temporário ->*/ || keyboardState == 2 || keyboardState == 3 || keyboardState == 0){
                //sorteia(MAPA);
                nivel.faseUm(event);
            }
        }
            //if keyboardState == 2 { segundaFase() }
            //if keyboardState == 3 { terceiraFase() }
            //if keyboardState == 4 { quartaFase() }

        //Botao Configurações
        if (event.mouse.button == 1 && 
            event.mouse.x > botao_x &&
            event.mouse.x < (botao_x + al_get_bitmap_width(botao)) &&
            event.mouse.y > botao2_y &&
            event.mouse.y < (botao2_y + al_get_bitmap_height(botao))){  
            std::cout << "Click no Configurações!" << std::endl;
        }
    }

    else if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode==ALLEGRO_KEY_ESCAPE){
                std::cout << "Aparecer tela de Pause" << std::endl;
                this->pausarMenu();
        }
    }
    
}

void Menu::pausarMenu(){
    ALLEGRO_EVENT event;

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(telaPause,  al_get_bitmap_width(fundo)/2 - al_get_bitmap_height(telaPause)/2,
                    al_get_bitmap_height(fundo)/2 - al_get_bitmap_width(telaPause)/2, 0);
    al_draw_bitmap(botaoSim, SCREEN_W/2+50, SCREEN_H/2, 0);
    al_draw_bitmap(botaoNao, SCREEN_W/2-100, SCREEN_H/2, 0);

    al_draw_text (font, al_map_rgb(0,0,0) , SCREEN_W/2-40, SCREEN_H/2-50 ,0, "Deseja sair?");

    al_flip_display();

    
    while(1){
        al_wait_for_event(event_queue, &event);

        //Botao Sim para sair do jogo
        if (event.mouse.button == 1 && 
            event.mouse.x > SCREEN_W/2+50 &&
            event.mouse.x < (SCREEN_W/2+50 + al_get_bitmap_width(botaoSim)) &&
            event.mouse.y > SCREEN_H/2 &&
            event.mouse.y < (SCREEN_H/2 + al_get_bitmap_height(botaoSim))){  
                sair = true;
                break;
        }
        //Encerra o Jogo
        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair=true;
            break;
        }

        //Botao Não, para manter
        if (event.mouse.button == 1 && 
            event.mouse.x > SCREEN_W/2-100 &&
            event.mouse.x < (SCREEN_W/2-100 + al_get_bitmap_width(botaoSim)) &&
            event.mouse.y > SCREEN_H/2 &&
            event.mouse.y < (SCREEN_H/2 + al_get_bitmap_height(botaoSim))){  
                return mainmenu();
        }
    }
}

/*
//Fazer chamada em cada nível quando der ESC
void Menu::pausarNivel(){
    ALLEGRO_EVENT event;

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(telaPause,  al_get_bitmap_width(fundo)/2 - al_get_bitmap_height(telaPause)/2,
                    al_get_bitmap_height(fundo)/2 - al_get_bitmap_width(telaPause)/2, 0);
    al_draw_bitmap(botaoSim, SCREEN_W/2+50, SCREEN_H/2, 0);
    al_draw_bitmap(botaoNao, SCREEN_W/2-100, SCREEN_H/2, 0);

    al_draw_text (font, al_map_rgb(0,0,0) , SCREEN_W/2-40, SCREEN_H/2-50 ,0, "Deseja abandonar\no nivel atual?");

    al_flip_display();

    
    while(1){
        al_wait_for_event(event_queue, &event);

        //Botao Sim para sair do nível
        if (event.mouse.button == 1 && 
            event.mouse.x > SCREEN_W/2+50 &&
            event.mouse.x < (SCREEN_W/2+50 + al_get_bitmap_width(botaoSim)) &&
            event.mouse.y > SCREEN_H/2 &&
            event.mouse.y < (SCREEN_H/2 + al_get_bitmap_height(botaoSim))){  
                return mainmenu();
        }
        //Encerra o Jogo
        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair=true;
            break;
        }

        //Botao Não, para manter no nivel atual
        if (event.mouse.button == 1 && 
            event.mouse.x > SCREEN_W/2-100 &&
            event.mouse.x < (SCREEN_W/2-100 + al_get_bitmap_width(botaoSim)) &&
            event.mouse.y > SCREEN_H/2 &&
            event.mouse.y < (SCREEN_H/2 + al_get_bitmap_height(botaoSim))){  
                //return mainmenu();
        }
    }
}
*/

