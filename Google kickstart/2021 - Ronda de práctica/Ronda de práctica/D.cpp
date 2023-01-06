#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<vector<char>> v;

void buscar(vector<vector<bool>> &visit, int x, int y, int n_f){
	
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int t, n, b, r, flagb, flagr;
	cin >> t;
	for(int k=1;k<=t;++k) { 
		cout << "Case #" << k << ": ";
		cin >> n;
		v=vector<vector<char>>(n,vector<char>(n));
		b=r=0;
		for(int i=0;i<n;++i) { 
			for(int j=0;j<n;++j) { 
				cin >> v[i][j];
				if(v[i][j]=='B')b++;
				if(v[i][j]=='R')r++;
			}
		}
		if(b>r+1 || r>b+1) cout << "Impossible" << endl;
		else{
			vector<vector<bool>> visit1(n,vector<bool>(n)), visit2(n,vector<bool>(n));
			for(int i=0;i<n;++i) { 
				if(v[0][i]=='R')buscar(visit1,i,0,n,);
			}
		}
	}
	return 0;
}

