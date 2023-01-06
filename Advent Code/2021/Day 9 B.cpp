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

int DFD(vector<vector<int>> &v, vector<vector<bool>> &visit, int i, int j){
	visit[i][j]=1; int c=0;
	if(i>0 && v[i-1][j]>v[i][j] && visit[i-1][j]==0 && v[i-1][j]!=9) c+=DFD(v,visit,i-1,j)+1;
	if(j>0 && v[i][j-1]>v[i][j] && visit[i][j-1]==0 &&  v[i][j-1]!=9) c+=DFD(v,visit,i,j-1)+1;
	if(i<v.size()-1 && v[i+1][j]>v[i][j] && visit[i+1][j]==0 && v[i+1][j]!=9) c+=DFD(v,visit,i+1,j)+1;
	if(j<v[0].size()-1 && v[i][j+1]>v[i][j] && visit[i][j+1]==0 && v[i][j+1]!=9) c+=DFD(v,visit,i,j+1)+1;	
	return c;
}
void mayor(int &a, int &b, int &c, int &s){
	if(s>a){c=b;b=a;a=s;}
	else if(s>b){c=b;b=s;}
	else if(s>c){c=s;}
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
	int tam1=0, tam2=0, tam3=0;
	vector<vector<bool>> visit(v.size(),vector<bool>(v[0].size()));
	for(size_t i=0;i<v.size();++i){
		for(size_t j=0;j<v[0].size();++j){
			if(check(v,i,j)){
				s=DFD(v,visit,i,j)+1;
				mayor(tam1,tam2,tam3,s);
			}
			
		}
	}
	cout << tam1 << " " << tam2 << " " << tam3 << endl;
	cout << tam1*tam2*tam3 << endl;
	return 0;
}
