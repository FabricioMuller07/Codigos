#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	char a, b; int p=0;
	while(cin >> a >> b){
		if(a=='A' && b=='X') p+=3;
		else if(a=='A' && b=='Y') p+=4;
		else if(a=='A' && b=='Z') p+=8;
		else if(a=='B' && b=='X') p+=1;
		else if(a=='B' && b=='Y') p+=5;
		else if(a=='B' && b=='Z') p+=9;
		else if(a=='C' && b=='X') p+=2;
		else if(a=='C' && b=='Y') p+=6;
		else if(a=='C' && b=='Z') p+=7;
	}
	cout << p << endl;
	return 0;
}

