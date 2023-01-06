#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	char c;
	int xj, yj, xc, yc;
	for(int i=0;i<10;++i) { 
		for(int j=0;j<10;++j) { 
			cin >> c;
			if(c=='C'){xc=i;yc=j;}
			if(c=='J'){xj=i;yj=j;}
		}
	}
	cout << abs(xc-xj)+abs(yc-yj) << endl;
	return 0;
}



