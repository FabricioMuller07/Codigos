#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

ll calcular(string str){
	ll c=0, ult=0; char last=str[0];
	for(int i=0;i<str.size();++i){
		if(str[i]=='O'){
			if(last=='X'){
				c=(c+1+ult+(str.size()-i-1)+(ult*(str.size()-1-i)))%1000000007;
			}
			last='O';
			ult=i;
		}
		else if(str[i]=='X'){
			if(last=='O'){
				c=(c+1+ult+(str.size()-i-1)+(ult*(str.size()-1-i)))%1000000007;
			}
			last='X';
			ult=i;
		}
	}
	return c;
}

int main(){
//	freopen("weak_typing_chapter_3_validation_input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ll cases, n, c, ult, val;
	char last, first, caract;
	string str, substring;
	bool primero;
	cin >> cases;
	for(int k=0;k<cases;++k){
		cin >> n;
		str=""; primero=false; c=0;
		for(int i=0;i<n;++i){
			cin >> caract;
			if(primero==false && (caract=='X' || caract=='O'))first=caract;
			
			if(caract!='.') str+=caract;
			else{
				val=calcular(str);
				c=(c+val*2)%1000000007;
			}
		}
		cout << "Case #" << k+1 << ": " << c << endl;
	}
	return 0;
}
	
	
	
