#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int c=0, v, f, t;
	while(cin >> str){
		v=t=f=0;
		for(size_t i=0;i<str.size();++i) { 
			if(i>0 && str[i]==str[i-1]) f=1;
			if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') v++;
			if(i>0 && ((str[i-1]=='a' && str[i]=='b') || (str[i-1]=='c' && str[i]=='d') || (str[i-1]=='p' && str[i]=='q') || (str[i-1]=='x' && str[i]=='y'))){t=1;break;}
		}
		if(t==0 && v>2 && f==1) c++;
	}
	cout << c << endl;
	return 0;
}

