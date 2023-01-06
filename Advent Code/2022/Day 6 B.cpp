#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	ifstream pilas("input.txt");
	string str; bool flag;
	getline(pilas,str);
	vector<int> v(26);
	for(size_t i=0;i<str.size();++i) { 
		fill(v.begin(),v.end(),0); flag=1;
		for(size_t j=i;j<i+14 && flag;++j) { 
			v[str[j]-'a']++;
			if(v[str[j]-'a']>1)flag=0;
		}
		if(flag){cout << i+14 << endl;break;}
	}
	return 0;
}

