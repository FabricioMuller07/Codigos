#include <bits/stdc++.h>
#include <windows.h>
typedef long long ll;
using namespace std;



int main() {
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "asd" << endl;
	for(int i=0;i<256;++i){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		cout << i << endl;
	}
	return 0;
}

