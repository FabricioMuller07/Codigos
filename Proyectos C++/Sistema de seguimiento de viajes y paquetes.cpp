#include <iostream>
#include <ctime>
#include <cstdlib>
#include<conio.h>
using namespace std;

int main() {
	char seg;
	string des, p1, p, vi, hora, horas, mins, codv;
	srand(time(NULL));
	Seguimiento:
		cout << "Hora acutal: 15:00" << endl;
		cout << "Ingrese 'P' si quiere hacer el seguimiento de un PAQUETE" << endl;
		cout << "Ingrese 'V' si quiere hacer el seguimiento de un VIAJE" << endl;
		cout << "Ingrese 'E' para salir del programa" << endl;
		cin >> seg;
	if(seg == 'P'){
		Paquete:
			system("cls");
			cout << "Ingrese el codigo de seguimiento del paquete" << endl;
			cout << "ingrese 'S' para volver a la seleccion de seguimiento" << endl;
			cin >> p;
			if(p == "GH123" or p == "FT312" or p == "OG531"){
				system("cls");
				if(p == "GH123")cout << "El envio aun no ha salido aun de " << endl;
				else if(p == "FT312") cout << "El envio a llegado a la terminal de para ser retirado" << endl;
				else if (p == "OG531"){
					cout << "El envio esta en curso" << endl;
					cout << "Informacion del envio:" << endl;
					if(rand()%2+1==1){
						cout << "El envio tiene un adelanto de " << rand()%5+1 << " hora(s)" << endl;
					}
					else{
						cout << "El envio tiene un atraso de " << rand()%5+1 << " hora(s)" << endl;
					}
					
					if(rand()%2+1==1){
						cout << "Llegara en " << rand()%2+1 << " Dia(s)" << endl;
					}
					else{
						cout << "Llegara en " << rand()%10+1 << " hora(s)" << endl;
					}
				}
				
				cout << endl;
				cout << "ingrese cualquier tecla para continuar" << endl;
				getch();
				system("cls");
				Opcion2:
				cout << "Ingrese 'C' para ingresar un nuevo codigo" << endl; 
				cout << "Ingrese 'S' para volver a la seleccion de seguimiento" << endl;
				cout << "Ingrese 'E' para salir del programa" << endl;
				cin >> p;
				if(p == "S"){
					system("cls");
					goto Seguimiento;
				}
				else if(p == "C")goto Paquete;
				else if(p == "E") goto Exit;
				else{
					system("cls");
					cout << "Opcion ingresada no valida, vuelva a intentarlo" << endl;
					goto Opcion2;
				}
			}
			else if(p == "S"){
				system("cls");
				goto Seguimiento;
			}
			else{
				system("cls");
				cout << "Codigo ingresado es incorrecto" << endl;
				Opcion3:
				cout << "Ingrese 'C' para ingresar nuevamente el codigo" << endl; 
				cout << "Ingrese 'S' para volver a la seleccion de seguimiento" << endl;
				cin >> p;
				if(p == "S"){
					system("cls");
					goto Seguimiento;
				}
				else if(p == "C"){
					goto Paquete;
				}
				else{
					system("cls");
					cout << "Opcion ingresada no valida, vuelva a intentarlo" << endl;
					goto Opcion3;
				}
			}
	}
	else if(seg == 'V'){
		system("cls");
		Opcion:
		cout << "Eliga el destino" << endl;
		cout << "'B' para Buenos Aires, Retiro" << endl;
		cout << "'BT' para Buenos Aires, Talar" << endl;
		cout << "'C' para Cordoba, Capital" << endl;
		cout << "'CR' para Cordoba, Rio Cuarto" << endl;
		cout << "'M' para Mendoza, 'Terminal del Sol'" << endl;
		cout << "'ML' para Mendoza, Lujan de Cuyo" << endl;
		cout << "Ingrese 'S' para volver a la seleccion de seguimiento" << endl;
		cin >> des;
		system("cls");
		if(des == "S"){
			goto Seguimiento;
		}
		if(des == "B" or des == "BT") goto HorariosB;
		if(des == "C" or des == "CR") goto HorariosC;
		if(des == "M" or des == "ML") goto HorariosM;
		else{
			cout << "Opcion ingresada no valida, vuelva a intentarlo" << endl;
			goto Opcion;
		}
	}
	else if(seg == 'E') goto Exit;
	else{
		system("cls");
		cout << "Opcion ingresada no valida, vuelva a intentarlo" << endl;
		goto Seguimiento;
	}
	
	HorariosB:{
		cout << "Los horarios a Buenos Aires son:" << endl;
		cout << "01:00 AM" << endl;
		cout << "05:00 AM" << endl;
		cout << "10:00 AM" << endl;
		cout << "15:00 PM" << endl;
		cout << "19:00 PM" << endl;
		cout << "23:00 PM" << endl;
		cout << "Seleccione un horario ingresando 'xx:xx'" << endl;
		cout << "Ingrese 'V' para volver a la seleccion de destino" << endl;
		cout << "Ingrese 'S' para volver a la seleccion de seguimiento" << endl;
		cin >> hora;
		if(hora == "V"){
			system("cls");
			goto Opcion;
		}
		else if(hora == "S"){
			system("cls");
			goto Seguimiento;
		}
		else if(hora!="01:00" and hora!="05:00" and hora!="10:00" and hora!="15:00" and hora!="19:00" and hora!="23:00"){
			system("cls");
			cout << "Horario ingresado es incorrecto" << endl;
			goto HorariosM;
		}
		system("cls");
		goto info;
	}
	HorariosC:{
		cout << "Los horarios a Cordoba son:" << endl;
		cout << "01:30 AM" << endl;
		cout << "05:30 AM" << endl;
		cout << "10:30 AM" << endl;
		cout << "15:30 PM" << endl;
		cout << "19:30 PM" << endl;
		cout << "23:30 PM" << endl;
		cout << "Seleccione un horario ingresando 'xx:xx'" << endl;
		cout << "Ingrese 'V' para volver a la seleccion de destino" << endl;
		cout << "Ingrese 'S' para volver a la seleccion de seguimiento" << endl;
		cin >> hora;
		if(hora == "V"){
			system("cls");
			goto Opcion;
		}
		else if(hora == "S"){
			system("cls");
			goto Seguimiento;
		}
		else if(hora!="01:30" and hora!="05:30" and hora!="10:30" and hora!="15:30" and hora!="19:30" and hora!="23:30"){
			system("cls");
			cout << "Horario ingresado es incorrecto" << endl;
			goto HorariosM;
		}
		system("cls");
		goto info;
	}
	HorariosM:{
		cout << "Los horarios a Mendoza son:" << endl;
		cout << "02:00 AM" << endl;
		cout << "06:00 AM" << endl;
		cout << "11:00 AM" << endl;
		cout << "16:00 PM" << endl;
		cout << "20:00 PM" << endl;
		cout << "Seleccione un horario ingresando 'xx:xx'" << endl;
		cout << "Ingrese 'V' para volver a la seleccion de destino" << endl;
		cout << "Ingrese 'S' para volver a la seleccion de seguimiento" << endl;
		cin >> hora;
		if(hora == "V"){
			system("cls");
			goto Opcion;
		}
		else if(hora == "S"){
			system("cls");
			goto Seguimiento;
		}
		else if(hora!="02:00" and hora!="06:00" and hora!="11:00" and hora!="16:00" and hora!="20:00"){
			system("cls");
			cout << "Horario ingresado es incorrecto" << endl;
			goto HorariosM;
		}
		system("cls");
		goto info;
	}
	info:{
		cout << "Ingrese el codigo ubicado en el pasaje junto a su numero de asiento" << endl;
		cout << "Ingrese 'S' para volver a la seleccion de seguimiento" << endl;
		cout << "Ingrese 'V' para volver a la seleccion de destinos" << endl;
		cin >> codv;
		if(codv=="AP312"){
			system("cls");
			if(des == "B" or des == "BT"){
				if(hora=="01:00" or hora=="05:00") cout << "El colectivo a llegado a destino" << endl;
				if(hora=="15:00" or hora=="10:00"){
					if(hora=="15:00"){
						if(rand()%10+1<7) cout << "El colectivo esta saliendo de destino en este momento" << endl;
						else cout << "El colectivo esta con 15 minutos de atraso" << endl;
					}
					else{
						cout << "El colectivo llegara en: 0:31 hs" << endl;
						cout << "Lleva recorrido: 5:00 hs" << endl;
						cout << "La velocidad promedio es de 98 km/h" << endl;
						cout << "Lleva recorrido un total de 429 KM" << endl;
						cout << "Le faltan recorrer 62 KM" << endl;
						cout << "Paradas restantes 0" << endl;
					}
				}
				if(hora=="19:00" or hora=="23:00") cout << "El colectivo aun no a salido de terminal" << endl;
			}
			if(des == "C" or des == "CR"){
				if(hora=="01:30" or hora=="05:30") cout << "El colectivo a llegado a destino" << endl;
				else if(hora=="10:30"){
					cout << "El colectivo llegara en 0:35 hs" << endl;
					cout << "Lleva recorrido: 4:00 hs" << endl;
					cout << "La velocidad promedio es de 109 km/h" << endl;
					cout << "Lleva recorrido un total de 290 KM" << endl;
					cout << "Le faltan recorrer 59 KM" << endl;
					cout << "Paradas restantes 0" << endl;
				}
				else if(hora=="23:30" or hora=="19:30") cout << "El colectivo aun no a salido de terminal" << endl;
			}
			if(des == "M" or des == "ML"){
				if(hora=="02:00") cout << "El colectivo a llegado a destino" << endl;
				else if(hora=="06:00"){
					cout << "El colectivo llegara en 2:29 hs" << endl;
					cout << "Lleva recorrido: 11:00 hs" << endl;
					cout << "La velocidad promedio es de 99 km/h" << endl;
					cout << "Lleva recorrido un total de 700 KM" << endl;
					cout << "Le faltan recorrer 200 KM" << endl;
					cout << "Paradas restantes 2" << endl;
				}
				else if(hora=="11:00"){
					cout << "El colectivo llegara en 7:00 hs" << endl;
					cout << "Lleva recorrido: 4:00 hs" << endl;
					cout << "La velocidad promedio es de 103 km/h" << endl;
					cout << "Lleva recorrido un total de 305 KM" << endl;
					cout << "Le faltan recorrer 695 KM" << endl;
					cout << "Paradas restantes 7" << endl;
				}
				else cout << "El colectivo aun no ha salido de terminal" << endl;
			}
			cout << endl;
			cout << "Ingrese cualquier tecla para continuar" << endl;
			cin >> p1;
			system("cls");
			Opcion4:{
				cout << "Ingrese 'V' para volver a la seleccion de viajes" << endl; 
				cout << "Ingrese 'S' para volver a la seleccion de seguimiento" << endl;
				cout << "Ingrese 'E' para salir del programa" << endl;
				cin >> p;
				if(p == "S"){
					system("cls");
					goto Seguimiento;
				}
				else if(p == "V"){
					system("cls");
					goto Opcion;
				}
				else if(p == "E") goto Exit;
				else{
					system("cls");
					cout << "Opcion ingresada no valida, vuelva a intentarlo" << endl;
					goto Opcion4;
				}
			}
		}
		else if(codv == "V"){
			system("cls");
			goto Opcion;
		}
		else if(codv == "S"){
			system("cls");
			goto Seguimiento;
		}
		else{
			system("cls");
			cout << "Codigo incorrecto, intente nuevamente" << endl;
			goto info;
		}
	}
	Exit:
		system("Cls");
		cout << endl;
		cout << "Gracias por utilizar nuestro servicio. BUEN VIAJE" << endl;
	return 0;
}
