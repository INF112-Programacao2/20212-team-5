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

    if(!al_init_acodec_addon())
    {
        std::cout <<"Falha ao iniciar al_init_acodec_addon!" << std::endl;
        return 0;
    }
    if(!al_install_audio())
    {
        std::cout <<"Falha ao iniciar al_install_audio!" << std::endl;
        return 0;
    }

    if (!al_reserve_samples(2))
    {
        std::cout <<"Falha ao iniciar al_reserve_samples!" << std::endl;
        return 0;
    }

    dlaranja = al_load_bitmap("assets/docesimpleslaranja.bmp"); //carrega a imagem da cabeca
    droxo = al_load_bitmap("assets/docesimplesroxo.bmp"); //carrega a imagem da cabeca
    dverde = al_load_bitmap("assets/docesimplesverde.bmp");
    dvermelho = al_load_bitmap("assets/docesimplesvermelho.bmp");
    dazul = al_load_bitmap("assets/docesimplesazul.bmp");
    damarelo = al_load_bitmap("assets/docesimplesamarelo.bmp");
    display = al_create_display(SCREEN_W, SCREEN_H);
    event_queue = al_create_event_queue();
    mapa = al_load_bitmap("assets/tabuleiroExpande.bmp");
    mouse=al_load_bitmap("assets/personagem.png"); 
    menu = al_load_bitmap("assets/menu.bmp");
    telaPause = al_load_bitmap("assets/pauseexp.bmp");
    botaoSim = al_load_bitmap("assets/botaosim.bmp");
    botaoNao = al_load_bitmap("assets/botaonao.bmp");
    fasesJogo = al_load_bitmap("assets/fasesjogo.bmp");
    logo = al_load_bitmap("assets/logo.bmp");
    botao = al_load_bitmap("assets/botao.bmp");
    fundo = al_load_bitmap("assets/Fundo3exp.bmp");
    cursor = al_create_mouse_cursor(droxo, 0, 0);

    musica = al_load_sample("assets/musica.ogg");
    inst_musica = al_create_sample_instance(musica);

    //referente a poder
    Pirulito = al_load_bitmap("assets/Pirulito.bmp");
    //fundosugar = al_load_bitmap("assets/fundosugar.bmp");
    Festa = al_load_bitmap("assets/Festa.bmp");
    fundorosa = al_load_bitmap("assets/fundorosa.bmp");
    Maozinha = al_load_bitmap("assets/Maozinha.bmp");
    Muda1 = al_load_bitmap("assets/Muda.bmp");
    Nave = al_load_bitmap("assets/Nave.bmp");


    if(!display)
    {
        std::cout << "Falha ao inicializar a tela" << std::endl;
        al_destroy_timer(timer);
        return 0;
    }
    
    if(!event_queue)
    {
        std::cout << "Falha ao criar a fila de eventos" << std::endl;
        al_destroy_display(display);

        return 0;
    }
    
    if(!mapa)
    {
        std::cout << "Falha ao carregar o mapa!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    
    if(!al_install_mouse())
    {
        std::cout << "Falha ao inicializar o mouse" << std::endl;
        return 0;
    }
    
    if(!menu){
        std::cout << "FALHA AO CARREGAR O MENU" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }


    if(!telaPause){
        std::cout << "FALHA AO CARREGAR O TELA PAUSE" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }

    if(!botaoSim){
        std::cout << "FALHA AO CARREGAR O BOTAO SIM" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }
    
    if(!botaoNao){
        std::cout << "FALHA AO CARREGAR O BOTAO NAO" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }

    if(!fasesJogo){
        std::cout << "FALHA AO CARREGAR O FASES JOGO" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }

    
    if(!logo){
        std::cout << "FALHA AO CARREGAR O Logo" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }
    
    if(!botao)
    {
        std::cout << "Falha ao carregar o botÃ£o" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    
    if(!fundo)
    {
        std::cout << "Falha ao carregar o fundo" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    
    if(!cursor)
    {
        std::cout << "Falha ao carregar o cursor" << std::endl;
        al_destroy_mouse_cursor(cursor);
        return 0;
    }

    if(!musica){
        std::cout << "FALHA AO CARREGAR A MUSICA" << std::endl;

        al_destroy_sample(musica);
        
        return 0;
    }
    if(!inst_musica){
        std::cout << "FALHA AO CARREGAR A ISTANCIA MUSICA" << std::endl;

        al_destroy_sample(musica);
        
        return 0;
    }

    //referente a poder
    if(!Pirulito)
    {
        std::cout << "Falha ao carregar o pirulo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    /*
    if(!fundosugar)
    {
        std::cout << "Falha ao carregar o Fundo do doce!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    */
    if(!Festa)
    {
        std::cout << "Falha ao carregar ajuda festa!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    if(!fundorosa)
    {
        std::cout << "Falha ao carregar fundo das ajudas!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    if(!Maozinha)
    {
        std::cout << "Falha ao carregar ajuda mao!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    if(!Muda1)
    {
        std::cout << "Falha ao carregar ajuda que muda os doces!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    if(!Nave)
    {
        std::cout << "Falha ao carregar ajuda nave!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_init_font_addon();    
    al_init_ttf_addon();   

    font = al_load_ttf_font("assets/candycrush.ttf", 50, 0); 
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

    return 1;
}

int desinicializa(){
    al_destroy_bitmap(mapa);
    al_destroy_bitmap(mouse);
    al_destroy_bitmap(telaPause);
    al_destroy_bitmap(botao);
    al_destroy_bitmap(botaoSim);
    al_destroy_bitmap(botaoNao);
    al_destroy_bitmap(fasesJogo);
    al_destroy_font(font);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    al_destroy_sample(musica);
    //al_destroy_sample_instance(musicaInstancia);

    //referente a poder
    al_destroy_bitmap(fundorosa);
    al_destroy_bitmap(Festa);
    //al_destroy_bitmap(fundosugar);
    al_destroy_bitmap(Maozinha);
    al_destroy_bitmap(Muda1);
    al_destroy_bitmap(Nave);

    return 0;
}

void sorteia(int mapa[][7]){
    for(int i=0;i<8; i++){
        for(int j=0;j<8;j++){
            mapa[i][j] = rand() % 6;
        }
    }
}

#endif