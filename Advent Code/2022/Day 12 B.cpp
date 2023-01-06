#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<char>> v(41,vector<char>(93));
vector<int> xp={1,0,-1,0}, yp={0,1,0,-1};

int BFS(pair<int,int> &p1, pair<int,int> &p2) {
	vector<vector<int>> d(41,vector<int>(93,INT_MAX)); d[p1.first][p1.second]=0;
	queue<pair<int,int>> q;
	int x, y, md=INT_MAX;
	q.push(p1);
	while(!q.empty()){
		x=q.front().first;y=q.front().second;
		q.pop();
		for(int i=0;i<4;++i) { 
			if(x+xp[i]>=0 && x+xp[i]<41 && y+yp[i]>=0 && y+yp[i]<93){
				if((v[x+xp[i]][y+yp[i]]>=v[x][y] || v[x+xp[i]][y+yp[i]]==v[x][y]-1) && d[x+xp[i]][y+yp[i]]==INT_MAX){
					q.push({x+xp[i],y+yp[i]});
					d[x+xp[i]][y+yp[i]]=d[x][y]+1;
					if(v[x+xp[i]][y+yp[i]]=='a')md=min(md,d[x+xp[i]][y+yp[i]]);
				}
			}
		}
	}
	return md;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	pair<int,int> p1, p2;
	for(int i=0;i<41;++i) { 
		for(int j=0;j<93;++j) { 
			cin >> v[i][j];
			if(v[i][j]=='S'){p1.first=i;p1.second=j;v[i][j]='a';}
			if(v[i][j]=='E'){p2.first=i;p2.second=j;v[i][j]='z';}
		}
	}
	int c=BFS(p2,p1);
	cout << c << endl;
	return 0;
}

