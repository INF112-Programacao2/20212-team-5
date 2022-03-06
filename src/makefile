CC=g++
CFLAGS=-o CandyCrush
CPFLAGS=-lallegro -lallegro_image -lallegro_font -lallegro_ttf
DELETAVEIS=main.o inicializa.o allegro.o menu.o nivel.o poder.o pontuacao.o CandyCrush.exe

all: main

main: main.o inicializa.o allegro.o menu.o nivel.o poder.o pontuacao.o 
		${CC} ${CFLAGS} main.o ${CPFLAGS}

main.o: main.cpp
		${CC} ${CFLAGS} -c main.cpp 

inicializa.o: inicializa.cpp
		${CC} ${CFLAGS} -c inicializa.cpp

allegro.o: allegro.cpp
		${CC} ${CFLAGS} -c allegro.cpp
		
menu.o: menu.cpp
		${CC} ${CFLAGS} -c menu.cpp
		
nivel.o: nivel.cpp
		${CC} ${CFLAGS} -c nivel.cpp
		
poder.o:  poder.cpp
		${CC} ${CFLAGS} -c poder.cpp

pontuacao.o: pontuacao.hpp pontuacao.cpp
		${CC} ${CFLAGS} -c pontuacao.cpp

clean:
		-del ${DELETAVEIS}
