#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct nino{
	string name;
	char r;
	int d;
};

bool cmp(const nino &a, const nino &b){
	if(a.r<b.r) return 1;
	else if(a.r==b.r){
		if(a.d<b.d) return 1;
		else if(a.d==b.d) return a.name<b.name;
	}
	return 0;
}
	
	int main() {
		ios_base::sync_with_stdio(false);cin.tie(nullptr);
		int n;
		cin >> n;
		vector<nino> v(n);
		for(int i=0;i<n;++i) { 
			cin >> v[i].name >> v[i].r >> v[i].d;
		}
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<n;++i) { 
			cout << v[i].name << endl;
		}
		return 0;
	}
	
	
