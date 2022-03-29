CC=g++
CFLAGS=-o CandyCrush

CPFLAGS=-lallegro -lallegro_image -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec
DELETAVEIS=main.o inicializa.o allegro.o menu.o nivel.o poder.o pontuacao.o tabuleiro.o mapa.o



all: main

main: main.o inicializa.o allegro.o menu.o nivel.o poder.o pontuacao.o tabuleiro.o mapa.o
		${CC} ${CFLAGS} main.o ${CPFLAGS}

main.o: main.cpp
		${CC} -c main.cpp

inicializa.o: inicializa.cpp
		${CC} -c inicializa.cpp

allegro.o: allegro.cpp
		${CC} -c allegro.cpp
		
menu.o: menu.cpp
		${CC} -c menu.cpp
		
nivel.o: nivel.cpp
		${CC} -c nivel.cpp
		
poder.o:  poder.cpp
		${CC} -c poder.cpp

pontuacao.o: pontuacao.hpp pontuacao.cpp
		${CC} -c pontuacao.cpp

tabuleiro.o: tabuleiro.hpp tabuleiro.cpp
		${CC} -c tabuleiro.cpp


mapa.o: mapa.hpp mapa.cpp
		${CC} -c mapa.cpp

release:
		powershell.exe ./release.sh
    
clean:
		-del ${DELETAVEIS}
