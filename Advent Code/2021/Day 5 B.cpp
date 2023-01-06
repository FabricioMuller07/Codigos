#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int max_valx=0, max_valy=0;

struct recta{
	int x1, y1;
	int x2, y2;
};

bool es_45(recta &a){
	if(abs(a.x2-a.x1) == abs(a.y2-a.y1)) return 1;
	else return 0;
}
double dist(int &x, int &y){
	return sqrt(double(x*x)+double(y*y));
}
void Lectura(vector<recta> &v){
	string str, aux; int pos=0, vp=0;
	while(getline(cin,str)){
		v.push_back({});
		while(str[pos]>='0' && str[pos]<='9'){
			aux+=str[pos];++pos;
		}
		v[vp].x1=stoi(aux);aux.clear();pos++;
		while(str[pos]>='0' && str[pos]<='9'){
			aux+=str[pos];++pos;
		}
		v[vp].y1=stoi(aux);aux.clear();
		while(str[pos]<'0' || str[pos]>'9'){++pos;}
		while((str[pos]>='0' && str[pos]<='9')){
			aux+=str[pos];++pos;
		}
		v[vp].x2=stoi(aux);aux.clear();pos++;
		while((str[pos]>='0' && str[pos]<='9')){
			aux+=str[pos];++pos;
		}
		v[vp].y2=stoi(aux);aux.clear();pos=0;
		if(v[vp].x1!=v[vp].x2 && v[vp].y1 != v[vp].y2 && !es_45(v[vp])) v.erase(v.end()-1);
		else{
			max_valx=max(max(v[vp].x1,v[vp].x2),max_valx);
			max_valy=max(max(v[vp].y1,v[vp].y2),max_valy);
			++vp;
		}
	}
}
void Marcar_mapa(recta &a, vector<vector<int>> &m){
	int inicio, fin, x, y, j=0;
	if(a.x1==a.x2){inicio=min(a.y1,a.y2);fin=max(a.y1,a.y2);}
	else if(a.y1==a.y2){inicio=min(a.x1,a.x2);fin=max(a.x1,a.x2);}
	else{
		inicio=0; fin=abs(a.x1-a.x2);
		if(a.y1<a.y2){x=a.x1;y=a.y1;}
		else{x=a.x2;y=a.y2;}
	}
	for(int i=inicio;i<=fin;++i){
		if(a.x1==a.x2)m[i][min(a.x1,a.x2)]++;
		else if(a.y1==a.y2)m[min(a.y1,a.y2)][i]++;
		else{
			m[y+i][x+j]++;
			if(x==a.x1 && a.x1>a.x2)j--;
			else if(x==a.x1 && a.x1<a.x2)j++;
			else if(x==a.x2 && a.x2>a.x1)j--;
			else j++;
		}
	}
}
	
void Imprimir_mapa(vector<vector<int>> &m){
	for(size_t i=0;i<m.size();++i){
		for(size_t j=0;j<m[i].size();++j){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
int Contar_mapa(vector<vector<int>> &m){
	int c=0;
	for(size_t i=0;i<m.size();++i){
		for(size_t j=0;j<m[i].size();++j){
			if(m[i][j]>1)c++;
		}
	}
	return c;
}
	
int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	vector<recta> v;
	Lectura(v);
	vector<vector<int>> mapa(max_valy+1,vector<int>(max_valx+1));
	
	for(size_t i=0;i<v.size();++i){
		Marcar_mapa(v[i],mapa);
	}
	
	Imprimir_mapa(mapa);
	
	int c=Contar_mapa(mapa);
	
	cout << c << endl;
	
	return 0;
}
