#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	ifstream pilas("input.txt");
	string str;
	getline(pilas,str);
	for(size_t i=0;i<str.size();++i) { 
		if(str[i]!=str[i+1]){
			if(str[i]!=str[i+2] && str[i+1]!=str[i+2]){
				if(str[i]!=str[i+3] && str[i+1]!=str[i+3] && str[i+2]!=str[i+3]){
					cout << i+4 << endl; break;
				}
			}
		}
	}
	return 0;
}

