#ifndef MAPA_CPP
#define MAPA_CPP

#include "main.hpp"
#include "mapa.hpp"
#include "pontuacao.cpp"
#include "poder.cpp"


int Mapa::getCoordenada(int x, int i){
    return this->MAPA[x][i];
}

int Mapa::clearCoordenada(){
    for (int i=11; i<17; i++){
        for (int j=0; j<7; j++){
            this->MAPA[i][j] = 0;
        }
    }
}

//int Mapa::setCoordenada(int escolha){
//    switch(escolha){
//        case 1:
//            for (int i=11; i<17; i++){
//                for (int j=0; j<7; j++){
//                    this->MAPA[i][j] = mapaUm[i][j];
//                }
//            }
//            break;
//        case 2:
//            for (int i=11; i<17; i++){
//                for (int j=0; j<7; j++){
//                    this->MAPA[i][j] = mapaDois[i][j];
//                }
//            }
//            break;
//        default:
//            for (int i=11; i<17; i++){
//                for (int j=0; j<7; j++){
//                    this->MAPA[i][j] = mapaUm[i][j];
//                }
//            }
//            break;
//
//    }
//    
//}

void Mapa::funcao_cair_doce_listrado_vertical(int x, int y){// 4 FAZ 1 LISTRADO
    if(aux_4==0){MAPA[x+3][y]=8;}
    if(aux_4==1){MAPA[x+3][y]=-1;}
    if(aux_4==2){MAPA[x+3][y]=-2;}
    if(aux_4==3){MAPA[x+3][y]=-3;}
    if(aux_4==5){MAPA[x+3][y]=-5;}
    if(aux_4==6){MAPA[x+3][y]=-6;}

}

void Mapa::funcao_cairDoce_listrado_horizontal(int aux_5,int y_dir, int x_dir){ //4 FAZ 1 LISTRADO
    
    if(aux_5==0){MAPA[y_dir][x_dir]=8;}
    if(aux_5==1){MAPA[y_dir][x_dir]=-1;}
    if(aux_5==2){MAPA[y_dir][x_dir]=-2;}
    if(aux_5==3){MAPA[y_dir][x_dir]=-3;}
    if(aux_5==5){MAPA[y_dir][x_dir]=-5;}
    if(aux_5==6){MAPA[y_dir][x_dir]=-6;}

}

int Mapa::funcao_cair_doces(int check_type, int x, int y){
       
       int aux;
       int aux2;
       int aux3;
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
             }
            if(horizontal){
                for(int k=0; x-k>=0;k++){
                   // cout<<"x-k= "<<x-k<<endl;
                    MAPA[x-k][y+3]=MAPA[x-k-1][y+3];
                    MAPA[x-k][y+2]=MAPA[x-k-1][y+2];
                    MAPA[x-k][y+1]=MAPA[x-k-1][y+1];
                    MAPA[x-k][y]=MAPA[x-k-1][y];
                }
            } 
        }
         if(check_type==5){
             if(vertical){
                
                std::cout<<x<<" "<<y<<" da função"<<std::endl;  
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

int Mapa::funcao_aux_check3_esp(int i, int j, int tipo_positivo, int tipo_listrado, int &n_doces){
         
        
        /*-----------CONDIÇÃO PARA SER UM TRIO LISTRADO VERTICAL--------------------*/
        if(  (MAPA[i][j]==tipo_listrado && MAPA[i+1][j]==tipo_positivo && MAPA[i+2][j]==tipo_positivo ) ||   (MAPA[i][j]==tipo_positivo && MAPA[i+1][j]==tipo_listrado && MAPA[i+2][j]==tipo_positivo)  || (MAPA[i][j]==tipo_positivo && MAPA[i+1][j]==tipo_positivo && MAPA[i+2][j]==tipo_listrado )   ){ //verifica se a primeira posição do trio e suas posições abaixo são iguais   

            n_doces++;
            

             
          
           
        vertical=true; 
            
        funcao_cair_doces(6,i,j);

        }
        vertical=false;
/*-------------------------------FIM VERTICAL -----------------------------------*/


/*----------------------------TRIO HORIZONTAL_VERTICAL---------------------------*/

       if( (MAPA[i][j]==tipo_listrado && MAPA[i][j+1]==tipo_positivo && MAPA[i][j+2]==tipo_positivo ) ||   (MAPA[i][j]==tipo_positivo && MAPA[i][j+1]==tipo_listrado && MAPA[i][j+2]==tipo_positivo)  || (MAPA[i][j]==tipo_positivo && MAPA[i][j+1]==tipo_positivo && MAPA[i][j+2]==tipo_listrado ) ){ //verifica se a primeira posição do trio e suas posições abaixo são iguais
            n_doces++;
            
            
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

        //if(n_doces_list_lar==2 && n_doces_list_roxo==2){
        //    nivel_completo=true;
        //    sair=true;
//
        //} 

}

int Mapa::funcao_aux_check4_esp(int i, int j, int tipo_positivo, int tipo_listrado, int &n_doces){
    
    
    /*---------------------------------VERTICAL------------------------*/
    if( 
    (MAPA[i][j]==tipo_listrado && MAPA[i+1][j]==tipo_positivo && MAPA[i+2][j]==tipo_positivo && MAPA[i+3][j]==tipo_positivo )||
    (MAPA[i][j]==tipo_positivo && MAPA[i+1][j]==tipo_listrado && MAPA[i+2][j]==tipo_positivo && MAPA[i+2][j]==tipo_positivo)||
    (MAPA[i][j]==tipo_positivo && MAPA[i+1][j]==tipo_positivo && MAPA[i+2][j]==tipo_listrado && MAPA[i+2][j]==tipo_positivo)|| 
    (MAPA[i][j]==tipo_positivo && MAPA[i+1][j]==tipo_positivo && MAPA[i+2][j]==tipo_positivo && MAPA[i+3][j]==tipo_listrado)  
    ){
        
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
        
        n_doces++;
        horizontal=true;
         funcao_cair_doces(6,i,j);
    }
    horizontal=false;


}
int Mapa::funcao_check_especial(int i, int j){
          
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

void Mapa::funcao_check_4(int i, int j, Pontos &pontos){
    if(  MAPA[i][j]==MAPA[i+1][j] && MAPA[i][j]==MAPA[i+2][j]  && MAPA[i][j]==MAPA[i+3][j] ){ 
                            
        aux_4 = MAPA[i][j];
        MAPA[i][j]=4;
        MAPA[i+1][j]=4;
        MAPA[i+2][j]=4;
        MAPA[i+3][j]=4;
                            
        //cout<<"vertical4: "<<i+1<<" "<<j+1<<endl;
        vertical=true;
        pontos.aumentarPontuacao(2);
        funcao_cair_doces(4,i,j);
        if(listrado){
            funcao_cair_doce_listrado_vertical(i, j);  //fazendo o doce ficar listrado
        }

    }
    vertical=false;

    if(  MAPA[i][j]==MAPA[i][j+1] && MAPA[i][j]==MAPA[i][j+2] && MAPA[i][j]==MAPA[i][j+3]){
        //cout<<"horizontal4: "<<i+1<<" "<<j+1<<endl;
        MAPA[i][j]=4;
        MAPA[i][j+1]=4;
        MAPA[i][j+2]=4;
        MAPA[i][j+3]=4;
        horizontal=true;
        pontos.aumentarPontuacao(2);
        funcao_cair_doces(4,i,j);
        if(listrado){
            funcao_cairDoce_listrado_horizontal(aux_5,Y_click_dir, X_click_dir); //fazendo o doce ficar listrado
        }
    }
    horizontal=false;
}
void Mapa::funcao_check_5(int i, int j, Pontos &pontos){
    
    if(MAPA[i][j]==MAPA[i+1][j] && MAPA[i][j]==MAPA[i+2][j]   &&   MAPA[i][j]==MAPA[i+3][j] && MAPA[i][j]==MAPA[i+4][j]){
        //cout<<"vertical5: "<<i+1<<" "<<j+1<<endl;
        MAPA[i][j]=4;
        MAPA[i+1][j]=4;
        MAPA[i+2][j]=4;

        MAPA[i+3][j]=4;
        MAPA[i+4][j]=4;
        vertical=true;
        pontos.aumentarPontuacao(3);
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
        pontos.aumentarPontuacao(3);
    } 
        horizontal=false;
}

void Mapa::funcao_check_3(int i,int j, Pontos &pontos){
    if(MAPA[i][j]==MAPA[i+1][j] && MAPA[i][j]==MAPA[i+2][j]){
        //cout<<"vertical3: "<<i+1<<" "<<j+1<<endl;
        
        MAPA[i][j]=4;
        MAPA[i+1][j]=4;
        MAPA[i+2][j]=4;
        vertical=true;
        pontos.aumentarPontuacao(1);
        funcao_cair_doces(3,i,j);
        
        
        
    }
    vertical=false;

    if(MAPA[i][j]==MAPA[i][j+1] && MAPA[i][j]==MAPA[i][j+2]){
        //cout<<"horizontal3: "<<i+1<<" "<<j+1<<endl;
        MAPA[i][j]=4;
        MAPA[i][j+1]=4;
        MAPA[i][j+2]=4;
        horizontal=true;
        pontos.aumentarPontuacao(1);
        funcao_cair_doces(3,i,j);
        
    } 
    horizontal=false;

}

void Mapa::funcao_troca_doces(int y_esq, int x_esq, int y_dir, int x_dir, Pontos &pontos){
    if(abs(y_esq - y_dir)==1 || abs(x_esq-x_dir)==1 ){ //verifica se a diferença entre o primeiro click e o segundo click ==1;
            if(!(abs(y_esq - y_dir)==1 & abs(x_esq-x_dir)==1)){ //verifica se o segundo clkick está na diagonal, se as 2 coordenadas mudam ao mesmo tempo;
                if(moves<=pontos.getMovRestantes()){
                    
                    std::cout << y_esq << " " << y_dir << std::endl;

                    aux_map=MAPA[y_esq][x_esq];       
                    MAPA[y_esq][x_esq]=MAPA[y_dir][x_dir];//posição do click esquerdo vai ser igual a posição do click direito;*
                    MAPA[y_dir][x_dir]=aux_map;//posição do click direito vai ser igual a posição do auxiliar*
                    moves++;
                    pontos.diminuirMovRestantes();
                }
                if(moves==pontos.getMovRestantes()){
                                std::cout<<"PERDEU"<<std::endl;
                                sair=true;
                                
                            }
     
            }
    }

}



#endif