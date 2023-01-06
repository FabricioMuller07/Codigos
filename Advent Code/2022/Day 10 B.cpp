#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<bool>> v(6,vector<bool>(40,0));
int i=0, j=0;
void draw(int &t, int &s) {
	cout << t << " " << s << endl;
	if(j%40==s-1 || j%40==s || j%40==s+1) v[i][j]=1;
	j++;
	if(j==40){i++;j=0;}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int t=0, n, s=1;
	while(cin >> str){
		if(str=="noop"){draw(++t,s);}
		else{
			cin >> n;
			draw(++t,s);
			draw(++t,s);
			s+=n;
		}
	}
	
	for(int i=0;i<6;++i) { 
		for(int j=0;j<40;++j) { 
			if(v[i][j])cout << "#";
			else cout << ".";
		}cout << endl;
	}
	
	return 0;
}

