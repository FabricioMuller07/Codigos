#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

char trash;
void get_sensor(int &x, int &y) {
	cin >> trash >> trash >> x;
	cin >> trash >> trash >> trash >> y;
}

void get_beacon(int &x, int &y) {
	string str;
	cin >> str >> str >> str >> str >> str;
	cin >> trash >> trash >> x;
	cin >> trash >> trash >> trash >> y;
}

void rango_sensor(set<int> &pts, int &xs, int &ys, int &xb, int &yb) {
	int d1=abs(xs-xb)+abs(ys-yb);
	if(ys-d1<=2000000 && ys+d1>=2000000){
		int d2=abs(ys-2000000), c=d1-d2;
		for(int i=xs-c;i<=xs+c;++i) { 
			pts.insert(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int xs, ys, xb, yb;
	set<int> pts;
	while(cin >> str >> str){
		get_sensor(xs,ys);
		get_beacon(xb,yb);
		rango_sensor(pts,xs,ys,xb,yb);
	}
	cout << pts.size() << endl;
	return 0;
}

