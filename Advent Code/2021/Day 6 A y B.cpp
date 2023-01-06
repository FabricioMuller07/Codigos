#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	ll num, c=0, aux, sum=0; char trash;
	freopen("input.txt","r",stdin);
	
	map<int,ll> m;
	
	while(cin >> num){
		m[num]++;
		cin >> trash;
	}
	
	while(c!=256){
		aux=m[0];
		for(int i=0;i<8;++i){
			m[i]=m[i+1];
		}
		m[6]+=aux;
		m[8]=aux;
		c++;
	}
	for(map<int,ll>::iterator it=m.begin();it!=m.end();++it){
		sum+=it->second;
	}
	cout << sum << endl;
	return 0;
}
