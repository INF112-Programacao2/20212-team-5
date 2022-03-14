1_ O tabuleiro é desenhado mas o MENU não.

2_Como a imagem do tabuleiro é 8x8, a matriz MAPA é definida como [8][8].
3_Vai sortear um valor de 0 a 2, que está definindo o tipo da peça. // não definitivo, apenas teste.
4_Vai fazer o spawn da peça de acordo com a leitura da matriz e do tipo de peça, e da coordenada;
5_Cada quadrado do tabuleiro tem +ou- uns 62bits, as coordenadas e as imagens das peças devem ser ajustadas.

6_ Movimento das peças: 
    -> Click botão esquerdo, define a  primeira coordenada
    -> Click botão direito, define a segunda coordenada, faz a verificação das condições e faz a troca.    
    -> A troca é feita mudando o valor do MAPA[x][y] (0,1,2);


7_Função Gravidade
    '4' foi definido para quando não tiver uma peça,  o if(MAPA[i][j]==4) vai verificar se tem um espaço em branco, e assim, vai começar a "cair as peças"

    