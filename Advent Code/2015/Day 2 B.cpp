#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	ll l, w, h, s=0, a; char trash;
	while(cin >> l >> trash >> w >> trash >>  h){
		s+=l*w*h;
		a=min(l,min(w,h));
		if(a==l)s+=a*2+2*min(w,h);
		else if(a==w)s+=a*2+2*min(l,h);
		else if(a==h)s+=a*2+2*min(w,l);
	}
	cout << s << endl;
	return 0;
}
	
