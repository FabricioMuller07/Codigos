#include "Juego.h"
void hidecursor();

Juego::Juego(int tamx, int tamy) : gridX(tamx), gridY(tamy){}

void Juego::Start(){
	CrearLimites();
	GenerarComida();
	V.Crear();
	V.CambiarDireccion(Direccion_Inicial());
	while(true){
		if(DetectarColision()==true) {Finalizar(); break;}
		V.Avanzar();
		Sleep(50);
	}
}
bool Juego::DetectarColision(){
	pair<int,int> pos=V.DarPos();
	if(V.Choque()) return true;
	else if(pos.first==119|| pos.second==29 ||pos.first==0 || pos.second==0)return true;
	else if(pos.first==comida.first && pos.second==comida.second){
		V.SumarPunto();
		GenerarComida();
	}
	return false;
}
void Juego::Finalizar(){
	system("cls");
	cout << "RIP." << endl;
}
void Juego::GenerarComida(){
	comida.first=rand()%100+10;
	comida.second=rand()%20+5;
	gotoxy(comida.first,comida.second);
	letra_color('O',68);
}
void Juego::CrearLimites(){
	for(int i=0;i<120;i++){gotoxy(i,0);letra_color('#',119);}
	for(int i=0;i<120;i++){gotoxy(i,29);letra_color('#',119);}
	for(int i=0;i<29;i++){gotoxy(0,i);letra_color('#',119);}
	for(int i=0;i<29;i++){gotoxy(119,i);letra_color('#',119);}
}
int Juego::Direccion_Inicial(){
	getch();
	return detectar_direccion(V.DarDir());
}
