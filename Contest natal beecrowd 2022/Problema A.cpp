#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	vector<vector<char>> v(8,vector<char>(8));
	int c;
	for(int i=0;i<8;++i) { 
		for(int j=0;j<8;++j) { 
			cin >> v[i][j];
		}
	}
	for(int i=0;i<8;++i) { 
		for(int j=0;j<8;++j) { 
			if(v[i][j]=='.'){
				c=0;
				if(i+2<8 && j-1>=0 && v[i+2][j-1]=='*') c++;
				if(i+2<8 && j+1<8 && v[i+2][j+1]=='*') c++;
				if(i+1<8 && j+2<8 && v[i+1][j+2]=='*') c++;
				if(i+1<8 && j-2>=0 && v[i+1][j-2]=='*') c++;
				if(i-2>=0 && j+1<8 && v[i-2][j+1]=='*') c++;
				if(i-2>=0 && j-1>=0 && v[i-2][j-1]=='*') c++;
				if(i-1>=0 && j+2<8 && v[i-1][j+2]=='*') c++;
				if(i-1>=0 && j-2>=0 && v[i-1][j-2]=='*') c++;
				v[i][j]=c+'0';
			}
			
		}
	}
	for(int i=0;i<8;++i) { 
		for(int j=0;j<8;++j) { 
			cout << v[i][j];
		}cout << endl;
	}
	return 0;
}

