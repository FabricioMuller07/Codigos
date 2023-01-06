#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int n, m, co=0;
	double k;
	cin >> n >> m >> k;
	vector<double> j(n), c(m);
	for(int i=0;i<n;++i) cin >> j[i];
	for(int i=0;i<m;++i) cin >> c[i];
	sort(j.rbegin(),j.rend());
	sort(c.rbegin(),c.rend());
	while(k>0 && (c.size()>0 || j.size()>0)){
		co++;
		if(j.size()>0 && c.size()>0){
			if(j[0]>c[0]){k-=j[0];j.erase(j.begin());}
			else{k-=c[0];c.erase(c.begin());}
		}
		else if(j.size()>0){k-=j[0];j.erase(j.begin());}
		else{k-=c[0];c.erase(c.begin());}
		
	}
	cout << co << " " << fixed << setprecision(3);
	if(k<=0)cout << 0.000 << endl;
	else cout << double(k)/2.0 << endl;
	return 0;
}

