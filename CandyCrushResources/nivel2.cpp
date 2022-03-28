/*
                                            Bem vindo ao jogo do Candy Crush SAGA
            Trabalho final de INF112, consiste em recriar o game CandyCrush em C++, disponível para computadores Windows/Linux x64
                    FLAGS NECESSÁRIAS PARA O COMPILADOR/LINKADOR -> -lallegro -lallegro_image -lallegro_font -lallegro_ttf
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>   
#include <allegro5/allegro_ttf.h>    
#include <iostream>
#include <stdlib.h>

using namespace std;

const float FPS = 1.5;
const int SCREEN_W = 1650; //HORIZONTAL
const int SCREEN_H = 980;
const int QUAD_SIZE = 20;


ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *menu = NULL;
ALLEGRO_BITMAP *mapa= NULL;
ALLEGRO_BITMAP *mouse=NULL;

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
ALLEGRO_BITMAP *bombarelogioroxa = NULL;
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

//IMAGENS
ALLEGRO_BITMAP *img_menina_1=NULL;


bool redraw = true;   
bool sair = false;
bool pressao=false;
bool pressao_dir=false;
int mouse_x, mouse_y;

//--------------auxiliares----------------------//
int Y_click_esq=0;
int X_click_esq=0;

int Y_click_dir=0;
int X_click_dir=0;
int aux_map;

int xtrio[64];
int ytrio[64];

bool vertical=false;
bool horizontal=false;
bool listrado=true;


//------------------------------pontuação------------------------//
int n_doces_list_roxo=0;
int n_doces_list_lar=0;
int n_doces_list_verde=0;
int n_doces_list_vermelho=0;
int n_doces_list_azul=0;
int n_doces_list_amarelo=0;
bool nivel_completo=false;

int moves=0;

//-------------------------------------------//
 




int MAPA[18][7]={
    0, 2 ,3,0,5,0,0,
    1, 5 ,3,5,6,5,6,
    2, 1 ,6,0,5,3,6,

    3, 2 ,5,5,1,2,0,
    3, 5 ,2,1,0,2,1,
    5, 1 ,3,0,0,1,0,

    1, 2 ,1,0, 1, 2,1,
    6, 1 ,2,6, 6, 5,0,
    6, 3 ,1,3, 5, 1,2,
    0, 2 ,3,0, 5, 0,0,
    1, 5 ,3,5, 6, 5,6,
    2, -1 ,6,1, 5, 3,6,

    3, 2 ,5,2,2,0,0,
    3, -1 ,2,1,0,6,1,
    5, 1 ,3,0,-8,5,0,

    1, 2 ,1,0,1,2,1,
    6, 1 ,2,5,-8,1,0,
    6, 3 ,1,3,5,1,2,
    
 
};
int q = 110;  
int aux,aux2,aux3,aux_4,aux_5;
int definir_numero_de_movimentos_do_nivel=25; /// 

funcao_cair_doce_listrado_vertical(int aux_4_, int x, int y){// 4 FAZ 1 LISTRADO
     if(aux_4==0){MAPA[x+3][y]=8;}
    if(aux_4==1){MAPA[x+3][y]=-1;}
    if(aux_4==2){MAPA[x+3][y]=-2;}
    if(aux_4==3){MAPA[x+3][y]=-3;}
    if(aux_4==5){MAPA[x+3][y]=-5;}
    if(aux_4==6){MAPA[x+3][y]=-6;}

}
funcao_cairDoce_listrado_horizontal(int aux_5,int y_dir, int x_dir){ //4 FAZ 1 LISTRADO
    

    if(aux_5==0){cout<<"owwww0"<<endl;MAPA[y_dir][x_dir]=8;}

    if(aux_5==1){cout<<"owwww1"<<endl;MAPA[y_dir][x_dir]=-1;}

    if(aux_5==2){cout<<"owwww2"<<endl;MAPA[y_dir][x_dir]=-2;}
    if(aux_5==3){cout<<"owwww3"<<endl;MAPA[y_dir][x_dir]=-3;}
    if(aux_5==5){cout<<"owwww5"<<endl;MAPA[y_dir][x_dir]=-5;}
    if(aux_5==6){cout<<"owwww6"<<endl;MAPA[y_dir][x_dir]=-6;}

}

int  funcao_cair_doces(int check_type, int x, int y){
       
        if(check_type==3){
            if(vertical){
               // cout<<x<<" "<<y<<" da função"<<endl;  
                aux=2;
                
                 for( int w=1; x-w>=0;w++){
                        if(x+aux>=0){
                            MAPA[x+aux][y]=MAPA[x-w][y];
                            aux--;
                        }
                       
                        
                }
                   
            }      
               
       
        
            if(horizontal){
                for(int k=0; x-k>=0;k++){
                    //cout<<"x-k= "<<x-k<<endl;
                    MAPA[x-k][y+2]=MAPA[x-k-1][y+2];
                    MAPA[x-k][y+1]=MAPA[x-k-1][y+1];
                    MAPA[x-k][y]=MAPA[x-k-1][y];
                }

            }
        }
        
         if(check_type==4){
             if(vertical){
                //cout<<x<<" "<<y<<" da função"<<endl;  
                aux2=3;
                
                    for( int w=1; x-w>=0;w++){
                        if(x+aux2>=0){
                             MAPA[x+aux2][y]=MAPA[x-w][y];
                             aux2--;
                        }
                    }
                
                //PASSIVEL DE REMOÇÃO
                /* if(listrado){
                    funcao_cair_doce_listrado(aux_4, x, y); 
                } */
                    
             }  
  
            if(horizontal){
                for(int k=0; x-k>=0;k++){
                   // cout<<"x-k= "<<x-k<<endl;
                    
                    MAPA[x-k][y+3]=MAPA[x-k-1][y+3];
                    MAPA[x-k][y+2]=MAPA[x-k-1][y+2];
                    MAPA[x-k][y+1]=MAPA[x-k-1][y+1];
                    MAPA[x-k][y]=MAPA[x-k-1][y];
                }
                //PASSIVEL DE REMOÇÃO
                /* if(listrado){
                    cout<<"fui invocado"<<endl;
                    funcao_cairDoce_listrado_horizontal(aux_5,Y_click_dir, X_click_dir);
                } */



            } 
        }
        
         if(check_type==5){
             if(vertical){
                cout<<x<<" "<<y<<" da função"<<endl;  
                aux3=4;
                
                 for( int w=1; x-w>=0;w++){
                    if(x+aux3>=0){
                        MAPA[x+aux3][y]=MAPA[x-w][y];
                        aux3--;
                    }                  
                }               
            }
            
            if(horizontal){
                for(int k=0; x-k>=0;k++){
                    //cout<<"x-k= "<<x-k<<endl;

                    MAPA[x-k][y+4]=MAPA[x-k-1][y+4];
                    MAPA[x-k][y+3]=MAPA[x-k-1][y+3];
                    MAPA[x-k][y+2]=MAPA[x-k-1][y+2];
                    MAPA[x-k][y+1]=MAPA[x-k-1][y+1];
                    MAPA[x-k][y]=MAPA[x-k-1][y];
                }

            } 
        }  
         

        //VAI FA
         if(check_type=6){
            if(vertical){
           
                for( int k=0 ; k<10  ; k++   ){     
                    MAPA[17-k][y]=MAPA[11-k][y];
                }


            }
            
            if(horizontal){
                for(int k=0; x-k >0; k++){ //x-k ->> enquanto a posição da (linha - k) seja maior que 0 
                    //colunas de 0 a 6 ---> 7 colunas
                        MAPA[x-k][0]=MAPA[x-k-1][0];
                        MAPA[x-k][1]=MAPA[x-k-1][1];
                        MAPA[x-k][2]=MAPA[x-k-1][2];
                        MAPA[x-k][3]=MAPA[x-k-1][3];
                        MAPA[x-k][4]=MAPA[x-k-1][4];
                        MAPA[x-k][5]=MAPA[x-k-1][5];
                        MAPA[x-k][6]=MAPA[x-k-1][6];
                       
                    }

            } 
         }
}

int funcao_aux_check3_esp(int i, int j, int tipo_positivo, int tipo_listrado, int &n_doces){
         
        
        /*-----------CONDIÇÃO PARA SER UM TRIO LISTRADO VERTICAL--------------------*/
        if(  (MAPA[i][j]==tipo_listrado && MAPA[i+1][j]==tipo_positivo && MAPA[i+2][j]==tipo_positivo ) ||   (MAPA[i][j]==tipo_positivo && MAPA[i+1][j]==tipo_listrado && MAPA[i+2][j]==tipo_positivo)  || (MAPA[i][j]==tipo_positivo && MAPA[i+1][j]==tipo_positivo && MAPA[i+2][j]==tipo_listrado )   ){ //verifica se a primeira posição do trio e suas posições abaixo são iguais   

            n_doces++;
            cout<<"+1 Listrado verticalmente!!!!"<<endl;
            cout<<"laranja_list: "<< n_doces_list_lar<<endl;
            cout<<"roxo_list: "<< n_doces_list_roxo<<endl;

             
          
           
        vertical=true; 
            
        funcao_cair_doces(6,i,j);

        }
        vertical=false;
/*-------------------------------FIM VERTICAL -----------------------------------*/


/*----------------------------TRIO HORIZONTAL_VERTICAL---------------------------*/

       if( (MAPA[i][j]==tipo_listrado && MAPA[i][j+1]==tipo_positivo && MAPA[i][j+2]==tipo_positivo ) ||   (MAPA[i][j]==tipo_positivo && MAPA[i][j+1]==tipo_listrado && MAPA[i][j+2]==tipo_positivo)  || (MAPA[i][j]==tipo_positivo && MAPA[i][j+1]==tipo_positivo && MAPA[i][j+2]==tipo_listrado ) ){ //verifica se a primeira posição do trio e suas posições abaixo são iguais
            n_doces++;
            cout<<"+1 Listrado horizontalmente !!!!"<<endl;
            cout<<"laranja_list: "<< n_doces_list_lar<<endl;
            cout<<"roxo_list: "<< n_doces_list_roxo<<endl;

           
            
            for(int k=0; k<7; k++){
                MAPA[i][k]=4; //atribui NADA à primeira posição
            }
            horizontal=true;
            
            /* if(n_doces_list_lar<2){
                n_doces_list_lar++;
            }  
            else if( n_doces_list_lar==2){
                cout<<"ce conseguiu 2 laranjas! listrados!!!!! >D"<<endl;
                
            }  */

            funcao_cair_doces(6,i,j);
        }
        horizontal=false;

/*-----------------------FIM HORIZONTAL --------------------------------------*/

        if(n_doces_list_lar==2 && n_doces_list_roxo==2){
            nivel_completo=true;
            cout<<"NÍVEL COMPLETO!!!!!"<<endl;
            sair=true;

        } 

}

int funcao_aux_check4_esp(int i, int j, int tipo_positivo, int tipo_listrado, int &n_doces){
    
    
    /*---------------------------------VERTICAL------------------------*/
    if( 
    (MAPA[i][j]==tipo_listrado && MAPA[i+1][j]==tipo_positivo && MAPA[i+2][j]==tipo_positivo && MAPA[i+3][j]==tipo_positivo )||
    (MAPA[i][j]==tipo_positivo && MAPA[i+1][j]==tipo_listrado && MAPA[i+2][j]==tipo_positivo && MAPA[i+2][j]==tipo_positivo)||
    (MAPA[i][j]==tipo_positivo && MAPA[i+1][j]==tipo_positivo && MAPA[i+2][j]==tipo_listrado && MAPA[i+2][j]==tipo_positivo)|| 
    (MAPA[i][j]==tipo_positivo && MAPA[i+1][j]==tipo_positivo && MAPA[i+2][j]==tipo_positivo && MAPA[i+3][j]==tipo_listrado)  
    ){
        cout<<"CHECK 4 especial vertical ;)"<<endl;
        n_doces++;
        vertical=true;
         funcao_cair_doces(6,i,j);
    }
    vertical=false;
    /*-----------------------------------------fim vertical-------------------*/

    if( (MAPA[i][j]==tipo_listrado && MAPA[i][j+1]==tipo_positivo && MAPA[i][j+2]==tipo_positivo && MAPA[i][j+3]==tipo_positivo)||
    (MAPA[i][j]==tipo_positivo && MAPA[i][j+1]==tipo_listrado && MAPA[i][j+2]==tipo_positivo && MAPA[i][j+3]==tipo_positivo)||
    (MAPA[i][j]==tipo_positivo && MAPA[i][j+1]==tipo_positivo && MAPA[i][j+2]==tipo_listrado && MAPA[i][j+3]==tipo_positivo)|| 
    (MAPA[i][j]==tipo_positivo && MAPA[i][j+1]==tipo_positivo && MAPA[i][j+2]==tipo_positivo && MAPA[i][j+3]==tipo_listrado)  ){
        cout<<"CHECK 4 ESPECIAL horizontal ;p"<<endl;
        n_doces++;
        horizontal=true;
         funcao_cair_doces(6,i,j);
    }
    horizontal=false;


}
int funcao_check_especial(int i, int j){
          
        funcao_aux_check4_esp(i,j,0,-8,n_doces_list_lar); //check3 laranja especial 
        funcao_aux_check3_esp(i,j,0,-8,n_doces_list_lar); //check3 laranja especial 

        funcao_aux_check4_esp(i,j,1,-1,n_doces_list_roxo);// check3 roxo especial
        funcao_aux_check3_esp(i,j,1,-1,n_doces_list_roxo);// check3 roxo especial

        funcao_aux_check4_esp(i,j,2,-2,n_doces_list_verde);//check3 verde especial
        funcao_aux_check3_esp(i,j,2,-2,n_doces_list_verde);//check3 verde especial
        
        funcao_aux_check4_esp(i,j,3,-3,n_doces_list_vermelho);//check vermelho especial
        funcao_aux_check3_esp(i,j,3,-3,n_doces_list_vermelho);//check vermelho especial

        funcao_aux_check4_esp(i,j,5,-5,n_doces_list_amarelo);//check amarelo especial
        funcao_aux_check3_esp(i,j,5,-5,n_doces_list_amarelo);//check amarelo especial

        funcao_aux_check4_esp(i,j,6,-6,n_doces_list_azul);
        funcao_aux_check3_esp(i,j,6,-6,n_doces_list_azul);
        
      
}

funcao_check_3(int i,int j){

/*-------------------------------VERTICAL3----------------------------------*/
    if(MAPA[i][j]==MAPA[i+1][j] && MAPA[i][j]==MAPA[i+2][j]){ //verifica se a primeira posição do trio e suas posições abaixo são iguais
        
        
        MAPA[i][j]=4; //atribui NADA à primeira posição
        MAPA[i+1][j]=4; //atribui NADA à segunda  posição
        MAPA[i+2][j]=4;// atribui nada à terceira posição
        vertical=true;
        funcao_cair_doces(3,i,j);
}
    
    vertical=false;
/*----------------------------------------------------------------------*/

/*-----------------------------HORIZONTAL3----------------------------------*/
if(MAPA[i][j]==MAPA[i][j+1] && MAPA[i][j]==MAPA[i][j+2]){
        //cout<<"horizontal3: "<<i+1<<" "<<j+1<<endl;
        MAPA[i][j]=4;
        MAPA[i][j+1]=4;
        MAPA[i][j+2]=4;
        horizontal=true;
        funcao_cair_doces(3,i,j);
        
    } 
    horizontal=false;
    
/*--------------------------------------------------------------------------*/
}
funcao_check_4(int i, int j){
    
/*-----------------------------VERTICAL4----------------------------------*/
if(MAPA[i][j]==MAPA[i+1][j] && MAPA[i][j]==MAPA[i+2][j]  && MAPA[i][j]==MAPA[i+3][j]){ 
                            
        aux_4=MAPA[i][j];
        MAPA[i][j]=4;
        MAPA[i+1][j]=4;
        MAPA[i+2][j]=4;
        MAPA[i+3][j]=4;
                            
        //cout<<"vertical4: "<<i+1<<" "<<j+1<<endl;
        vertical=true;
        funcao_cair_doces(4,i,j);

        if(listrado){
            funcao_cair_doce_listrado_vertical(aux_4, i, j);  //fazendo o doce ficar listrado
        }


    }
    vertical=false;

/*------------------------------------------------------------------------------*/

/*-----------------------------HORIZONTAL4----------------------------------*/
    if(  MAPA[i][j]==MAPA[i][j+1] && MAPA[i][j]==MAPA[i][j+2] && MAPA[i][j]==MAPA[i][j+3]){
        //cout<<"horizontal4: "<<i+1<<" "<<j+1<<endl;
        aux_5=MAPA[i][j];
        MAPA[i][j]=4;
        MAPA[i][j+1]=4;
        MAPA[i][j+2]=4;
        MAPA[i][j+3]=4;
        horizontal=true;

        funcao_cair_doces(4,i,j);

        if(listrado){
            
            funcao_cairDoce_listrado_horizontal(aux_5,Y_click_dir, X_click_dir); //fazendo o doce ficar listrado
        }
                            
    }
    horizontal=false;
/*------------------------------------------------------------------------------*/


}
funcao_check_5(int i, int j){
    
    if(MAPA[i][j]==MAPA[i+1][j] && MAPA[i][j]==MAPA[i+2][j]   &&   MAPA[i][j]==MAPA[i+3][j] && MAPA[i][j]==MAPA[i+4][j]){
        //cout<<"vertical5: "<<i+1<<" "<<j+1<<endl;
        MAPA[i][j]=4;
        MAPA[i+1][j]=4;
        MAPA[i+2][j]=4;
        MAPA[i+3][j]=4;
        MAPA[i+4][j]=4;

        
        
        vertical=true;
        funcao_cair_doces(5,i,j);
        
        
    }
    vertical=false;

    if((MAPA[i][j]==MAPA[i][j+1] && MAPA[i][j]==MAPA[i][j+2]   &&   MAPA[i][j]==MAPA[i][j+3] && MAPA[i][j]==MAPA[i][j+4])){
        //cout<<"horizontal5: "<<i+1<<" "<<j+1<<endl;
        MAPA[i][j]=4;
        MAPA[i][j+1]=4;
        MAPA[i][j+2]=4;

        MAPA[i][j+3]=4;
        MAPA[i][j+4]=4;
        horizontal=true;
    } 
        horizontal=false;
}
funcao_spawn_doces(){
    for (int i=11; i<18; i++){
        for (int j=0; j<5; j++){
            int auxteste;

            if(MAPA[i][j]==0){ //Se for 0, desenha a peça laranja
                    al_draw_bitmap(docesimpleslaranja,(j*q)+700,(i-11)*q,0);    
            }
            if(MAPA[i][j]==1){ //Se for 1, desenha a peça roxa;
                    al_draw_bitmap(docesimplesroxo,(j*q)+700,(i-11)*q,0); //função desenha
            }
            if(MAPA[i][j]==2){//Se for 2, desenha a peça verde;
                    al_draw_bitmap(docesimplesverde,(j*q)+700,(i-11)*q,0); //função desenha          
            }
            if(MAPA[i][j]==3){ //Se for 3, desenha a peça vermelha
                al_draw_bitmap(docesimplesvermelho,(j*q)+700,(i-11)*q,0);
                    
            }
            if(MAPA[i][j]==5){ //Se for 5, desenha a peça amarela;
                al_draw_bitmap(docesimplesamarelo,(j*q)+700,(i-11)*q,0); //função desenha
            }
            if(MAPA[i][j]==6){//Se for 6, desenha a peça azul;
                al_draw_bitmap(docesimplesazul,(j*q)+700,(i-11)*q,0); //função desenha
            }
            
            if(MAPA[i][j]==-8){
                al_draw_bitmap(especialhorizontallaranja,(j*q)+700,(i-11)*q,0);
            }

            if(MAPA[i][j]==-1){
                al_draw_bitmap(especialhorizontalroxo,(j*q)+700,(i-11)*q,0);
            }
            if(MAPA[i][j]==-2){
                al_draw_bitmap(especialhorizontalverde,(j*q)+700,(i-11)*q,0);
            }
            if(MAPA[i][j]==-3){
                al_draw_bitmap(especialhorizontalvermelho,(j*q)+700,(i-11)*q,0);
            }
            if(MAPA[i][j]==-5){
                al_draw_bitmap(especialverticalamarelo,(j*q)+700,(i-11)*q,0);
            }
            if(MAPA[i][j]==-6){
                al_draw_bitmap(especialverticalazul,(j*q)+700,(i-11)*q,0);
            }

            funcao_check_especial(i,j);
            funcao_check_5(i,j);              
            funcao_check_4(i,j);
            funcao_check_3(i,j); 
                
    
        }



    }
       
}
funcao_troca_doces(int y_esq, int x_esq, int y_dir, int x_dir ){
    if(abs(y_esq - y_dir)==1 || abs(x_esq-x_dir)==1 ){ //verifica se a diferença entre o primeiro click e o segundo click ==1;
            if(!(abs(y_esq - y_dir)==1 & abs(x_esq-x_dir)==1)){ //verifica se o segundo clkick está na diagonal, se as 2 coordenadas mudam ao mesmo tempo;
                if(moves<=definir_numero_de_movimentos_do_nivel){
                    
                    
                    aux_map=MAPA[y_esq][x_esq];       
                    MAPA[y_esq][x_esq]=MAPA[y_dir][x_dir];//posição do click esquerdo vai ser igual a posição do click direito;*
                    MAPA[y_dir][x_dir]=aux_map;//posição do click direito vai ser igual a posição do auxiliar*
                    moves++;
                }
                if(moves==definir_numero_de_movimentos_do_nivel){
                                cout<<"JOGO FECHADO"<<endl;
                                sair=true;
                                
                            }
     
            }
    }

}

int inicializa() {
    
    if(!al_init())
    {
        cout << "Falha ao carregar Allegro" << endl;
        return 0;
    }

    if(!al_install_keyboard())
    {
        cout << "Falha ao inicializar o teclado" << endl;
        return 0;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        cout << "Falha ao inicializar o temporizador" << endl;
        return 0;
    }

    if(!al_init_image_addon())
    {
        cout <<"Falha ao iniciar al_init_image_addon!" << endl;
        return 0;
    }
    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        cout << "Falha ao inicializar a tela" << endl;
        al_destroy_timer(timer);
        return 0;
    }

    mapa = al_load_bitmap("tapNivel2_oficial.bmp");
    if(!mapa)
    {
        cout << "Falha ao carregar o mapa!" << endl;
        al_destroy_display(display);
        return 0;
    }

    mouse=al_load_bitmap("CandyCrushResources/personagem.png"); 
    if(!al_install_mouse())
    {
        cout << "Falha ao inicializar o mouse" << endl;
        return 0;
    }



    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        cout << "Falha ao criar a fila de eventos" << endl;
        al_destroy_display(display);

        return 0;
    }
    menu = al_load_bitmap("Fundo3exp.bmp");
    if(!menu){
        cout << "FALHA AO CARREGAR O MENU" << endl;

        al_destroy_display(display);
        
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

    docesimplesazul = al_load_bitmap("docesimplesazul.bmp");
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

    img_menina_1 = al_load_bitmap("GirlFelizCandy.bmp");
    if(!brigadeiroespecial){
        std::cout << "Falha ao carregar brigadeiroespecial!" << std::endl;
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


int main(int argc, char **argv){
    
    
    
    
    if(!inicializa()) return -1;
    while(!sair){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
         if(ev.type == ALLEGRO_EVENT_TIMER)
        {
        
            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
            
            }
        }
	    //<------------------------------------------------------->

        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                sair = true; 
                break;
            }
        }
        else if(ev.type== ALLEGRO_EVENT_MOUSE_AXES) //SE PASSAR O PONTEIRO EM CIMA DO DISPLAY
        {
                mouse_x=(ev.mouse.x); //atribui os valores mouse_x e mouse_y ás coordenadas do mouse no display
                mouse_y=(ev.mouse.y);                
        }
        else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) //se der o click no mouse
        {
            if(ev.mouse.button & 1){ // &1 = botão esquerdo
                pressao=true;   //pressionado= TRUE
                if(pressao==true){
                    //cout<<Y_click_esq<<"OLHAesq "<< X_click_esq<<endl;
                   Y_click_esq=mouse_y/q+11;  //auxiliar guarda a coordenada X do último click;*
                   X_click_esq=mouse_x/q-6; //auxiliar guarda a coordenada X do último click; *   
                   
                }
                
                
            }
            if(ev.mouse.button & 2){ // &1 = botão direito
                
                pressao_dir=true;   //Se pressionar o botão direito, pressão dir= true
                
                if(pressao_dir==true){  
                    
                    Y_click_dir=mouse_y/q+11; //2 adicionado ÀS 09:47
                    X_click_dir=mouse_x/q-6;
                   
                    funcao_troca_doces(Y_click_esq,X_click_esq,Y_click_dir,X_click_dir);
                    
                   
                }

            } 
        }
        else if (ev.type== ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {       
                pressao=false;
                pressao_dir=false;
                              

        }
        if(redraw && al_is_event_queue_empty(event_queue)) //se REDRAW (redesenhar for true e a fila estiver vazia)
        {
            redraw = false;

            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_bitmap(menu, 0,0,0);
            al_draw_bitmap(mapa,700,100,0);
            al_draw_bitmap(img_menina_1,1300,100,0);
            
            
                //SPAWN DAS PEÇAS 
                
                funcao_spawn_doces();
        } 



        
       
            
        al_flip_display();
    
        
    }

        al_clear_to_color(al_map_rgb(0,255,0));
        
		al_flip_display();

	
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    
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