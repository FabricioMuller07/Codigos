#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool check(vector<vector<int>> &v, int i, int j){
	int c1=0,c2=0;
	if(i>0 && v[i-1][j]>v[i][j]) c1++;
	if(j>0 && v[i][j-1]>v[i][j]) c1++;
	if(i<v.size()-1 && v[i+1][j]>v[i][j]) c1++;
	if(j<v[0].size()-1 && v[i][j+1]>v[i][j]) c1++;
	
	if(i>0) c2++;
	if(j>0) c2++;
	if(i<v.size()-1) c2++;
	if(j<v[0].size()-1) c2++;
	
	if(c1==c2) return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int p=0, s=0;
	vector<vector<int>> v;
	while(cin >> str){
		v.push_back({});
		for(size_t i=0;i<str.size();++i){
			v[p].push_back(str[i]-48);
		}++p;
	}
	
	for(size_t i=0;i<v.size();++i){
		for(size_t j=0;j<v[0].size();++j){
			if(check(v,i,j)){
				s+=v[i][j]+1;
			}
			
		}
	}
	
	cout << s << endl;
	return 0;
}


