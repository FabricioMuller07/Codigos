#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

int main(){
//	freopen1(".txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cases, r, c, k, cont, ca, resp, ca1, ca2;
	cin >> cases;
	for(int z=0;z<cases;++z){
		cin >> r >> c >> k;
		vector<vector<char>> v(r,vector<char>(c)), aux1, aux2;
		cont=ca=0;
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				cin >> v[i][j];
			}
		}
		for(int i=0;i<c;++i){
			if(v[k-1][i]=='X') ca++;
		}
		
		if(ca==1) resp=1;
		else{
			ca1=ca2=0;
			aux1=aux2=v;
			for(int i=0;i<c;++i){
				for(int j=0;j<r-1;++j){
					if(aux1[j][i]=='.' && aux1[j+1][i]=='.'){
						swap(aux1[j][i],aux1[j+1][i]);
					}
				}
			}
			for(int i=0;i<c;++i){
				if(aux1[k-1][i]=='X') ca1++;
			}
			for(int i=0;i<c;++i){
				for(int j=r-1;j>0;--j){
					if(aux2[j][i]=='.' && aux2[j-1][i]=='.'){
						swap(aux2[j][i],aux2[j-1][i]);
					}
				}
			}
			for(int i=0;i<c;++i){
				if(v[k-1][i]=='X') ca2++;
			}
		}
		cout << "Case #" << z+1 << ": " << resp << endl;
	}
	return 0;
}
