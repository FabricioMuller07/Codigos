#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int s=0, c=0;
	vector<int> v(53); vector<string> vs; vector<bool> visit(53);
	while(getline(cin,str)){
		c++;
		vs.push_back(str);
		if(c==3){
			fill(v.begin(),v.end(),0);c=0;
			for(int k=0;k<3;++k) { 
				str=vs[k];
				fill(visit.begin(),visit.end(),0);
				for(size_t i=0;i<str.size();++i) { 
					if(str[i]>='a' && str[i]<='z' && !visit[str[i]-'a']){
						v[str[i]-'a']+=(k+1);
						visit[str[i]-'a']=1;
					}
					else if(!visit[str[i]-'A'+26]){
						v[str[i]-'A'+26]+=(k+1);
						visit[str[i]-'A'+26]=1;
					}
				}
			}
			for(int i=0;i<52;++i) {
//				cout << v[i] << endl;
				if(v[i]==6){
//					cout << i << endl;
					s+=i+1;
//					break;
				}
			}
			vs.clear();
		}
	}
	cout << s << endl;
	return 0;
}

