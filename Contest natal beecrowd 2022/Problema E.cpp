#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int n; string str; bool flag=1;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;++i) { 
		cin >> str;
		v[i]=str.size();
	}
	sort(v.begin(),v.end());
	for(int i=1;i<n && flag;++i) { 
		if(v[i]%2==0 || v[i-1]+2!=v[i]) flag=0;
	}
	if(flag) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}

