#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str, trash, a, b, aux;
	cin >> str;
	map<string, string> m;
	while(cin >> a >> trash >> b){
		m[a]=b;
	}
	for(int i=0;i<40;++i){
		for(size_t i=0;i<str.size()-1;++i){
			aux=str[i];aux+=str[i+1];
			auto it=m.find(aux);
			if(it!=m.end()){
				str.insert(i+1,it->second);++i;
			}
		}
	}
	map<char,ll> cont; ll maxv=0,minv=LLONG_MAX;
	for(size_t i=0;i<str.size();++i){
		++cont[str[i]];
		maxv=max(cont[str[i]],maxv);
	}
	for(auto it=cont.begin();it!=cont.end();++it){
		minv=min(it->second,minv);
	}
	cout << maxv-minv << endl;
	return 0;
}


