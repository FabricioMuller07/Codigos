#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	set<string> s; string str, t;
	int m, n, c;
	cin >> m;
	for(int i=0;i<m;++i) { 
		cin >> str >> c >> t;
		s.insert(str);
	}
	cin >> n;
	for(int i=0;i<n;++i) { 
		cin >> str >> c >> t;
		s.insert(str);
	}
	for( set<string>::iterator it=s.begin(); it!=s.end(); ++it ) { 
		cout << *it << endl;
	}
	return 0;
}

