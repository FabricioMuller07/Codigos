#include <bits/stdc++.h>
#include <windows.h>
#include "ConsolaFuente.h"
using namespace std;

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy();
void ConsoleTam();
void Color();
void CrearUI();
vector<pair<short,short>> GenerarPieza();
void Jugar();

int main() {
	CambiarFuente(h,15,15);
	ConsoleTam();
	CrearUI();
	Jugar();
	return 0;
}

void gotoxy(const short &x,const short &y) {SetConsoleCursorPosition(h,{x,y});}
void ConsoleTam() {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect); 
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 397, 400, TRUE);
}
void Color(string str,const int &id) {
	SetConsoleTextAttribute(h,id);
	cout << str;
	SetConsoleTextAttribute(h,7);
}
void CrearUI() {
	for(int j=1;j<=22;++j){
		for(int i=1;i<=25;++i){
			if((i>0 && i<8) || (i>18) || (j==1) || (j==22))Color(" ",136);
			else cout << " ";
		}
		if(j!=41)cout << endl;
	}
}
vector<pair<short,short>> GenerarPieza(vector<vector<bool>> &v){
	short p=rand()%7+1;
	if(p==1){
		
	}
	return {{0,0}};
}
void Jugar(){
	vector<vector<bool>> v(20,vector<bool>(10));
	vector<pair<short,short>> pieza(4);
	while(true){
		pieza=GenerarPieza(v);
		
	}
}
