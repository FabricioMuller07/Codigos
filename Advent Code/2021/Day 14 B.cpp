#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str, trash, a, aux, par; 
	ll maxv=0, minv=LLONG_MAX;
	char auxc;
	map<string, char> m;
	map<string, ll> pares, paresaux;
	map<char,ll> cant;
	
	cin >> str;
	while(cin >> a >> trash >> auxc){
		m[a]=auxc;
	}
	
	for(size_t i=0;i<str.size()-1;++i){
		aux=str[i];aux+=str[i+1];
		++pares[aux];
		++cant[str[i]];
	}
	++cant[str[str.size()-1]];
	
	for(int i=0;i<40;++i){
		for(auto it=pares.begin();it!=pares.end();++it){
			aux=it->first;
			auxc=m[aux];
			cant[auxc]+=it->second;
			par=aux[0];par+=auxc;
			paresaux[par]+=it->second;
			par=auxc;par+=aux[1];
			paresaux[par]+=it->second;
		}
		pares=paresaux;
		paresaux.clear();
	}
	for(auto it=cant.begin();it!=cant.end();++it){
		maxv=max(it->second,maxv);
		minv=min(it->second,minv);
	}
	cout << maxv-minv << endl;
	return 0;
}
