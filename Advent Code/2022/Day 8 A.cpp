#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>> v(99,vector<int>(99));

bool evaluar(int &x, int &y) {
	int m1=0, m2=0, m3=0, m4=0;
	for(int i=0;i<x;++i) { 
		m1=max(m1,v[i][y]);
	}
	for(int i=x+1;i<99;++i) { 
		m2=max(m2,v[i][y]);
	}
	for(int i=0;i<y;++i) { 
		m3=max(m3,v[x][i]);
	}
	for(int i=y+1;i<99;++i) { 
		m4=max(m4,v[x][i]);
	}
	if(m1<v[x][y] || m2<v[x][y] || m3<v[x][y] || m4<v[x][y]) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	char tree; int c=97*4+4;
	for(int i=0;i<99;++i){
		for(int j=0;j<99;++j){
			cin >> tree;
			v[i][j]=tree-'0';
		}
	}
	
	for(int i=1;i<98;++i) { 
		for(int j=1;j<98;++j) { 
			c+=evaluar(i,j);
		}
	}
	
	cout << c << endl;
//	cout << "asd" << endl;
//	for(int i=0;i<99;++i){
//		for(int j=0;j<99;++j){
//			cout << v[i][j];
//		}cout << endl;
//	}
	return 0;
}

