#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//2=1
//4=4
//7=3
//8=7

int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str, l; int c=0;
	while(cin >> str){
		if(str=="|"){
			for(int i=0;i<4;++i){
				cin >> str;
				if(str.size()==2)c++;
				else if(str.size()==4)c++;
				else if(str.size()==3)c++;
				else if(str.size()==7)c++;
			}
		}
	}
	cout << c << endl;
	return 0;
}


