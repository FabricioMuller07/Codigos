#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int x=0, y=0;
	set<pair<int,int>> s;
	s.insert({x,y});
	getline(cin,str);
	for(size_t i=0;i<str.size();++i){
		if(str[i]=='^') y+=1;
		else if(str[i]=='<')x-=1;
		else if(str[i]=='>')x+=1;
		else if(str[i]=='v')y
			-=1;
		s.insert({x,y});
	}
	cout << s.size() <<endl;
	return 0;
}


