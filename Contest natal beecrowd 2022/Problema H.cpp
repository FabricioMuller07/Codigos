#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int n, m, r=INT_MAX; string str;
	vector<int> v(10);
	cin >> n;
	while(n--){
		cin >> m;
		cin.ignore();
		while(m--){
			getline(cin,str);
			for(size_t i=0;i<str.size();++i) { 
				if(tolower(str[i])=='m')v[0]++;
				else if(tolower(str[i])=='e')v[1]++;
				else if(tolower(str[i])=='r')v[2]++;
				else if(tolower(str[i])=='y')v[3]++;
				else if(tolower(str[i])=='c')v[4]++;
				else if(tolower(str[i])=='h')v[5]++;
				else if(tolower(str[i])=='i')v[6]++;
				else if(tolower(str[i])=='s')v[7]++;
				else if(tolower(str[i])=='t')v[8]++;
				else if(tolower(str[i])=='a')v[9]++;
			}
		}
	}
	r=min(r,v[0]);
	r=min(r,v[1]);
	r=min(r,v[2]/3);
	r=min(r,v[3]);
	r=min(r,v[4]);
	r=min(r,v[5]);
	r=min(r,v[6]);
	r=min(r,v[7]/2);
	r=min(r,v[8]);
	r=min(r,v[9]);
	cout << r << endl;
	return 0;
}

