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
    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        std::cout << "Falha ao criar a fila de eventos" << std::endl;
        al_destroy_display(display);

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
    botao = al_load_bitmap("assets/botao.bmp");
    if(!botao)
    {
        std::cout << "Falha ao carregar o botão" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    fundo = al_load_bitmap("assets/Fundo2.bmp");
    if(!fundo)
    {
        std::cout << "Falha ao carregar o fundo" << std::endl;
        al_destroy_display(display);
        return 0;
    }
    cursor = al_create_mouse_cursor(droxo, 0, 0);
    if(!cursor)
    {
        std::cout << "Falha ao carregar o cursor" << std::endl;
        al_destroy_mouse_cursor(cursor);
        return 0;
    }
//------------------------------------------ Proposta

    //pecas
    ALLEGRO_BITMAP *docesimplesamarelo = NULL;
    ALLEGRO_BITMAP *docesimplesazul = NULL;
    ALLEGRO_BITMAP *docesimpleslaranja = NULL;
    ALLEGRO_BITMAP *docesimplesroxo = NULL;
    ALLEGRO_BITMAP *docesimplesverde = NULL;
    ALLEGRO_BITMAP *docesimplesvermelho = NULL;

    //bomba relogio
    ALLEGRO_BITMAP *bombarelogioamarelo = NULL;
    ALLEGRO_BITMAP *bombarelogioazul = NULL;
    ALLEGRO_BITMAP *bombarelogiolaranja = NULL;
    ALLEGRO_BITMAP *bombarelogioroxo = NULL;
    ALLEGRO_BITMAP *bombarelogioverde = NULL;
    ALLEGRO_BITMAP *bombarelogiovermelho = NULL;

    //especial horizontal
    ALLEGRO_BITMAP *especialhorizontalamarelo = NULL;
    ALLEGRO_BITMAP *especialhorizontalazul = NULL;
    ALLEGRO_BITMAP *especialhorizontallaranja = NULL;
    ALLEGRO_BITMAP *especialhorizontalroxo = NULL;
    ALLEGRO_BITMAP *especialhorizontalverde = NULL;
    ALLEGRO_BITMAP *especialhorizontalvermelho = NULL;

    //especial vertical
    ALLEGRO_BITMAP *especialverticalamarelo = NULL;
    ALLEGRO_BITMAP *especialverticalazul = NULL;
    ALLEGRO_BITMAP *especialverticallaranja = NULL;
    ALLEGRO_BITMAP *especialverticalroxo = NULL;
    ALLEGRO_BITMAP *especialverticalverde = NULL;
    ALLEGRO_BITMAP *especialverticalvermelho = NULL;

    //pacote fish
    ALLEGRO_BITMAP *pacotefishamarelo = NULL;
    ALLEGRO_BITMAP *pacotefishazul = NULL;
    ALLEGRO_BITMAP *pacotefishlaranja = NULL;
    ALLEGRO_BITMAP *pacotefishroxo = NULL;
    ALLEGRO_BITMAP *pacotefishverde = NULL;
    ALLEGRO_BITMAP *pacotefishvermelho = NULL;

    //peixe especial
    ALLEGRO_BITMAP *peixeespecialamarelo = NULL;
    ALLEGRO_BITMAP *peixeespecialazul = NULL;
    ALLEGRO_BITMAP *peixeespeciallaranja = NULL;
    ALLEGRO_BITMAP *peixeespecialroxo = NULL;
    ALLEGRO_BITMAP *peixeespecialverde = NULL;
    ALLEGRO_BITMAP *peixeespecialvermelho = NULL;

    //especiais
    ALLEGRO_BITMAP *rosquinharosaespecial = NULL;
    ALLEGRO_BITMAP *brigadeiroespecial= NULL;

    //Doces Simples

    docessimplesamarelo = al_load_bitmap("docessimplesamarelo.bmp");
    if(!docessimplesamarelo){
        cout << "Falha ao carregar docessimplesamarelo!" << endl;
        al_destroy_display(display);
        return 0;
    }

    docessimplesazul = al_load_bitmap("docessimpleszul.bmp");
    if(!docessimplesazul){
        cout << "Falha ao carregar docessimplesazul!" << endl;
        al_destroy_display(display);
        return 0;
    }

    docessimpleslaranja = al_load_bitmap("docessimpleslaranja.bmp");
    if(!docessimpleslaranja){
        cout << "Falha ao carregar docessimpleslaranja!" << endl;
        al_destroy_display(display);
        return 0;
    }

    docessimplesroxo = al_load_bitmap("docessimplesroxo.bmp");
    if(!docessimplesroxo){
        cout << "Falha ao carregar docessimplesroxo!" << endl;
        al_destroy_display(display);
        return 0;
    }

    docessimplesverde = al_load_bitmap("docessimplesverde.bmp");
    if(!docessimplesverde){
        cout << "Falha ao carregar docessimplesverde!" << endl;
        al_destroy_display(display);
        return 0;
    }

    docessimplesvermelho = al_load_bitmap("docessimplesvermelho.bmp");
    if(!docessimplesvermelho){
        cout << "Falha ao carregar docessimplesvermelho!" << endl;
        al_destroy_display(display);
        return 0;
    }
    
    //-----------------------------------------

    //Bombas Relogio

    bombarelogioamarelo = al_load_bitmap("bombarelogioamarelo.bmp");
    if(!bombarelogioamarelo){
        cout << "Falha ao carregar a bomba relogio amarela!" << endl;
        al_destroy_display(display);
        return 0;
    }
    al_draw_bitmap(apple,macax*q,macay*q,0);

    bombarelogioazul = al_load_bitmap("bombarelogioazul.bmp");
    if(!bombarelogioazul){
        cout << "Falha ao carregar a bomba relogio azul!" << endl;
        al_destroy_display(display);
        return 0;
    }
    
    bombarelogiolaranja = al_load_bitmap("bombarelogiolaranja.bmp");
    if(!bombarelogiolaranja){
        cout << "Falha ao carregar a bomba relogio laranja!" << endl;
        al_destroy_display(display);
        return 0;
    }

    bombarelogioroxa = al_load_bitmap("bombarelogioroxa.bmp");
    if(!bombarelogioroxa){
        cout << "Falha ao carregar a bomba relogio roxa!" << endl;
        al_destroy_display(display);
        return 0;
    }

    bombarelogioverde = al_load_bitmap("bombarelogioverde.bmp");
    if(!bombarelogioverde){
        cout << "Falha ao carregar a bomba relogio verde" << endl;
        al_destroy_display(display);
        return 0;
    }

    bombarelogiovermelho = al_load_bitmap("bombarelogiovermelho.bmp");
    if(!bombarelogiovermelho){
        cout << "Falha ao carregar a bomba relogio vermelho" << endl;
        al_destroy_display(display);
        return 0;
    }
    //----------------------------------------

    //Especiais Horizontais 

    especialhorizontalamarelo = al_load_bitmap("especialhorizontal.bmp");
    if(!especialhorizontalamarelo){
        cout << "Falha ao carregar especialhorizontal!" << endl;
        al_destroy_display(display);
        return 0;
    }

    especialhorizontalazul = al_load_bitmap("especialhorizontal.bmp");
    if(!especialhorizontalazul){
        cout << "Falha ao carregar especialhorizontal!" << endl;
        al_destroy_display(display);
        return 0;
    }

    especialhorizontallaranja = al_load_bitmap("especialhorizontal.bmp");
    if(!especialhorizontallaranja){
        cout << "Falha ao carregar especialhorizontal!" << endl;
        al_destroy_display(display);
        return 0;
    }

    especialhorizontalroxo = al_load_bitmap("especialhorizontal.bmp");
    if(!especialhorizontalroxo){
        cout << "Falha ao carregar especialhorizontal!" << endl;
        al_destroy_display(display);
        return 0;
    }

    especialhorizontalverde = al_load_bitmap("especialhorizontal.bmp");
    if(!especialhorizontalverde){
        cout << "Falha ao carregar especialhorizontal!" << endl;
        al_destroy_display(display);
        return 0;
    }

    especialhorizontalvermelho = al_load_bitmap("especialhorizontal.bmp");
    if(!especialhorizontalvermelho){
        cout << "Falha ao carregar especialhorizontal!" << endl;
        al_destroy_display(display);
        return 0;
    }
    //----------------------------------------

     //Especiais Verticais 

    especialverticalamarelo = al_load_bitmap("especialverticalamarelo.bmp");
    if(!especialverticalamarelo){
        cout << "Falha ao carregar especialverticalamarelo!" << endl;
        al_destroy_display(display);
        return 0;
    }

    especialverticalazul = al_load_bitmap("especialverticalazul.bmp");
    if(!especialverticalazul){
        cout << "Falha ao carregar especialverticalazul!" << endl;
        al_destroy_display(display);
        return 0;
    }

    especialverticallaranja = al_load_bitmap("especialverticallaranja.bmp");
    if(!especialverticallaranja){
        cout << "Falha ao carregar especialverticallaranja!" << endl;
        al_destroy_display(display);
        return 0;
    }

    especialverticalroxo = al_load_bitmap("especialverticalroxo.bmp");
    if(!especialverticalroxo){
        cout << "Falha ao carregar especialverticalroxo!" << endl;
        al_destroy_display(display);
        return 0;
    }

    especialverticalverde = al_load_bitmap("especialverticalverde.bmp");
    if(!especialverticalverde){
        cout << "Falha ao carregar especialverticalverde!" << endl;
        al_destroy_display(display);
        return 0;
    }

    especialverticalvermelho = al_load_bitmap("especialverticalvermelho.bmp");
    if(!especialverticalvermelho){
        cout << "Falha ao carregar especialverticalvermelho!" << endl;
        al_destroy_display(display);
        return 0;
    }
    //----------------------------------------

    //Pacote Fish

    pacotefishamarelo = al_load_bitmap("pacotefishamarelo.bmp");
    if(!pacotefishamarelo){
        cout << "Falha ao carregar pacotefishamarelo!" << endl;
        al_destroy_display(display);
        return 0;
    }

    pacotefishazul = al_load_bitmap("pacotefishazul.bmp");
    if(!pacotefishazul){
        cout << "Falha ao carregar pacotefishazul!" << endl;
        al_destroy_display(display);
        return 0;
    }

    pacotefishlaranja = al_load_bitmap("pacotefishlaranja.bmp");
    if(!pacotefishlaranja){
        cout << "Falha ao carregar pacotefishlaranja!" << endl;
        al_destroy_display(display);
        return 0;
    }

    pacotefishroxo = al_load_bitmap("pacotefishroxo.bmp");
    if(!pacotefishroxo){
        cout << "Falha ao carregar pacotefishroxo!" << endl;
        al_destroy_display(display);
        return 0;
    }

    pacotefishverde = al_load_bitmap("pacotefishverde.bmp");
    if(!pacotefishverde){
        cout << "Falha ao carregar pacotefishverde!" << endl;
        al_destroy_display(display);
        return 0;
    }

    pacotefishvermelho = al_load_bitmap("pacotefishvermelho.bmp");
    if(!pacotefishvermelho){
        cout << "Falha ao carregar pacotefishvermelho!" << endl;
        al_destroy_display(display);
        return 0;
    }

    //----------------------------------------

    //Peixe Especial

    peixeespecialamarelo = al_load_bitmap("peixeespecialamarelo.bmp");
    if(!peixeespecialamarelo){
        cout << "Falha ao carregar peixeespecialamarelo!" << endl;
        al_destroy_display(display);
        return 0;
    }

    peixeespecialazul = al_load_bitmap("peixeespecialazul.bmp");
    if(!peixeespecialazul){
        cout << "Falha ao carregar peixeespecialazul!" << endl;
        al_destroy_display(display);
        return 0;
    }

    peixeespeciallaranja = al_load_bitmap("peixeespeciallaranja.bmp");
    if(!peixeespeciallaranja){
        cout << "Falha ao carregar peixeespeciallaranja!" << endl;
        al_destroy_display(display);
        return 0;
    }

    peixeespecialroxo = al_load_bitmap("peixeespecialroxo.bmp");
    if(!peixeespecialroxo){
        cout << "Falha ao carregar peixeespecialroxo!" << endl;
        al_destroy_display(display);
        return 0;
    }

    peixeespecialverde = al_load_bitmap("peixeespecialverde.bmp");
    if(!peixeespecialverde){
        cout << "Falha ao carregar peixeespecialverde!" << endl;
        al_destroy_display(display);
        return 0;
    }

    peixeespecialvermelho = al_load_bitmap("peixeespecialvermelho.bmp");
    if(!peixeespecialvermelho){
        cout << "Falha ao carregar peixeespecialvermelho!" << endl;
        al_destroy_display(display);
        return 0;
    }

    //----------------------------------------

    //Especiais

    rosquinharosaespecial = al_load_bitmap("rosquinharosaespecial.bmp");
    if(!peixeespecialvermelho){
        cout << "Falha ao carregar rosquinharosaespecial!" << endl;
        al_destroy_display(display);
        return 0;
    }

    brigadeiroespecial = al_load_bitmap("brigadeiroespecial.bmp");
    if(!brigadeiroespecial){
        cout << "Falha ao carregar brigadeiroespecial!" << endl;
        al_destroy_display(display);
        return 0;
    }



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
    al_destroy_bitmap(bombarelogioroxo);
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

//Fim da Proposta----------------------------------------------------------------------------------------------

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