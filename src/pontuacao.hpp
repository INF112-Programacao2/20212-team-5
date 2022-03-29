#ifndef PONTUACAO_H
#define PONTUACAO_H

class Pontos {
    private:
        int pontuacao = 0;
        int objrestantes = 50;
        int movRestantes = 50;
    public:
        /* Pontuação geral */
        int getPontuacao();
        void setPontuacao(int i);
        void aumentarPontuacao(int i);
        void diminuirPontuacao(int i);
        /* Objetivos restantes */
        int getObjRestantes();
        void setObjRestantes(int i);
        void aumentarObjRestantes();
        void diminuirObjRestantes();
        /* Movimentos restantes */
        int getMovRestantes();
        void setMovRestantes(int i);
        void aumentarMovRestantes();
        void diminuirMovRestantes();
        /* Funções de escrita */
        void escrevePontuacao(ALLEGRO_FONT *font);
        void escreveObjRestantes(ALLEGRO_FONT *font);
        void escreveMovRestantes(ALLEGRO_FONT *font);
        void escreverFase(ALLEGRO_FONT *font, int fase);
        void escreverFaseMenu(ALLEGRO_FONT *font, int fase);
    
};

class PontosDoce : public Pontos {
    protected:
        int pontosDoces[6] = {2,2,2,2,2,2};
        double multiplicador[8] = {1, 1.2, 1.7, 1.9, 3.2, 4.5, 7.2, 10};
    public:
        void pontosDoce(int escolha, int multiplicador);
};

#endif
