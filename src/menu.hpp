#ifndef MENU_H
#define MENU_H

#include "allegro.cpp"

#include "main.hpp"

class Menu {
    private:
        bool estadoMusica = true;
    public:
        void mainmenu();
        void pausarInicio();
        //void pausarNivel();
        void escolherNivel();
        void somDoJogo();
        
};

#endif