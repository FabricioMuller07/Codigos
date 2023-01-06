#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int c=0;
	getline(cin,str);
	for(size_t i=0;i<str.size();++i){
		if(str[i]=='(') c++;
		else c--;
	}
	cout << c << endl;

	return 0;
}


