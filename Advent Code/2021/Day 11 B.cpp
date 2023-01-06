#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int c=0;
void imprimir(vector<vector<int>> &v,int k);
void DFD(vector<vector<int>> &v, vector<vector<bool>> &visit, int i, int j) {
	visit[i][j]=1; v[i][j]=0; ++c;
	if(i>0 && visit[i-1][j]==0){
		++v[i-1][j];
		if(v[i-1][j]>9) DFD(v,visit,i-1,j);
	}
	if(i>0 && j>0 && visit[i-1][j-1]==0){
		++v[i-1][j-1];
		if(v[i-1][j-1]>9) DFD(v,visit,i-1,j-1);
	}
	if(i>0 && j<9 && visit[i-1][j+1]==0){
		++v[i-1][j+1];
		if(v[i-1][j+1]>9) DFD(v,visit,i-1,j+1);
	}
	
	if(i<9 && visit[i+1][j]==0){
		++v[i+1][j];
		if(v[i+1][j]>9) DFD(v,visit,i+1,j);
	}
	if(i<9 && j>0 && visit[i+1][j-1]==0){
		++v[i+1][j-1];
		if(v[i+1][j-1]>9) DFD(v,visit,i+1,j-1);
	}
	if(i<9 && j<9 && visit[i+1][j+1]==0){
		++v[i+1][j+1];
		if(v[i+1][j+1]>9) DFD(v,visit,i+1,j+1);
	}
	
	
	if(j>0 && visit[i][j-1]==0){
		++v[i][j-1];
		if(v[i][j-1]>9) DFD(v,visit,i,j-1);
	}
	if(j<9 && visit[i][j+1]==0){
		++v[i][j+1];
		if(v[i][j+1]>9) DFD(v,visit,i,j+1);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	vector<vector<int>> v(10,vector<int>(10)); char num; int k=0;
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			cin >> num;
			v[i][j]=num-48;
		}
	}
	while(true){
		for(int i=0;i<10;++i){
			for(int j=0;j<10;++j){
				++v[i][j];
			}
		}
		vector<vector<bool>> visit(10,vector<bool>(10,0));
		c=0;
		for(int i=0;i<10;++i){
			for(int j=0;j<10;++j){
				if(v[i][j]>9)DFD(v,visit,i,j);
			}
		}
		
		if(c==100){cout << k << endl; break;}
		else k++;
		
//		imprimir(v,k);
		
	}
	cout << c << endl;
	return 0;
}

void imprimir(vector<vector<int>> &v,int k){
	cout << k << ":" << endl;
	cout << "============" << endl;
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			cout << v[i][j];
		}cout << endl;
	}
	cout << "============" << endl;
}
	
