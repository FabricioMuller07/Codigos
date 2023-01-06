#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int bin(string str) {
	int n=0, c=1;
	reverse(str.begin(),str.end());
	for(size_t i=0;i<str.size();++i){
		if(str[i]=='1') n+=c;
		c*=2;
	}
	return n;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str;
	vector<string> v;
	while(cin >> str){
		v.push_back(str);
	}
	int C0, C1;
	string gama, epsilon;
	for(int j=0;j<v[0].size();++j){
		C1=C0=0;
		for(size_t i=0;i<v.size();++i){
			if(v[i].at(j)=='0')C0++;
			else C1++;
		}
		if(C0>C1){gama+="0";epsilon+="1";}
		else{gama+="1";epsilon+="0";}
	}
	cout << bin(gama)*bin(epsilon) << endl;

	return 0;
}
