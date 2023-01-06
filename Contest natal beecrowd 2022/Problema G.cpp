#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct ad{
	string s;
	int v, x;
};

bool cmp(const ad &a, const ad &b){
	if(a.v<b.v) return 1;
	else if(a.v==b.v){
		return a.x>b.x;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	vector<ad> v(a);
	for(int i=0;i<a;++i) { 
		cin >> v[i].s >> v[i].v >> v[i].x;
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<a && b>0;++i) { 
		if(v[i].v<=b){cout << v[i].s << endl;b-=v[i].v;}
		else b=0;
	}
	return 0;
}

