#pragma once

#ifndef SERVICE_H
#define SERVICE_H

#include <SFML/Graphics.hpp>
#include "mainwindow.h"

#include <chrono>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <cstdlib>

using namespace sf;


struct row {
    int x;
    int y;
};


void ShellSort(int*, int);
void GnomeSort(int*, int);
void fillArray(row*, int*, int);
void shellSortStep(row*, int, int&, int&, int&);
void gnomSortStep(row*, int&, int);
void exit(RenderWindow&, Event&);
void toDraw(RenderWindow&, RectangleShape&, row*, int, int, int, int);

void mainPart(int, int*, int); // Сама программа

int countIntegers(const std::string&);
int* extractNumbers(const std::string&);
std::string arrayToString(int*, int);

#endif // SERVICE_H
