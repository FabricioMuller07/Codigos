#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int x1=0, y1=0; int x2=0, y2=0;
	set<pair<int,int>> s;
	s.insert({x1,y1});
	getline(cin,str);
	for(size_t i=0;i<str.size();++i){
		if((i+1)%2==1){
			if(str[i]=='^') y1+=1;
			else if(str[i]=='<')x1-=1;
			else if(str[i]=='>')x1+=1;
			else if(str[i]=='v')y1-=1;
			s.insert({x1,y1});
		}
		else{
			if(str[i]=='^') y2+=1;
			else if(str[i]=='<')x2-=1;
			else if(str[i]=='>')x2+=1;
			else if(str[i]=='v')y2-=1;
			s.insert({x2,y2});
		}
	}
	cout << s.size() <<endl;
	return 0;
}
	
	
	
