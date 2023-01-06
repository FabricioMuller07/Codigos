#include <bits/stdc++.h>
typedef long long ll;
using namespace std;	

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int n, a, b, c, d, eq1, eq2, puntos1=0, puntos2=0;
	cin >> n;
	for(int i=0;i<n;++i) { 
		cin >> a >> b >> c >> d;
		cin >> eq1 >> eq2;
		if(a==c && b==d && a==eq1 && b==eq2){puntos1++;puntos2++;}
		else{
			if(a==eq1 && b==eq2)puntos1+=3;
			else if(a==eq1 || b==eq2) puntos1++;
			
			if(c==eq1 && d==eq2)puntos2+=3;
			else if(c==eq1 || d==eq2) puntos2++;
		}
	}
	cout << puntos1 << " " << puntos2 << endl;
	
	return 0;
}



