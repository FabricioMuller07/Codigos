#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int r=0;
vector<int> v={20,60,100,140,180,220};
void ver_tiempo(int &t, int &s) {
	if(v.size()>0 && t>=v[0]){
		cout << s << " " << v[0] << endl;
		r+=s*v[0];
		v.erase(v.begin());
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int t=0, n, s=1;
	while(cin >> str){
		if(str=="noop"){
			t++;
			ver_tiempo(t,s);
		}
		else{
			cin >> n;
			t+=2; 
			ver_tiempo(t,s);
			s+=n;
		}
	}
	cout << r << endl;
	return 0;
}

