#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int n, m, num, c1=0, c2=0;
	map<int,int> C, J;
	cin >> n >> m;
	for(int i=0;i<n;++i) { 
		cin >> num;
		C[num]++;
	}
	for(int j=0;j<m;++j) { 
		cin >> num;
		J[num]++;
	}
	for(auto it=C.begin(); it!=C.end(); ++it ) { 
		auto b=J.find(it->first);
		if(b==J.end() && it->second>1) c1++;
	}
	for(auto it=J.begin(); it!=J.end(); ++it ) { 
		auto b=C.find(it->first);
		if(b==C.end() && it->second>1) c2++;
	}
	cout << min(c1,c2) << endl;
	return 0;
}

