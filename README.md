# Physics-Engine
Simple Physics Engine using the SFML graphics library

Compile commands:\
g++ -Isrc/include -c main.cpp game.cpp entity.cpp\
g++ main.o game.o entity.o -o sfml-app -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
