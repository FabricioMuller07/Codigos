#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

int main(){
//	freopen("weak_typing_chapter_1_input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int cases, n, c;
	char last;
	string str;
	cin >> cases;
	for(int k=0;k<cases;++k){
		cin >> n;
		cin >> str;c=0;
		last=str[0];
		for(size_t i=1;i<str.size();++i){
			if(last=='F') last=str[i];
			if(str[i]=='X' && last=='O'){
				c++; last='X';
			}
			else if(str[i]=='O' && last=='X'){
				c++; last='O';
			}
		}
		cout << "Case #" << k+1 << ": " << c << endl;
	}
	return 0;
}
