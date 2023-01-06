#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int c=0, f, t, p;
	map<pair<char,char>, int> m;
	while(cin >> str){
		m.clear();t=f=0;p=-1;
		for(size_t i=0;i<str.size();++i) { 
			if(i>1 && str[i-2]==str[i]) f=1;
			if(i>0){
				if(i==1 || str[i-1]!=str[i])m[{str[i-1],str[i]}]++;
				else if(p!=i-1){
					p=i;
					m[{str[i-1],str[i]}]++;
				}
				if(m[{str[i-1],str[i]}]>1) t=1;
			}
		}
		if(t && f) c++;
	}
	cout << c << endl;
	return 0;
}

