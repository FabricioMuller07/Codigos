#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

int main(){
	freopen("weak_typing_chapter_2_input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ll cases, n, c, ult, algo;
	char last;
	string str, substring;
	cin >> cases;
	for(int k=0;k<cases;++k){
		cin >> n;
		cin >> str;
		c=0;
		for(int i=0;i<n;++i){
			last=str[i];
			ult=0;
			for(int j=i+1;j<n;++j){
				algo=0;
				if(str[j]=='X'){
					if(last=='O') algo=1;
					else algo=0;
					last='X';
				}
				else if(str[j]=='O'){
					if(last=='X') algo=1;
					else algo=0;
					last='O';
				}
				ult+=algo;
				c=(c+ult)%1000000007;
			}
		}
		
		cout << "Case #" << k+1 << ": " << c << endl;
	}
	return 0;
}
	

