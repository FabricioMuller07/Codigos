#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void func(size_t &i, string &str, string &p, string &c){
	bool flag;
	if(str[i]==p[0] && str.size()-i>=p.size()){
		flag=1;
		for(size_t j=i+1;j<i+p.size() && flag;++j) { 
			if(str[j]!=p[j-i])flag=0;
		}
		if(flag){
			if((i==0 || str[i-1]==' ') && (i+p.size()==str.size() || str[i+p.size()]==' '))flag=1;
			else flag=0;
			if(flag){
				str.erase(str.begin()+i,str.begin()+i+p.size());
				str.insert(i,c);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str, a="azul", v="vermelho", b="blue", r="red"; 
	getline(cin,str);
	for(size_t i=0;i<str.size();++i) { 
		func(i,str,b,a);
		func(i,str,r,v);
	}
	cout << str << endl;
	return 0;
}

