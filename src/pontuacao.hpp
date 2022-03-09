#ifndef PONTUACAO_H
#define PONTUACAO_H

class Pontos {
        int pontuacao = 0;
        int objrestantes = 50;
        int movRestantes = 50;
    public:
        int getPontuacao();
        void setPontuacao(int i);
        void aumentarPontuacao(int i);
        void diminuirPontuacao(int i);

        int getObjRestantes();
        void setObjRestantes(int i);
        void aumentarObjRestantes();
        void diminuirObjRestantes();
        
        int getMovRestantes();
        void setMovRestantes(int i);
        void aumentarMovRestantes();
        void diminuirMovRestantes();

        void escrevePontuacao(ALLEGRO_FONT *font);
        void escreveObjRestantes(ALLEGRO_FONT *font);
        void escreveMovRestantes(ALLEGRO_FONT *font);
    
};

#endif
