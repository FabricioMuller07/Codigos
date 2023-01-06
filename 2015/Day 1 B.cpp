#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int c=0, p;
	getline(cin,str);
	for(size_t i=0;i<str.size();++i){
		if(str[i]=='(') c++;
		else c--;
		if(c==-1) {p=i+1;break;}
	}
	cout << p << endl;

	return 0;
}


