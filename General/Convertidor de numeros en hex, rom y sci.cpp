#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	string b;
	string selec;
	Seleccion:{
		cout << "Ingrese:" << endl;
		cout << "'Hex' para convertir un numero a hexadecimal" << endl;
		cout << "'NoCie' para expresar un nuemero en notacion cientifica" << endl;
		cout << "'Rom' para expresar un numero en numeros romanos" << endl;
		cout << "'E' para salir del programa" << endl;
		cin >> selec;
		system("cls");
		if(selec=="Hex"){
			long long int nh;
			cout << "Ingrese el numero a convertir: ";
			cin >> nh;
			cout << "El numero: " << nh << " En Hexadecimal es: ";
			cout << hex << uppercase << nh << endl;
		}
		else if(selec=="NoCie"){
			long double Notn;
			cout << "Ingrese el numero a convertir: ";
			cin >> Notn;
			cout << "El numero ingresado en Notacion cientifica es: ";
			cout << fixed << setprecision(2) << scientific << Notn << endl;
		}
		else if(selec=="Rom"){
			int x;
			cout << "Ingrese el numero a convertir: ";
			cin >> x;
			cout << "El numero ingresado en Numeros Romanos es: ";
			if(x>=1000){cout<<"M"; x=x-1000;}
			if(x>=900){cout<<"CM"; x=x-900;}
			if(x>=500){cout<<"D";  x=x-500;}
			if(x>=400){cout<<"CD"; x=x-400;}
			if(x>=300){cout<<"C"; x=x-100;}
			if(x>=200){cout<<"C"; x=x-100;}
			if(x>=100){cout<<"C"; x=x-100;}
			if(x>=90){cout<<"XC"; x=x-90;}
			if(x>=50){cout<<"L"; x=x-50;}
			if(x>=40){cout<<"XL"; x=x-40;}
			if(x>=30){cout<<"X"; x=x-10;}
			if(x>=20){cout<<"X"; x=x-10;}
			if(x>=10){cout<<"X"; x=x-10;}
			if(x>=9){cout<<"IX"; x=x-9;}
			if(x>=5){cout<<"V"; x=x-5;}
			if(x>=4){cout<<"IV"; x=x-4;}
			if(x>=3){cout<<"III"; x=x-3;}
			if(x>=2){cout<<"II"; x=x-2;}
			if(x>=1){cout<<"I"; x=x-1;}
			cout << endl;
		}
		else if(selec=="E") goto Exit;
		else{
			cout << "Opcion ingresada incorrecta" << endl;
			goto Seleccion;
		}
		
		cout << endl;
		cout << "Ingrese cualquier tecla para continuar" << endl;
		cin >> b;
		system("cls");
		goto Seleccion;
	}
	Exit:
	return 0;
}

