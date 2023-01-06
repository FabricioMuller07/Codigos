#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Viborita.h"
#include "funciones.h"
using namespace std;

class Juego{
	int gridX, gridY;
	pair<int,int> comida;
	Viborita V;
public:
	Juego(int tamx, int tamy);
	void Start();
	int Direccion_Inicial();
	void CrearLimites();
	bool DetectarColision();
	void Finalizar();
	void GenerarComida();
};

#endif

