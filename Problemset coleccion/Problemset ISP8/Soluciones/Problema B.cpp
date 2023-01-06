#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int n, c=0; bool f1, f2, f3, f4, f5; char aux;
	cin >> n;
	vector<string> v(n);
	f1=f2=f3=f4=f5=0;
	for(int i=0;i<n;++i) { 
		cin >> v[i];
		for(size_t j=0;j<v[i].size();++j) { 
			if(v[i].at(j)=='S')f1=1;
			else if(v[i].at(j)=='o')f2=1;
			else if(v[i].at(j)=='f')f3=1;
			else if(v[i].at(j)=='i')f4=1;
			else if(v[i].at(j)=='a')f5=1;
		}
		if(v[i].size()>1)aux=tolower(v[i].at(v[i].size()-2));
		else aux='z';
		if((aux=='a' || aux=='e' || aux=='i') && tolower(v[i].at(v[i].size()-1))=='r')c++;
	}
	sort(v.begin(),v.end());
	if(f1 && f2 && f3 && f4 && f5) cout << "Sofi :)" << endl;
	else cout << "Sofi :(" << endl;
	cout << c << endl;
	for(size_t i=0;i<v.size();++i) { 
		cout << v[i] << endl;
	}
	return 0;
}

