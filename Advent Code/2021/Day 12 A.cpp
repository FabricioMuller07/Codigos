#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int c=0;

bool es_mayus(string &str) {
	for(size_t i=0;i<str.size();++i){
		if(str[i]>='a' && str[i]<='z') return false;
	}
	return true;
}

void DFD(map<string,vector<string>> &m, map<string,bool> &visit, string &str) {
	auto it=m.find(str);
	for(size_t i=0;i<it->second.size();++i){
		auto itv=visit.find(it->second[i]);
		if(it->second[i]=="end") c++;
		else if((!es_mayus(it->second[i]) && itv->second==0) || es_mayus(it->second[i])){
			visit[str]=1;
			DFD(m,visit,it->second[i]);
			visit[str]=0;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	map<string,vector<string>> m;
	map<string,bool> visit;
	string a, str, b; bool flag;
	while(getline(cin,str)){
		a=b=""; flag=1;
		for(size_t i=0;i<str.size();++i){
			if(str[i]=='-') flag=0;
			else if(flag)a+=str[i];
			else b+=str[i];
		}
		if(a=="start" || b=="end")m[a].push_back(b);
		else if(a=="end" || b=="start")m[b].push_back(a);
		else{m[a].push_back(b);m[b].push_back(a);}
		if(!es_mayus(a))visit[a]=0;
		if(!es_mayus(b))visit[b]=0;
	}
	
	string aux="start";
	DFD(m,visit,aux);
	
	cout << c << endl;
	
	return 0;
}
