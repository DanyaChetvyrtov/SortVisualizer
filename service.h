#pragma once

#ifndef SERVICE_H
#define SERVICE_H


#include <SFML/Graphics.hpp>


using namespace sf;


const int ARRAY_SIZE = 800;


struct row {
    int x;
    int y;
};


void fillArray(row*, int);
void shellSortStep(row*, int&, int&, int&);
void gnomSortStep(row*, int&);
void exit(RenderWindow&, Event&);
void toDraw(RenderWindow&, RectangleShape&, row*, int, int);

void mainPart(int); // Сама программа

#endif // SERVICE_H
