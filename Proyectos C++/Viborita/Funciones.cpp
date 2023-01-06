#include "Funciones.h"


void gotoxy(int x,int y){  
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}
void hidecursors(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}		
int detectar_direccion(int dir){
	Sleep(40);
	if(GetAsyncKeyState(VK_UP) && dir!=2) dir=1; // ARRIBA
	if(GetAsyncKeyState(VK_RIGHT) && dir!=4) dir=3; // DERECHA
	if(GetAsyncKeyState(VK_DOWN) && dir!=1) dir=2; // ABAJO
	if(GetAsyncKeyState(VK_LEFT) && dir!=3) dir=4; // IZQUIERDA	
	return dir;
}
void letra_color(char letra, int color){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	cout << letra;
	color=7;
	SetConsoleTextAttribute(hConsole, color);
}
