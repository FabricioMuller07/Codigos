#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	ll t, n;
	cin >> t;
	while(t--){
		cin >> n;
		n*=n;
		cout << ((n*(n+1))/2)*n << endl;
	}
	return 0;
}
