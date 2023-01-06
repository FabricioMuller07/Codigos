#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void matriz(set<pair<int,int>> s){
	int valmax_x=0,valmax_y=0;
	for(auto it=s.begin();it!=s.end();++it){
		valmax_x=max(valmax_x,it->first);
		valmax_y=max(valmax_y,it->second);
	}
	for(int i=0;i<=valmax_y;++i){
		for(int j=0;j<=valmax_x;++j){
			if(s.find({j,i})!=s.end()) cout << '#';
			else cout << '.';
		}cout << endl;
	}
}
void fold(set<pair<int,int>> &s, int n, bool &flag) {
	if(flag){
		for(auto it=s.begin();it!=s.end();++it){
			if(it->first>n){
				s.insert({n-abs(n-it->first),it->second});
				it=s.erase(it);
				--it;
			}
		 
		}
	}
	else{
		for(auto it=s.begin();it!=s.end();++it){
			if(it->second>n){
				s.insert({it->first,n-abs(n-it->second)});
				it=s.erase(it);
				--it;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int x, y, pos, n; bool flag;
	char trash; string str, num;
	set<pair<int,int>> s;
	while(cin >> str && str!="fold"){
		stringstream stre(str);
		stre >> x >> trash >> y;
		s.insert({x,y});
	}
	while(getline(cin,str)){
		flag=1;num="";
		for(size_t i=0;i<str.size();++i){
			if(str[i]=='x'){flag=1;pos=i;break;}
			else if(str[i]=='y'){flag=0;pos=i;break;}
		}
		for(size_t j=pos+2;j<str.size();++j){
			num+=str[j];
		}
		n=stoi(num);
		fold(s,n,flag);
		cout << s.size() << endl;
	}
	matriz(s);
	return 0;
}


