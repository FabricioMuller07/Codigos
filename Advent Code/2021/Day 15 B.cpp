#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void DFD(vector<vector<int>> &v, vector<vector<ll>> &cam, unsigned int x, unsigned int y) {
	if(x<v[0].size()-1){
		if(x+1==v[0].size()-1 && y==v.size()-1){
			if(cam[y][x+1]==-1)cam[y][x+1]=cam[y][x]+v[y][x+1];
			else cam[y][x+1]=min(cam[y][x]+v[y][x+1],cam[y][x+1]);
		}
		else if(cam[y][x+1]==-1 || cam[y][x+1]>cam[y][x]+v[y][x+1]){
			cam[y][x+1]=cam[y][x]+v[y][x+1];
			DFD(v,cam,x+1,y);
		}
	}
	if(y<v.size()-1){
		if(y+1==v.size()-1 && x==v[0].size()-1){
			if(cam[y+1][x]==-1)cam[y+1][x]=cam[y][x]+v[y+1][x];
			else cam[y+1][x]=min(cam[y][x]+v[y+1][x],cam[y+1][x]);
		}
		else if(cam[y+1][x]==-1 || cam[y+1][x]>cam[y][x]+v[y+1][x]){
			cam[y+1][x]=cam[y][x]+v[y+1][x];
			DFD(v,cam,x,y+1);
		}
	}
	if(x>0 && cam[y][x-1]>cam[y][x]+v[y][x-1]){
		cam[y][x-1]=cam[y][x]+v[y][x-1];
		DFD(v,cam,x-1,y);
	}
	if(y>0 && cam[y-1][x]>cam[y][x]+v[y-1][x]){
		cam[y-1][x]=cam[y][x]+v[y-1][x];
		DFD(v,cam,x,y-1);
	}
}
void aumentar(vector<vector<int>> &v, int y, int p1, int p2) {
	for(int i=p1;i<p2;++i){
		++v[y][i];
		if(v[y][i]==10)v[y][i]=1;
	}
}
void aumentarC(vector<vector<int>> &v, int p1, int p2) {
	int base=v[0].size();
	for(int i=p1;i<p2;++i){
		for(size_t j=0;j<v[i].size();++j){
			v[i][j]=v[i-base][j]+1;
			if(v[i][j]==10)v[i][j]=1;
		}
	}
}
int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	vector<vector<int>> v;
	string nums;
	while(getline(cin, nums)){
		v.push_back(vector<int> (nums.size()));
		for(size_t i=0;i<nums.size();++i){
			v[v.size()-1][i]=nums[i]-48;
		}
	}
	
	int p1, d;
	d=0;
	for(int k=0;k<4;++k){
		p1=v.size();
		for(int j=d;j<p1;++j){
			v.push_back(vector<int>(v[0].size()));
		}
		d=p1;
		aumentarC(v,p1,v.size());
	}
	for(size_t i=0;i<v.size();++i){
		d=0;
		for(int k=0;k<4;++k){
			p1=v[i].size();
			for(int j=d;j<p1;++j){
				v[i].push_back(v[i][j]);
			}
			d=p1;
			aumentar(v,i,p1,v[i].size());
		}
	}
	
	
	vector<vector<ll>> cam(v.size(),vector<ll> (v[0].size(),-1));
	cam[0][0]=0;
	DFD(v,cam,0,0);
	
	cout << cam[v.size()-1][v[0].size()-1] << endl;
	
	return 0;
}


