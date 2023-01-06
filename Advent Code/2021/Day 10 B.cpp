#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; ll sum=0; bool flag=1;
	stack<char> s;
	vector<ll> v;
	while(getline(cin,str)){
		for(size_t i=0;i<str.size();++i){
			if(str[i]=='(' || str[i]=='[' || str[i]=='{' || str[i]=='<')s.push(str[i]);
			else{
				if((str[i]==')' && s.top()!='(') || (str[i]==']' && s.top()!='[') || (str[i]=='}' && s.top()!='{') || (str[i]=='>' && s.top()!='<')){flag=0;break;}
				else s.pop();
			}
		}
		if(flag){
			while(!s.empty()){
				sum*=5;
				if(s.top()=='(')sum+=1;
				else if(s.top()=='[')sum+=2;
				else if(s.top()=='{')sum+=3;
				else if(s.top()=='<')sum+=4;
				s.pop();
			}
			v.push_back(sum);
		}
		s=stack<char>();sum=0; flag=1;
	}
	sort(v.begin(),v.end());
	cout << v.size() << endl;
	for(size_t i=0;i<v.size();++i){
		cout << v[i] << endl;
	}
	cout << v[v.size()/2] << endl;
	
	return 0;
}
