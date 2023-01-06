#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

void DFD(char a, vector<int> &letras, vector<bool> &visit, vector<vector<int>> &v){
	visit[a-65]=1;
	letras[a-65]++;
	for(size_t i=0;i<v[a-65].size();++i){
		if(visit[v[a-65][i]]==0) DFD(v[a-65][i]+65,letras,visit,v);
	}
}
int DJ(int inicio, int lfinal, vector<vector<int>> &v ){
	if(inicio == lfinal) return 0;
	else{
		vector<int> d(26,INT_MAX);
		queue<int> q; int actual;
		q.push(inicio);
		d[inicio]=0;
		while(!q.empty()){
			actual=q.front();
			q.pop();
			for(size_t i=0;i<v[actual].size();++i){
				if(d[actual]+1<d[v[actual][i]]){
					q.push(v[actual][i]);
					d[v[actual][i]]=d[actual]+1;
				}
			}
		}
		return d[lfinal];
	}
}
int main() {
	freopen("consistency_chapter_2_input.txt","r",stdin);
	freopen("output3.txt","w",stdout);
	int cases, n, c, min_val; string str;
	char a, b;
	cin >> cases;
	for(int k=0;k<cases;++k){
		cin >> str;
		cin >> n;
		vector<vector<int>> v(26);
		for(int i=0;i<n;++i){
			cin >> a >> b;
			v[a-65].push_back(b-65);
		}
		
		vector<int> letras(26);
		
		for(size_t i=0;i<str.size();++i){
			vector<bool> visit(26);
			DFD(str[i],letras, visit, v);
		}
		
		vector<int> posibles;
		
		for(int i=0;i<26;++i){
			if(letras[i]==str.size()) posibles.push_back(i);
		}
		
		if(posibles.size()==0) cout << "Case #" << k+1 << ": " << -1 << endl;
		else{
			min_val=INT_MAX;
			for(int i=0;i<posibles.size();++i){
				c=0;
				for(size_t j=0;j<str.size();++j){
					c+=DJ(str[j]-65, posibles[i],v);
				}
				min_val=min(c,min_val);
			}
			cout << "Case #" << k+1 << ": " << min_val << endl;
		}
	}
	return 0;
}

