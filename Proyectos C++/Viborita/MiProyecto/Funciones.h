#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <windows.h>
#include <iostream>
using namespace std;

void gotoxy(int x,int y);
void hidecursors();
int detectar_direccion(int dir);
void letra_color(char letra, int color);
#endif
