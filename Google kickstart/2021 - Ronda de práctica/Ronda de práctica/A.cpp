#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int t, n, k, s, num;
	cin >> t;
	for(int i=0;i<t;++i) { 
		cin >> n >> k;
		s=0;
		for(int i=0;i<n;++i) { 
			cin >> num;
			s+=num;
		}
		cout << "Case #" << i+1 << ": " << s%k << endl;
	}
	return 0;
}

