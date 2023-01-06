#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> memo(1,0);

ll solucion(ll n){
	if(n<memo.size())return memo[n];
	else{
		memo.push_back(n+solucion(n-1));
		return memo[n];
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll n=0;
	while(cin >> n)
		cout << solucion(n) << endl;
	return 0;
}

