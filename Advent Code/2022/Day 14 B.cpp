#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	vector<vector<bool>> v(1000,vector<bool>(179,0));
	string str, tow; int xi, yi, xf, yf, x, y, c=0, maxy=0; char coma;
	while(getline(cin,str)){
		stringstream s(str);
		s >> xi >> coma >> yi;
		while(s >> tow >> xf >> coma >> yf){
			maxy=max(maxy,yi);
			for(int i=min(xi,xf);i<=max(xf,xi);++i) { 
				for(int j=min(yi,yf);j<=max(yf,yi);++j) {
					v[i][j]=1;
				}
			}
			xi=xf;yi=yf;
		}
		maxy=max(maxy,yi);
	}
	while(!v[500][0]){
		x=500;y=0;
		c++;
		while(y!=10){
			if(v[x][y+1]==0)y++;
			else if(v[x-1][y+1]==0){x--;y++;}
			else if(v[x+1][y+1]==0){x++;y++;}
			else break;
		}
		v[x][y]=1;
	}
	cout << c << endl;
	return 0;
}

