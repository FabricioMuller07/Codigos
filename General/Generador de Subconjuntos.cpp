#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, c=0;
list<list<int>> subconjuntos;
list<int> l;
void generador_recursivo(vector<int> &v, int index){
	c++;
	subconjuntos.push_back(l);
	for(int i=index;i<n;++i) { 
		l.push_back(v[i]);
		generador_recursivo(v,i+1);
		l.pop_back();
	}
}


int main() {
	cout << "Ingrese cantidad de elementos del conjunto" << endl;
	cin >> n;
	cout << "Ingrese elementos del conjunto" << endl;
	vector<int> v(n);
	for(int i=0;i<n;++i) { 
		cin >> v[i];
	}
	generador_recursivo(v,0);
	cout << "cantidad de subconjuntos: " << c << endl;
	cout << "subconjuntos:" << endl;
	for(auto it=subconjuntos.begin(); it!=subconjuntos.end(); ++it ) { 
		for(auto itt=it->begin(); itt!=it->end(); ++itt ) { 
			cout << *itt << " ";
		}cout << endl;
	}
	return 0;
}
