#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

int main(){
//		freopen("runway_validation_input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	int cases, n, m, respuesta, cant, cd;
	cin >> cases;
	for(int k=0;k<cases;++k){
		cin >> n >> m;
		vector<pair<int,int>> v(m);
		vector<vector<bool>> u(n,vector<bool>(m,0));
		vector<vector<int>> ronda(n,vector<int>(m)), aux;
		for(int i=0;i<m;++i){
			cin >> v[i].first;
			v[i].second=0;
		}
		respuesta=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin >> ronda[i][j];
			}
		}
		aux=ronda;
		// se fija las iguales en la primera ronda
		for(int i=0;i<m;++i){
			for(int j=0;j<m;++j){
				if(u[0][j]==0 && ronda[0][i]==v[j].first){
					u[0][j]=1;
					ronda[0][i]=-1;
					break;
				}
			}
		}
		//se fija las iguales de las primeras rondas, en las siguientes rondas
		for(int i=1;i<n;++i){
			for(int j=0;j<m;++j){
				for(int z=0;z<m;++z){
					if(u[i-1][z]==1 && u[i][z]==0 && ronda[i][j]==v[z].first){
						u[i][z]=1;
						ronda[i][j]=-1;
						v[z].second++;
						break;
					}
				}
			}
		}
		cd=cant=0;
		for(int i=0;i<m;++i){
			if(v[i].second==n){
				cd++;
				
			}
		}
		
		
		for(int i=1;i<n;++i){
			for(int j=0;j<m;++j){
				for(int z=0;z<m;++z){
					if(ronda[i][j]==ronda[i-1][z]){
						ronda[i-1][j]=-1;
						aux[i][j]=-1;
					}
				}
			}
			for(int j=0;j<m;++j){
				if(aux[i][j]!=-1) cant++;
			}
		}
		cout << cd << " " << cant << endl;
		respuesta=max(cant-cd,0);
		
		cout << "aca" << endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout << aux[i][j] << " ";
			}
			cout << endl;
		}
		cout << "aca" << endl;
		cout << "Case #" << k+1 << ": " << respuesta << endl;
	}
	return 0;
}
	
	
