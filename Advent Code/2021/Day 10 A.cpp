#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; ll sum=0;
	stack<char> s;
	while(getline(cin,str)){
		
		for(size_t i=0;i<str.size();++i){
			if(str[i]=='(' || str[i]=='[' || str[i]=='{' || str[i]=='<')s.push(str[i]);
			else{
				if((str[i]==')' && s.top()!='(') || (str[i]==']' && s.top()!='[') || (str[i]=='}' && s.top()!='{') || (str[i]=='>' && s.top()!='<')){
					if(str[i]==')')sum+=3;
					else if(str[i]==']')sum+=57;
					else if(str[i]=='}')sum+=1197;
					else if(str[i]=='>')sum+=25137;
					break;
				}
				else s.pop();
			}
		}
		s=stack<char>();
	}
	cout << sum << endl;
	
	return 0;
}
