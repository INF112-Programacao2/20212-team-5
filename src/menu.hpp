#ifndef MENU_H
#define MENU_H

#include "allegro.cpp"

#include "main.hpp"

class Menu {
    private:
        //const char *Iniciar = "Iniciar";
        bool _sairJogo = false;
    public:
        int mainmenu();
        int telaPause();
        //void somDoJogo();
};

#endif