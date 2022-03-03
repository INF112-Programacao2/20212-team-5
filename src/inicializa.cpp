#include "allegro.h"
#include "main.h"
#include <iostream>

int inicializa() {
    
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

    mapa = al_load_bitmap("CandyCrushRecursos/tabuleiro.bmp");
    if(!mapa)
    {
        std::cout << "Falha ao carregar o mapa!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    mouse=al_load_bitmap("CandyCrushRecursos/personagem.png"); 
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
    menu = al_load_bitmap("CandyCrushRecursos/menu.bmp");
    if(!menu){
        std::cout << "FALHA AO CARREGAR O MENU" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }
    dlaranja = al_load_bitmap("CandyCrushRecursos/dlaranja.tga"); //carrega a imagem da cabeca
	if(!dlaranja)
    {
        std::cout << "Falha ao carregar o doce laranja!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    
    droxo = al_load_bitmap("CandyCrushRecursos/droxo.tga"); //carrega a imagem da cabeca
	if(!droxo)
    {
        std::cout << "Falha ao carregar o doce roxo" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    dverde = al_load_bitmap("assets/dverde.tga"); //carrega a imagem da cabeca
	if(!droxo)
    {
        std::cout << "Falha ao carregar o doce verde" << std::endl;
        al_destroy_display(display);
        return 0;
    }

     Pirulito = al_load_bitmap("assets/Pirulito.bmp");
    if(!Pirulito)
    {
        std::cout << "Falha ao carregar o pirulo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    fundosugar = al_load_bitmap("assets/fundosugar.bmp");
    if(!fundosugar)
    {
        std::cout << "Falha ao carregar o Fundo do doce!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    Festa = al_load_bitmap("assets/Festa.bmp");
    if(!Festa)
    {
        std::cout << "Falha ao carregar ajuda festa!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    fundorosa = al_load_bitmap("assets/fundorosa.bmp");
    if(!fundorosa)
    {
        std::cout << "Falha ao carregar fundo das ajudas!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    Maozinha = al_load_bitmap("assets/Maozinha.bmp");
    if(!Maozinha)
    {
        std::cout << "Falha ao carregar ajuda mao!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    Muda1 = al_load_bitmap("assets/Muda1.bmp");
    if(!Muda1)
    {
        std::cout << "Falha ao carregar ajuda que muda os doces!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    Nave = al_load_bitmap("assets/Nave.bmp");
    if(!Nave)
    {
        std::cout << "Falha ao carregar ajuda nave!" << std::endl;
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
    al_destroy_bitmap(Pirulito);
    al_destroy_bitmap(fundorosa);
    al_destroy_bitmap(Festa);
    al_destroy_bitmap(fundosugar);
    al_destroy_bitmap(Maozinha);
    al_destroy_bitmap(Muda1);
    al_destroy_bitmap(Nave);
    return 0;
}