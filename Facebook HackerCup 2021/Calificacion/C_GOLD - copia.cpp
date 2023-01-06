#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;



ll DFD(ll padre, ll nodo, vector<vector<ll>> rela, vector<ll> gold, vector<ll> &camino){
	gold[padre]=0;
	camino.push_back(nodo);
	for(size_t i=0;i<rela[padre].size();++i){
		if(rela[padre][i]==nodo){
			rela[padre].erase(rela[padre].begin()+i);
			break;
		}
	}
	for(size_t i=0;i<rela[nodo].size();++i){
		if(rela[nodo][i]==padre){
			rela[nodo].erase(rela[nodo].begin()+i);
			break;
		}
	}
	
	ll max_val=0, pos=camino.size(), valor_actual=0, ult_pos=0;
	for(int i=0;i<rela[nodo].size();++i){
		valor_actual=DFD(nodo,rela[nodo][i],rela,gold,camino);
		if(valor_actual>max_val){
			max_val=valor_actual;
			for(size_t j=1;j<camino.size();++j){
				if(rela[nodo][i]==camino[pos]) break;
				else camino.erase(camino.begin()+pos);
			}
			ult_pos=camino.size();
		}
		else{
			camino.erase(camino.begin()+ult_pos,camino.end());
		}
	}
	return max_val+gold[nodo];
}
	
int main(){
//	freopen("gold_mine_chapter_1_input.txt","r",stdin);
//	freopen("output4F.txt","w",stdout);
	ll cases, n, a, b, kveces;
	cin >> cases;
	for(int k=0;k<cases;++k){
		cin >> n >> kveces;
		vector<ll> gold(n);
		vector<vector<ll>> rela(n);
		for(int i=0;i<n;++i){
			cin >> gold[i];
		}
		for(int i=0;i<n-1;++i){
			cin >> a >> b;
			rela[a-1].push_back(b-1);
			rela[b-1].push_back(a-1);
		}
		
		ll max_val=0, valor_actual=0, ult_pos=0, FFF;
		for(int z=0;z<kveces;++z){
			for(int i=0;i<rela[0].size();++i){
				valor_actual=DFD(0,rela[0][i],rela,gold,camino);
				if(valor_actual>max_val){
					max_val=valor_actual;
					for(size_t j=1;j<camino.size();++j){
						if(rela[0][i]==camino[1]) break;
						else{
							camino.erase(camino.begin()+1);
						}
					}
					ult_pos=camino.size();
				}
				else{
					camino.erase(camino.begin()+ult_pos,camino.end());
				}
			}
			FFF+=max_val+gold[0];
			for(size_t i=0;i<camino.size()-1;++i){
				gold[camino[i]]=0;
				for(size_t j=0;j<rela[camino[i]].size();++j){
					if(rela[camino[i]][j]==camino[i+1]){
						rela[camino[i]].erase(rela[camino[i]].begin()+j);
						break;
					}
				}
				for(size_t j=0;j<rela[camino[i+1]].size();++j){
					if(rela[camino[i+1]][j]==camino[i]){
						rela[camino[i+1]].erase(rela[camino[i+1]].begin()+j);
						break;
					}
				}
			}
		}
		cout << "Case #" << k+1 << ": " << FFF << endl;
	}
	return 0;
}
