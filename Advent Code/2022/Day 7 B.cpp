#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> v;
struct nodo {
	string name;
	nodo* p=NULL;
	vector<nodo*> car;
	int w=0;
};

void calcular_peso(nodo* n) {
//	cout << n->name << " " << n->w << " ";
//	if(n->p!=nullptr) cout << n->p->name << endl;
//	else cout << endl;
//	if(n->name=="e") cout << n->w << endl;
	vector<nodo*> &car=n->car;
	for(size_t i=0;i<car.size();++i) { 
		calcular_peso(car[i]);
		n->w+=car[i]->w;
	}
	v.push_back(n->w);
}

int main() {
//	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	nodo raiz, *na;
	string str, pw, name;
	cin >> pw;
	while(cin >> str){
		if(str=="cd"){
			cin >> name;
			if(name==".."){
				cout << na->name << endl;
				na=na->p;
			}
			else{
				if(name=="/"){
					na=&raiz;
					na->name=name;
				}
				else{
					vector<nodo*> &car=na->car;
					for(size_t i=0;i<car.size();++i) { 
						if(car[i]->name==name)na=car[i];
					}
				}
			}
			cin >> pw;
		}
		else{
			while(cin >> str){
				if(str=="$")break;
				else if(str=="dir"){
					cin >> name;
					na->car.push_back(new nodo);
					na->car[na->car.size()-1]->name=name;
					na->car[na->car.size()-1]->p=na;
				}
				else{
					cin >> name;
					na->w+=stoi(str);
				}
			}
		}
	}
	calcular_peso(&raiz);
	int we=raiz.w-40000000, wt=INT_MAX, r;
	for(size_t i=0;i<v.size();++i) { 
		if(v[i]>we && wt>v[i]-we){
			wt=v[i]-we;
			r=v[i];
		}
	}
	cout << r << endl;
	return 0;
}

