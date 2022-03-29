#ifndef MAPA_CPP
#define MAPA_CPP

#include "main.hpp"
#include "mapa.hpp"
#include "pontuacao.cpp"
#include "poder.cpp"


int Mapa::getCoordenada(int x, int i){
    return this->MAPA[x][i];
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

}

void Mapa::funcao_check_4(int i, int j, Pontos &pontos){
    if(  MAPA[i][j]==MAPA[i+1][j] && MAPA[i][j]==MAPA[i+2][j]  && MAPA[i][j]==MAPA[i+3][j] ){ 
                            
    
        MAPA[i][j]=4;
        MAPA[i+1][j]=4;
        MAPA[i+2][j]=4;
        MAPA[i+3][j]=4;
                            
        //cout<<"vertical4: "<<i+1<<" "<<j+1<<endl;
        vertical=true;
        pontos.aumentarPontuacao(2);
        funcao_cair_doces(4,i,j);


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