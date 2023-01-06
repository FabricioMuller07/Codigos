#ifndef VIBORITA_H
#define VIBORITA_H
#include "funciones.h"
#include <iostream>
#include <deque>
#include <map>
using namespace std;

struct punto{ int x, y;};

class Viborita{
	deque<pair<int,int>> posiciones;
	map<pair<int,int>,bool> lugares;
	int tamanio=4, longitud=1, puntos=0;
	punto posVibora={60,14};
	int direccion=0;
	
public:
	Viborita();
	void Crear();
	void CambiarDireccion(int dir);
	void Avanzar();
	void SumarPunto();
	bool Choque();
	pair<int,int> DarPos();
	int DarDir();
};

#endif

