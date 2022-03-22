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
    event_queue = al_create_event_queue();
    mapa = al_load_bitmap("assets/tabuleiro.bmp");
    mouse=al_load_bitmap("assets/personagem.png"); 
    menu = al_load_bitmap("assets/menu.bmp");
    logo = al_load_bitmap("assets/logo.bmp");
    botao = al_load_bitmap("assets/botao.bmp");
    fundo = al_load_bitmap("assets/Fundo2.bmp");
    cursor = al_create_mouse_cursor(docesimplesroxo, 0, 0);


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

    telaPause = al_load_bitmap("assets/pause.bmp");
    if(!telaPause){
        std::cout << "FALHA AO CARREGAR O TELA PAUSE" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }
    botaoSim = al_load_bitmap("assets/botaosim.bmp");
    if(!botaoSim){
        std::cout << "FALHA AO CARREGAR O BOTAO SIM" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }
    botaoNao = al_load_bitmap("assets/botaonao.bmp");
    if(!botaoNao){
        std::cout << "FALHA AO CARREGAR O BOTAO NAO" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }
    logo = al_load_bitmap("assets/logo.bmp");

    if(!logo){
        std::cout << "FALHA AO CARREGAR O Logo" << std::endl;

        al_destroy_display(display);
        
        return 0;
    }
    
    if(!botao)
    {
        std::cout << "Falha ao carregar o botão" << std::endl;
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
//------------------------------------------ 

    //Doces Simples

    docesimplesamarelo = al_load_bitmap("docesimplesamarelo.bmp");
    if(!docesimplesamarelo){
        std::cout << "Falha ao carregar docesimplesamarelo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    docesimplesazul = al_load_bitmap("docesimpleszul.bmp");
    if(!docesimplesazul){
        std::cout << "Falha ao carregar docesimplesazul!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    docesimpleslaranja = al_load_bitmap("docesimpleslaranja.bmp");
    if(!docesimpleslaranja){
        std::cout << "Falha ao carregar docesimpleslaranja!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    docesimplesroxo = al_load_bitmap("docesimplesroxo.bmp");
    if(!docesimplesroxo){
        std::cout << "Falha ao carregar docesimplesroxo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    docesimplesverde = al_load_bitmap("docesimplesverde.bmp");
    if(!docesimplesverde){
        std::cout << "Falha ao carregar docesimplesverde!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    docesimplesvermelho = al_load_bitmap("docesimplesvermelho.bmp");
    if(!docesimplesvermelho){
        std::cout << "Falha ao carregar docesimplesvermelho!" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    
    //-----------------------------------------

    //Bombas Relogio

    bombarelogioamarelo = al_load_bitmap("bombarelogioamarelo.bmp");
    if(!bombarelogioamarelo){
        std::cout << "Falha ao carregar a bomba relogio amarela!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    bombarelogioazul = al_load_bitmap("bombarelogioazul.bmp");
    if(!bombarelogioazul){
        std::cout << "Falha ao carregar a bomba relogio azul!" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    
    bombarelogiolaranja = al_load_bitmap("bombarelogiolaranja.bmp");
    if(!bombarelogiolaranja){
        std::cout << "Falha ao carregar a bomba relogio laranja!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    bombarelogioroxa = al_load_bitmap("bombarelogioroxa.bmp");
    if(!bombarelogioroxa){
        std::cout << "Falha ao carregar a bomba relogio roxa!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    bombarelogioverde = al_load_bitmap("bombarelogioverde.bmp");
    if(!bombarelogioverde){
        std::cout << "Falha ao carregar a bomba relogio verde!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    bombarelogiovermelho = al_load_bitmap("bombarelogiovermelho.bmp");
    if(!bombarelogiovermelho){
        std::cout << "Falha ao carregar a bomba relogio vermelho!" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    //----------------------------------------

    //Especiais Horizontais 

    especialhorizontalamarelo = al_load_bitmap("especialhorizontalamarelo.bmp");
    if(!especialhorizontalamarelo){
        std::cout << "Falha ao carregar especialhorizontalamarelo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    especialhorizontalazul = al_load_bitmap("especialhorizontalazul.bmp");
    if(!especialhorizontalazul){
        std::cout << "Falha ao carregar especialhorizontalazul!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    especialhorizontallaranja = al_load_bitmap("especialhorizontallaranja.bmp");
    if(!especialhorizontallaranja){
        std::cout << "Falha ao carregar especialhorizontallaranja!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    especialhorizontalroxo = al_load_bitmap("especialhorizontalroxo.bmp");
    if(!especialhorizontalroxo){
        std::cout << "Falha ao carregar especialhorizontalroxo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    especialhorizontalverde = al_load_bitmap("especialhorizontalverde.bmp");
    if(!especialhorizontalverde){
        std::cout << "Falha ao carregar especialhorizontalverde!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    especialhorizontalvermelho = al_load_bitmap("especialhorizontalvermelho.bmp");
    if(!especialhorizontalvermelho){
        std::cout << "Falha ao carregar especialhorizontalvermelho!" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    //----------------------------------------

     //Especiais Verticais 

    especialverticalamarelo = al_load_bitmap("especialverticalamarelo.bmp");
    if(!especialverticalamarelo){
        std::cout << "Falha ao carregar especialverticalamarelo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    especialverticalazul = al_load_bitmap("especialverticalazul.bmp");
    if(!especialverticalazul){
        std::cout << "Falha ao carregar especialverticalazul!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    especialverticallaranja = al_load_bitmap("especialverticallaranja.bmp");
    if(!especialverticallaranja){
        std::cout << "Falha ao carregar especialverticallaranja!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    especialverticalroxo = al_load_bitmap("especialverticalroxo.bmp");
    if(!especialverticalroxo){
        std::cout << "Falha ao carregar especialverticalroxo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    especialverticalverde = al_load_bitmap("especialverticalverde.bmp");
    if(!especialverticalverde){
        std::cout << "Falha ao carregar especialverticalverde!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    especialverticalvermelho = al_load_bitmap("especialverticalvermelho.bmp");
    if(!especialverticalvermelho){
        std::cout << "Falha ao carregar especialverticalvermelho!" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    //----------------------------------------

    //Pacote Fish

    pacotefishamarelo = al_load_bitmap("pacotefishamarelo.bmp");
    if(!pacotefishamarelo){
        std::cout << "Falha ao carregar pacotefishamarelo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    pacotefishazul = al_load_bitmap("pacotefishazul.bmp");
    if(!pacotefishazul){
        std::cout << "Falha ao carregar pacotefishazul!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    pacotefishlaranja = al_load_bitmap("pacotefishlaranja.bmp");
    if(!pacotefishlaranja){
        std::cout << "Falha ao carregar pacotefishlaranja!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    pacotefishroxo = al_load_bitmap("pacotefishroxo.bmp");
    if(!pacotefishroxo){
        std::cout << "Falha ao carregar pacotefishroxo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    pacotefishverde = al_load_bitmap("pacotefishverde.bmp");
    if(!pacotefishverde){
        std::cout << "Falha ao carregar pacotefishverde!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    pacotefishvermelho = al_load_bitmap("pacotefishvermelho.bmp");
    if(!pacotefishvermelho){
        std::cout << "Falha ao carregar pacotefishvermelho!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    //----------------------------------------

    //Peixe Especial

    peixeespecialamarelo = al_load_bitmap("peixeespecialamarelo.bmp");
    if(!peixeespecialamarelo){
        std::cout << "Falha ao carregar peixeespecialamarelo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    peixeespecialazul = al_load_bitmap("peixeespecialazul.bmp");
    if(!peixeespecialazul){
        std::cout << "Falha ao carregar peixeespecialazul!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    peixeespeciallaranja = al_load_bitmap("peixeespeciallaranja.bmp");
    if(!peixeespeciallaranja){
        std::cout << "Falha ao carregar peixeespeciallaranja!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    peixeespecialroxo = al_load_bitmap("peixeespecialroxo.bmp");
    if(!peixeespecialroxo){
        std::cout << "Falha ao carregar peixeespecialroxo!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    peixeespecialverde = al_load_bitmap("peixeespecialverde.bmp");
    if(!peixeespecialverde){
        std::cout << "Falha ao carregar peixeespecialverde!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    peixeespecialvermelho = al_load_bitmap("peixeespecialvermelho.bmp");
    if(!peixeespecialvermelho){
        std::cout << "Falha ao carregar peixeespecialvermelho!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    //----------------------------------------

    //Especiais

    rosquinharosaespecial = al_load_bitmap("rosquinharosaespecial.bmp");
    if(!peixeespecialvermelho){
        std::cout << "Falha ao carregar rosquinharosaespecial!" << std::endl;
        al_destroy_display(display);
        return 0;
    }

    brigadeiroespecial = al_load_bitmap("brigadeiroespecial.bmp");
    if(!brigadeiroespecial){
        std::cout << "Falha ao carregar brigadeiroespecial!" << std::endl;
        al_destroy_display(display);
        return 0;
    }



    
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
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    //pecas
    al_destroy_bitmap(docesimplesamarelo);
    al_destroy_bitmap(docesimplesazul);
    al_destroy_bitmap(docesimpleslaranja);
    al_destroy_bitmap(docesimplesroxo);
    al_destroy_bitmap(docesimplesverde);
    al_destroy_bitmap(docesimplesvermelho);

    //bomba relogio
    al_destroy_bitmap(bombarelogioamarelo);
    al_destroy_bitmap(bombarelogioazul);
    al_destroy_bitmap(bombarelogiolaranja);
    al_destroy_bitmap(bombarelogioroxa);
    al_destroy_bitmap(bombarelogioverde);
    al_destroy_bitmap(bombarelogiovermelho);

    //especial horizontal
    al_destroy_bitmap(especialhorizontalamarelo);
    al_destroy_bitmap(especialhorizontalazul);
    al_destroy_bitmap(especialhorizontallaranja);
    al_destroy_bitmap(especialhorizontalroxo);
    al_destroy_bitmap(especialhorizontalverde);
    al_destroy_bitmap(especialhorizontalvermelho);

    //especial vertical
    al_destroy_bitmap(especialverticalamarelo);
    al_destroy_bitmap(especialverticalazul);
    al_destroy_bitmap(especialverticallaranja);
    al_destroy_bitmap(especialverticalroxo);
    al_destroy_bitmap(especialverticalverde);
    al_destroy_bitmap(especialverticalvermelho);

    //pacote fish
    al_destroy_bitmap(pacotefishamarelo);
    al_destroy_bitmap(pacotefishazul);
    al_destroy_bitmap(pacotefishlaranja);
    al_destroy_bitmap(pacotefishroxo);
    al_destroy_bitmap(pacotefishverde);
    al_destroy_bitmap(pacotefishvermelho);

    //peixe especial
    al_destroy_bitmap(peixeespecialamarelo);
    al_destroy_bitmap(peixeespecialazul);
    al_destroy_bitmap(peixeespeciallaranja);
    al_destroy_bitmap(peixeespecialroxo);
    al_destroy_bitmap(peixeespecialverde);
    al_destroy_bitmap(peixeespecialvermelho);

    //especiais
    al_destroy_bitmap(rosquinharosaespecial);
    al_destroy_bitmap(brigadeiroespecial);

    return 0;
}

#endif