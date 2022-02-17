1_ALLEGRO_BITMAP *mouse=NULL; // declara o ponteiro para a variavel mouse;
2 if(!al_install_mouse())... //inicializa a função para instalar o mouse;
3_mouse=al_load_bitmap("CandyCrushResources/personagem.png");  //atribui uma imagem ao mouse;
4_ al_register_event_source(event_queue, al_get_mouse_event_source()); // coloca o mouse na fila de eventos;

5_
 if(ev.type == ALLEGRO_EVENT_TIMER) // Verifica se o tempo está passando, ou seja, se o aplicativo está rodando
        
        else if(ev.type== ALLEGRO_EVENT_MOUSE_AXES) //SE PASSAR O PONTEIRO EM CIMA DO DISPLAY
        else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) //SE DER O CLICK
   
        else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_UP) // SE SOLTAR O CLICK, NAO TIVER PRESSIONADO


6_ Não entendi o objetivo dessas funções:

//al_init_font_addon();  // marcado para possibilitar a execução
//al_init_ttf_addon();  //  marcado para possibilitar a execução


OBS: As coordenadas do mouse vão ser impressas, assim como o CLICK.
PROBLEMAS:

-> O botão do mouse ainda não aparece;
-> Ainda não dá pra fechar o app pelo próprio;
    