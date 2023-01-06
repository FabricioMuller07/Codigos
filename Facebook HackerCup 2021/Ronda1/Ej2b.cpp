#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

int main(){
//	freopen("weak_typing_chapter_2_input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ll cases, n, c, ult;
	char last;
	string str, substring;
	cin >> cases;
	for(int k=0;k<cases;++k){
		cin >> n;
		cin >> str;
		c=0;
		last=str[0];
		if(last!='F') ult=0;
		for(int i=0;i<n;++i){
			if(str[i]=='O'){
				if(last=='X'){
					c=(c+1+ult+(n-i-1)+(ult*(n-1-i)))%1000000007;
				}
				last='O';
				ult=i;
			}
			else if(str[i]=='X'){
				if(last=='O'){
					c=(c+1+ult+(n-i-1)+(ult*(n-1-i)))%1000000007;
				}
				last='X';
				ult=i;
			}
		}
		
		cout << "Case #" << k+1 << ": " << c << endl;
	}
	return 0;
}
	
	
