#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int bin(string str){
	int n=0, c=1;
	reverse(str.begin(),str.end());
	for(size_t i=0;i<str.size();++i){
		if(str[i]=='1') n+=c;
		c*=2;
	}
	return n;
}

void eliminar(vector<string> &v, int pos, char val){
	for(size_t i=0;i<v.size();++i){
		if(v[i].at(pos)==val){
			v.erase(v.begin()+i);
			--i;
		}
	}
}
	
int filtro_OXY(vector<string> v){
	int p=0, C0, C1;
	while(v.size()>1){
		C0=C1=0;
		for(size_t i=0;i<v.size();++i){
			if(v[i].at(p)=='1') C1++;
			else C0++;
		}
		if(C1>=C0)eliminar(v,p,'0');
		else eliminar(v,p,'1');
		p++;
		if(p==v[0].size())p=0;
	}
	return bin(v[0]);
}

int filtro_C02(vector<string> v){
	int p=0, C0, C1;
	while(v.size()>1){
		C0=C1=0;
		for(size_t i=0;i<v.size();++i){
			if(v[i].at(p)=='1') C1++;
			else C0++;
		}
		if(C1>=C0)eliminar(v,p,'1');
		else eliminar(v,p,'0');
		p++;
		if(p==v[0].size())p=0;
	}
	return bin(v[0]);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str;
	vector<string> v;
	while(cin >> str){
		v.push_back(str);
	}
	
	int oxy=filtro_OXY(v);
	int C02=filtro_C02(v);
	
	cout << oxy*C02 << endl;
	
	return 0;
}
