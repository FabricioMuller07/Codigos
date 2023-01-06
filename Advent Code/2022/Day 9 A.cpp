#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

set<pair<int,int>> s;
struct pt {
	int x=0, y=0;
};

void check(pt &t, pt &h) {
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
	s.insert({t.x,t.y});
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	pt t, h; char d; int p;
	while(cin >> d >> p){
		while(p--){
			if(d=='U') h.y++;
			if(d=='D') h.y--;
			if(d=='R') h.x++;
			if(d=='L') h.x--;
			check(t,h);
		}
	}
	cout << s.size() << endl;
	//	for( set<pair<int,int>>::iterator it=s.begin(); it!=s.end(); ++it ) { 
	//		cout << it->first << " " << it->second << endl;
	//	}
	return 0;
}

