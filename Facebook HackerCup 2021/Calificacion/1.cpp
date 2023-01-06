#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

int main() {
	freopen("consistency_chapter_1_input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string str;
	int n, cant, cant_min;
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> str;
		vector<int> v(26,0);
		for(size_t j=0;j<str.size();++j){
			v[str[j]-'A']++;
		}
		cant_min=INT_MAX;
		for(int j=0;j<26;++j){
			cant=0;
			for(int k=0;k<26;++k){
				if(j!=k){
					if(j==0 || j==4 || j==8 || j==14 || j==20){
						if(k==0 || k==4 || k==8 || k==14 || k==20) cant+=v[k]*2;
						else cant+=v[k];
					}
					else{
						if(k==0 || k==4 || k==8 || k==14 || k==20) cant+=v[k];
						else cant+=v[k]*2;
					}
				}
			}
			cant_min=min(cant,cant_min);
		}
		
		cout << "Case #" << i+1 << ": " << cant_min << endl;
	}
	return 0;
}

