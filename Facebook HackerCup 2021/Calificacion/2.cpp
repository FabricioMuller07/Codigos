#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

int main() {
	freopen("xs_and_os_input.txt","r",stdin);
	freopen("output2.txt","w",stdout);
	int cases, tam, pt, cant, cant_min, c; bool t;
	cin >> cases;
	for(int k=0;k<cases;++k){
		cin >> tam;
		vector<vector<char>> v(tam,vector<char>(tam)); pt=1;
		vector<pair<int,int>> coords;
		for(int i=0;i<tam;++i){
			for(int j=0;j<tam;++j){
				cin >> v[i][j];
			}
		}
		cant_min=INT_MAX;
		for(int i=0;i<tam;++i){
			cant=0; t=1;
			for(int j=0;j<tam;++j){
				if(v[i][j]=='.') cant++;
				else if(v[i][j]=='O'){
					t=0;break;
				}
			}
			if(t && cant_min==cant) c++;
			else if(t && cant<cant_min && cant!=0){
				c=1; cant_min=cant;
			}
		}
		for(int i=0;i<tam;++i){
			cant=0; t=1;
			for(int j=0;j<tam;++j){
				if(v[j][i]=='.') cant++;
				else if(v[j][i]=='O'){
					t=0;break;
				}
			}
			if(t && cant_min==cant){
				if(cant==1){
					int pos=0, pos2=0;
					for(int j=0;j<tam;++j){
						if(v[j][i]=='.') pos=j;
					}
					for(int j=0;j<tam;++j){
						if(v[pos][j]=='.') pos2=j;
					}
					if(pos2!=pos) c++;
				}
				else c++;
			}
			else if(t && cant<cant_min && cant!=0){
				c=1; cant_min=cant;
			}
		}
		if(cant_min==INT_MAX) cout << "Case #" << k+1 << ": " << "Impossible" << endl;
		else cout << "Case #" << k+1 << ": " << cant_min << " " << c << endl;
	}
	return 0;
}

