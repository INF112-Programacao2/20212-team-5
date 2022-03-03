#ifndef PONTUACAO_H
#define PONTUACAO_H

namespace Pontuacao {
    class Pontos {
        protected:
            int pontuacao;
            int movRestantes;
        public:
            int pontuacao();
            int objRestantes();
            int movrestantes();
            int fimDaFase();
    };

};

#endif
