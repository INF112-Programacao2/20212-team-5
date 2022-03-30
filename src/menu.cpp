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

    
    int botao_x = SCREEN_W/2; //coordenada x do botao
    int botao1_y = 320; // coordenada y do botao
    int botao2_y = 520;
    
    //Desenha os botoes e imagens do jogo na tela
    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(logo,0,50,0);
    al_draw_bitmap(botao,botao_x,botao1_y,0);
    al_draw_bitmap(botao,botao_x,botao2_y,0);

    al_draw_text ( font, al_map_rgb(0,0,0) , botao_x+35, botao1_y+7, 0, "Iniciar");
    al_draw_text ( font, al_map_rgb(0,0,0) , botao_x+30, botao2_y+7, 0, "Musica");



    al_flip_display();
    al_wait_for_event(event_queue, &event);     //ESPERA POR UM EVENTO (No caso da condição abaixo, iniciará o jogo). SE FOR QUEBRADO(receber um break), A CONDIÇÃO RETORNA O PROGRAMA AO MENU INICIAR

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
            this->escolherNivel();  
        } 

        //Botao Configurações
        if (event.mouse.button == 1 && 
            event.mouse.x > botao_x &&
            event.mouse.x < (botao_x + al_get_bitmap_width(botao)) &&
            event.mouse.y > botao2_y &&
            event.mouse.y < (botao2_y + al_get_bitmap_height(botao))){  
            this->somDoJogo();
        }

    
    }

    //Aparecer confirmacao de saida do jogo, caso tente sair com ESC
    if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode==ALLEGRO_KEY_ESCAPE){
                this->pausarInicio();
        }
    }
    
}

void Menu::pausarInicio(){

    ALLEGRO_EVENT event;

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(telaPause,  al_get_bitmap_width(fundo)/2 - al_get_bitmap_height(telaPause)/2,
                    al_get_bitmap_height(fundo)/2 - al_get_bitmap_width(telaPause)/2, 0);
    al_draw_bitmap(botaoSim, SCREEN_W/2+65, SCREEN_H/2, 0);
    al_draw_bitmap(botaoNao, SCREEN_W/2-75, SCREEN_H/2, 0);

    al_draw_text (font, al_map_rgb(0,0,0) , SCREEN_W/2-80, SCREEN_H/2-125 ,0, "Deseja sair?");

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

void Menu::escolherNivel(){
    ALLEGRO_EVENT event;

    Nivel nivel;
    int fase = 0;

    while(1){
        al_draw_bitmap(fundo,0,0,0);
        al_draw_bitmap(fasesJogo,  0,0, 0);

        al_flip_display();
        al_wait_for_event(event_queue, &event);

        //Para o nível 1
        if (event.mouse.button == 1 && 
            event.mouse.x > 222 && event.mouse.x < 379 &&
            event.mouse.y > 555 && event.mouse.y < 690){
                fase = 1;
                nivel.faseUm(event, fase);
        }

        //Para o nível 2
        if (event.mouse.button == 1 && 
            event.mouse.x > 761 && event.mouse.x < 916 &&
            event.mouse.y > 45 && event.mouse.y < 173){
                fase=2;
                nivel.faseDois(event, fase);        
        }         

        //Para o nível 3
        if (event.mouse.button == 1 && 
            event.mouse.x > 1244 && event.mouse.x < 1419 &&
            event.mouse.y > 552 && event.mouse.y < 695){
                fase=3;
                nivel.faseTres(event, fase); 
        }

        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair=true;
            break;
        }
        if(event.type == ALLEGRO_EVENT_KEY_UP){
            if(event.keyboard.keycode==ALLEGRO_KEY_ESCAPE){
                break;
            }
        }
    
    }    
}

void Menu::somDoJogo(){
    
    if (estadoMusica){
        al_set_sample_instance_playmode(inst_musica, ALLEGRO_PLAYMODE_LOOP);
        al_attach_sample_instance_to_mixer(inst_musica, al_get_default_mixer());
        al_play_sample_instance(inst_musica);
        estadoMusica = false;
    } 
    else if(!estadoMusica){
        al_stop_sample_instance(inst_musica);
        estadoMusica = true;
    }

}



