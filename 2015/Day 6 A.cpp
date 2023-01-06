#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	vector<vector<bool>> v(1000,vector<bool>(1000));
	string str, s; int x1, y1, x2, y2, c=0; char t;
	while(cin >> str){
		if(str=="turn"){
			cin >> s >> x1 >> t >> y1 >> str >> x2 >> t >> y2;
			if(s=="on"){
				for(int i=x1;i<=x2;++i) { 
					for(int j=y1;j<=y2;++j) { 
						v[i][j]=1;
					}
				}
			}
			else{
				for(int i=x1;i<=x2;++i) { 
					for(int j=y1;j<=y2;++j) { 
						v[i][j]=0;
					}
				}
			}
		}
		else{
			cin >> x1 >> t >> y1 >> str >> x2 >> t >> y2;
			for(int i=x1;i<=x2;++i) { 
				for(int j=y1;j<=y2;++j) { 
					v[i][j]=!v[i][j];
				}
			}
		}
	}
	
	for(int i=0;i<1000;++i) { 
		for(int j=0;j<1000;++j) { 
			if(v[i][j]) c++;
		}
	}
	cout << c << endl;
	return 0;
}

