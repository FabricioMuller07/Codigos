#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

set<pair<int,int>> s;
struct pt {
	int x=0, y=0;
};

void check(pt &t, pt &h, int &n) {
	if(t.x!=h.x && t.y!=h.y){
		if(t.x-h.x>1){
			t.x--;
			if(t.y-h.y>=1)t.y--;
			else if(h.y-t.y>=1)t.y++;
		}
		else if(h.x-t.x>1){
			t.x++;
			if(t.y-h.y>=1)t.y--;
			else if(h.y-t.y>=1)t.y++;
		}
		if(t.y-h.y>1){
			t.y--;
			if(t.x-h.x>=1)t.x--;
			else if(h.x-t.x>=1)t.x++;
		}
		else if(h.y-t.y>1){
			t.y++;
			if(t.x-h.x>=1)t.x--;
			else if(h.x-t.x>=1)t.x++;
		}
	}
	else{
		if(t.x-h.x>1)t.x--;
		else if(h.x-t.x>1)t.x++;
		if(t.y-h.y>1)t.y--;
		else if(h.y-t.y>1)t.y++;
	}
	if(n==8)s.insert({t.x,t.y});
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	pt h; char d; int p, n=0;
	vector<pt> t(9);
	while(cin >> d >> p){
		while(p--){
			if(d=='U') h.y++;
			if(d=='D') h.y--;
			if(d=='R') h.x++;
			if(d=='L') h.x--;
			check(t[0],h,n);
			for(int i=1;i<9;++i) { 
				check(t[i],t[i-1],i);
			}
		}
	}
	cout << s.size() << endl;
	return 0;
}

