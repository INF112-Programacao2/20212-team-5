#ifndef INICIALIZA_CPP
#define INICIALIZA_CPP

#include "inicializa.hpp"
#include "main.hpp"

int inicializa() {
    
    nome = "Candy Crush";
    al_set_app_name(nome);
    
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

    mapa = al_load_bitmap("assets/tabuleiro.bmp");
    if(!mapa)
    {
        std::cout << "Falha ao carregar o mapa!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    mouse=al_load_bitmap("assets/personagem.png"); 
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
    menu = al_load_bitmap("assets/menu.bmp");
    if(!menu){
        std::cout << "FALHA AO CARREGAR O MENU" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }
    logo = al_load_bitmap("assets/logo.bmp");
    if(!logo){
        std::cout << "FALHA AO CARREGAR O Logo" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }
    dlaranja = al_load_bitmap("assets/dlaranja.tga"); //carrega a imagem da cabeca
	if(!dlaranja)
    {
        std::cout << "Falha ao carregar o doce laranja!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    
    droxo = al_load_bitmap("assets/droxo.tga"); //carrega a imagem da cabeca
	if(!droxo)
    {
        std::cout << "Falha ao carregar o doce roxo" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    dverde = al_load_bitmap("assets/dverde.tga");
    if(!dverde)
    {
        std::cout << "Falha ao carregar o doce verde" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    dvermelho = al_load_bitmap("assets/dvermelho.tga");
    if(!dvermelho)
    {
        std::cout << "Falha ao carregar o doce vermelho" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    dazul = al_load_bitmap("assets/dazul.tga");
    if(!dazul)
    {
        std::cout << "Falha ao carregar o doce azul" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    fundo = al_load_bitmap("assets/Fundo2.bmp");
    cursor = al_create_mouse_cursor(droxo, 0, 0);
    if(!cursor)
        {
            std::cout << "Falha ao carregar o cursor" << std::endl;
            al_destroy_mouse_cursor(cursor);
            return 0;
        }
    //al_init_font_addon();  // marcado para possibilitar a execução
    //al_init_ttf_addon();  //  marcado para possibilitar a execução
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_init_font_addon();    
    al_init_ttf_addon();    
    font = al_load_ttf_font("assets/candycrush.ttf", 26, 0); 

    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

    return 1;
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

    return 0;
}

int sorteia(int mapa[][8]){
    for(int i=0;i<8; i++){
        for(int j=0;j<8;j++){
            mapa[i][j] = rand() % 5;
        }
    }
}

#endif