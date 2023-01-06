#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct dato_nodo{
	int dato;
	dato_nodo *izq=NULL,*der=NULL;
};
class BST{
public:
	void insertar_nodo(int &nuevo_nodo, dato_nodo &raiz){
		if(nuevo_nodo<raiz.dato){
			if(raiz.izq==NULL){
				raiz.izq = new dato_nodo;
				raiz.izq->dato=nuevo_nodo;
			}
			else insertar_nodo(nuevo_nodo, *raiz.izq);
		}
		else{
			if(raiz.der==NULL){
				raiz.der = new dato_nodo;
				raiz.der->dato=nuevo_nodo;
			}
			else insertar_nodo(nuevo_nodo, *raiz.der);
		}
	}
	// PRE
	void Hacer_pre(int &cantidad, dato_nodo &raiz){
		int c=0;
		printf("Pre.: ");
		Imprimir_pre(c,cantidad, raiz);
	}
	void Imprimir_pre(int &c, int &cantidad, dato_nodo &raiz){
		if(c==cantidad-1) printf("%i\n",raiz.dato+1);
		else printf("%i ",raiz.dato+1);
		c++;
		if(raiz.izq!=NULL) Imprimir_pre(c,cantidad,*raiz.izq);
		if(raiz.der!=NULL) Imprimir_pre(c,cantidad,*raiz.der);
	}
	// IN
	void Hacer_in(int &cantidad, dato_nodo &raiz){
		int c=0;
		printf("In..: ");
		Imprimir_in(c,cantidad, raiz);
	}
	void Imprimir_in(int &c, int &cantidad, dato_nodo &raiz){
		if(raiz.izq!=NULL) Imprimir_in(c,cantidad,*raiz.izq);
		if(c==cantidad-1) printf("%i\n",raiz.dato+1);
		else printf("%i ",raiz.dato+1);
		c++;
		if(raiz.der!=NULL) Imprimir_in(c,cantidad,*raiz.der);
	}
	// POST
	void Hacer_post(int &cantidad, dato_nodo &raiz){
		int c=0;
		printf("Post: ");
		Imprimir_post(c,cantidad, raiz);
	}
	void Imprimir_post(int &c, int &cantidad, dato_nodo &raiz){
		if(raiz.izq!=NULL) Imprimir_post(c,cantidad,*raiz.izq);
		if(raiz.der!=NULL) Imprimir_post(c,cantidad,*raiz.der);
		if(c==cantidad-1) printf("%i\n",raiz.dato+1);
		else printf("%i ",raiz.dato+1);
		c++;
	}
	void Limpiar(dato_nodo &raiz){
		delete(raiz.izq);
		delete(raiz.der);
		raiz.izq=NULL;
		raiz.der=NULL;
	}
};

int main(){
	int cases, cant_nodos, raiz, nodo;
	dato_nodo nodo_raiz;
	BST B;
	scanf("%i",&cases);
	for(int k=0;k<cases;++k){
		scanf("%i",&cant_nodos);
		cin >> raiz;
		raiz--;
		nodo_raiz.dato=raiz;
		for(int i=1;i<cant_nodos;++i) { 
			scanf("%i",&nodo);
			nodo--;
			B.insertar_nodo(nodo, nodo_raiz);
		}
		printf("Case %i:\n",k+1);
		B.Hacer_pre(cant_nodos, nodo_raiz);
		B.Hacer_in(cant_nodos, nodo_raiz);
		B.Hacer_post(cant_nodos, nodo_raiz);
		printf("\n");
		B.Limpiar(nodo_raiz);
	}
	return 0;
}

