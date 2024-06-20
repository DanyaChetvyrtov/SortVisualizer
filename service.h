#pragma once

#ifndef SERVICE_H
#define SERVICE_H


#include <SFML/Graphics.hpp>
#include "mainwindow.h""

#include <chrono>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <cstdlib>

using namespace sf;


const int ARRAY_SIZE = 800;


struct row {
    int x;
    int y;
};


void ShellSort(int*, int);
void GnomeSort(int*, int);
void fillArray(row*, int);
void shellSortStep(row*, int&, int&, int&);
void gnomSortStep(row*, int&);
void exit(RenderWindow&, Event&);
void toDraw(RenderWindow&, RectangleShape&, row*, int, int);

void mainPart(int); // Сама программа


int countIntegers(const std::string&);
int* extractNumbers(const std::string&, int&);

#endif // SERVICE_H
