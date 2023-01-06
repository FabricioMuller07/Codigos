#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>> v(99,vector<int>(99));

int evaluar(int &x, int &y) {
	int m1=0, m2=0, m3=0, m4=0;
	for(int i=x-1;i>=0;--i) { 
		if(v[i][y]<v[x][y])m1++;
		else{m1++;break;}
	}
	for(int i=x+1;i<99;++i) { 
		if(v[i][y]<v[x][y])m2++;
		else{m2++;break;}
	}
	
	for(int i=y-1;i>=0;--i) { 
		if(v[x][i]<v[x][y])m3++;
		else{m3++;break;}
	}
	for(int i=y+1;i<99;++i) { 
		if(v[x][i]<v[x][y])m4++;
		else{m4++;break;}
	}
	return m1*m2*m3*m4;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	char tree; int r=0;
	for(int i=0;i<99;++i){
		for(int j=0;j<99;++j){
			cin >> tree;
			v[i][j]=tree-'0';
		}
	}
	
	
	for(int i=1;i<98;++i) { 
		for(int j=1;j<98;++j) { 
			r=max(r,evaluar(i,j));
		}
	}
	
	cout << r << endl;
	return 0;
}

