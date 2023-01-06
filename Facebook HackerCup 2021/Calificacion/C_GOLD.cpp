#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

int DFD(int padre, int nodo, vector<vector<int>> rela, vector<int> gold){
	gold[padre]=0;
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
	
	int max_val=0;
	for(int i=0;i<rela[nodo].size();++i){
		max_val=max(max_val,DFD(nodo,rela[nodo][i],rela,gold));
		
	}
	
	return max_val+gold[nodo];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int cases, n, a, b;
	cin >> cases;
	for(int k=0;k<cases;++k){
		cin >> n;
		vector<int> gold(n);
		vector<vector<int>> rela(n);
		for(int i=0;i<n;++i){
			cin >> gold[i];
		}
		for(int i=0;i<n-1;++i){
			cin >> a >> b;
			rela[a-1].push_back(b-1);
			rela[b-1].push_back(a-1);
		}
		
		int max_val=0;
		for(int i=0;i<rela[0].size();++i){
			max_val=max(max_val,DFD(0,rela[0][i],rela,gold));
		}
		cout << max_val << endl;
	}
	return 0;
}

