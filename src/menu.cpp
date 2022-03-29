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

    //Nivel nivel;
    
    int botao_x = SCREEN_W/2; //coordenada x do botao
    int botao1_y = 320; // coordenada y do botao
    int botao2_y = 520;
    

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(logo,0,50,0);
    al_draw_bitmap(botao,botao_x,botao1_y,0);
    al_draw_bitmap(botao,botao_x,botao2_y,0);

    al_draw_text ( font, al_map_rgb(0,0,0) , botao_x+35, botao1_y+7, 0, "Iniciar");
    al_draw_text ( font, al_map_rgb(0,0,0) , botao_x+30, botao2_y+7, 0, "Config.");


    /*
    Nivel nivel;
    int fase = 0;

    */


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
            std::cout << "Click no Configurações!" << std::endl;
            this->somDoJogo();
        }

    /*

    if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.button == 1){

        if(keyboardState == 1 /* temporário -> || keyboardState == 3 || keyboardState == 0){
            fase=1;
            
            nivel.faseUm(event, fase);

    
        }
        if (keyboardState == 2){ fase=2;nivel.faseDois(event, fase);}
    }
    */
    }

    if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode==ALLEGRO_KEY_ESCAPE){
                std::cout << "Aparecer tela de Pause" << std::endl;
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
                std::cout << "Clicou no Nível 1" << std::endl;
                fase = 1;
                nivel.faseUm(event, fase);
        }

        //Para o nível imagem 1
        if (event.mouse.button == 1 && 
            event.mouse.x > 502 && event.mouse.x < 660 &&
            event.mouse.y > 320 && event.mouse.y < 448){
                std::cout << "Clicou no Nível imagem 1" << std::endl;
                        
        }
        //Para o nível 2
        if (event.mouse.button == 1 && 
            event.mouse.x > 761 && event.mouse.x < 916 &&
            event.mouse.y > 45 && event.mouse.y < 173){
                std::cout << "Clicou no Nível 2" << std::endl;
                fase=2;
                nivel.faseDois(event, fase);        
        }
<<<<<<< HEAD
        //Para o nível 3
        if (event.mouse.button == 1 && 
            event.mouse.x > 761 && event.mouse.x < 916 &&
            event.mouse.y > 45 && event.mouse.y < 173){
                fase = 3;
                nivel.faseTres(event, fase);      
        }
=======
>>>>>>> d961599431c2e14161e020fd243b16b08a77ec8a

        //Para o nível imagem 2
        if (event.mouse.button == 1 && 
            event.mouse.x > 1023 && event.mouse.x < 1169 &&
            event.mouse.y > 320 && event.mouse.y < 439){
                std::cout << "Clicou no Nível imagem 2" << std::endl;        
        }

        //Para o nível 3
        if (event.mouse.button == 1 && 
            event.mouse.x > 1244 && event.mouse.x < 1419 &&
            event.mouse.y > 552 && event.mouse.y < 695){
                std::cout << "Clicou no Nível 3" << std::endl;
        }

        /*if(event.type == ALLEGRO_EVENT_MOUSE_AXES)
            std::cout << event.mouse.x << " " << event.mouse.y << std::endl;
        */

        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair=true;
            break;
        }
        if(event.type == ALLEGRO_EVENT_KEY_UP){
            if(event.keyboard.keycode==ALLEGRO_KEY_ESCAPE){
                //std::cout << "Aparecer tela de Pause" << std::endl;
                //this->pausarMenu();
                break;
            }
        }
    
    }    
}

void Menu::somDoJogo(){
    
    al_set_sample_instance_playmode(inst_musica, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(inst_musica, al_get_default_mixer());
    al_play_sample_instance(inst_musica);
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


