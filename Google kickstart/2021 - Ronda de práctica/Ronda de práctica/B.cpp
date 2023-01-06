#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool vocal(char x){
	x=tolower(x);
	if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u') return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int t;string str;
	cin >> t;
	for(int i=1;i<=t;++i) { 
		cin >> str;
		cout << "Case #" << i << ": ";
		if(vocal(str[str.size()-1])) cout << str << " is ruled by Alice." << endl;
		else if(tolower(str[str.size()-1])!='y') cout << str << " is ruled by Bob." << endl;
		else cout << str << " is ruled by nobody." << endl;
	}
	return 0;
}

