#ifndef PONTUACAO_H
#define PONTUACAO_H

class Pontos {
        int pontuacao = 0;
        int objrestantes = 0;
        int movRestantes = 0;
    public:

        int getPontuacao();
        int addPontuacao(int i);
        void setObjRestantes(int i);
        int getObjRestantes();
        void diminuirObjRestantes();
        void removePontuacao(int i);
        void aumentarObjRestantes();
        void escrevePontuacao(ALLEGRO_FONT *font);
        void escreveObjRestantes(ALLEGRO_FONT *font);
        void escreveMovRestantes(ALLEGRO_FONT *font);
        int movrestantes();
        int fimDaFase();
};

#endif
