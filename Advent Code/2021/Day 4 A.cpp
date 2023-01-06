#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class tablero{
	vector<int> t;
	vector<bool> marcas;
	int m=0;
public:
	tablero(){
		t.resize(25);
		marcas.resize(25);
	};
	void insertar(int val, int x, int y){t[5*y+x]=val;}
	bool marcar(int val){
		m++;
		for(size_t i=0;i<t.size();++i){
			if(t[i]==val)marcas[i]=1;
		}
		if(m>4) return comprobar();
		return false;
	}
	bool comprobar(){
		int c;
		for(int i=0;i<5;++i){
			c=0;
			for(int j=0;j<5;++j){
				if(marcas[i*5+j]==1) c++;
			}
			if(c==5) return true;
		}
		for(int i=0;i<5;++i){
			c=0;
			for(int j=0;j<5;++j){
				if(marcas[i+j*5]==1) c++;
			}
			if(c==5) return true;
		}
		return false;
	}
	void imprimir(){
		cout << endl;
		for(int i=0;i<5;++i){
			for(int j=0;j<5;++j){
				cout << t[i*5+j] << " ";
			}cout << endl;
		}
		cout << endl;
	}
	int suma(){
		int s=0;
		for(int i=0;i<25;++i){
			if(marcas[i]==0) s+=t[i];
		}
		return s;
	}
};

int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int num, sum=0, tab=0, p=0; char trash; string str;
	vector<int> valores;
	map<int,set<int>> m;
	vector<tablero> v;
	getline(cin,str);
	stringstream ss(str);
	while(ss >> num){
		valores.push_back(num);
		ss >> trash;
	}
	while(cin >> num){
		v.resize(v.size()+1);
		m[num].insert(tab);
		p=1;
		v[tab].insertar(num,0,0);
		for(int i=0;i<5;++i){
			for(int j=p;j<5;++j){
				cin >> num;
				m[num].insert(tab);
				v[tab].insertar(num,j,i);
			}
			p=0;
		}
		tab++;
	}
	int last_value=-1;
	for(size_t i=0;i<valores.size();++i){
		auto it = m.find(valores[i]);
		if(it!=m.end()){
			for(auto it1=(it->second).begin();it1!=(it->second).end();++it1){
				if(v[*it1].marcar(valores[i])){sum=v[*it1].suma();last_value=valores[i];break;}
			}
			(it->second).clear();
		}
		if(last_value!=-1) break;
	}
	
	cout << sum*last_value << endl;
	
	return 0;
}
	
