#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str1, str2; char a; int p=1, s=0; bool t=0;
	vector<int> l, r; 
	while(getline(cin,str1)){
		getline(cin,str2);
		stringstream s1(str1), s2(str2);
		s1 >> a; s2 >> a;
		
		if(t) s+=p;
		t=0; p++;
	}
	return 0;
}

