#include "Viborita.h"

Viborita::Viborita(){}

void Viborita::Crear(){
	posiciones.push_front({posVibora.x,posVibora.y});
	gotoxy(posVibora.x,posVibora.y);
	letra_color('*',170);
}
void Viborita::Avanzar(){
	CambiarDireccion(detectar_direccion(direccion));
	if(direccion==1)posVibora.y--;
	else if(direccion==2)posVibora.y++;
	else if(direccion==3)posVibora.x++;
	else if(direccion==4)posVibora.x--;
	posiciones.push_front({posVibora.x,posVibora.y});
	gotoxy(posVibora.x,posVibora.y);
	lugares[{posVibora.x,posVibora.y}]=1;
	letra_color('*',170);
	if(longitud==tamanio){
		pair<int,int> p=posiciones.back();
		lugares[{p.first,p.second}]=0;
		gotoxy(p.first,p.second);
		cout << " ";
		posiciones.pop_back();
	}
	else longitud++;
}
bool Viborita::Choque(){
	pair<int,int> p=posiciones.front();
	if(direccion==1)p.second--;
	else if(direccion==2)p.second++;
	else if(direccion==3)p.first++;
	else if(direccion==4)p.first--;
	if(lugares[p]==true) return true;
	else return false;
}
void Viborita::SumarPunto(){
	tamanio++;
	puntos++;
}
void Viborita::CambiarDireccion(int dir){
	if(dir!=0) direccion=dir;
}
pair<int,int> Viborita::DarPos(){return {posVibora.x,posVibora.y};}
int Viborita::DarDir(){return direccion;}
