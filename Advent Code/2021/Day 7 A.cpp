#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	char trash;
	int num, c=0, mm=0;
	map<int,ll> m;
	while(cin >> num){
		m[num]++;
		cin >> trash;
		mm=max(mm,num);
	}
	auto it=m.begin();
	vector<int> v(mm+1), v2(mm+1);
	if(it->first==0){c+=it->second;++it;}
	for(int i=1;i<=mm;++i){
		v[i]=c+v[i-1];
		if(it->first<=i){c+=it->second;++it;}
	}
	
	c=0; it=m.end(); 
	--it;
	if(it->first==mm){c+=it->second;--it;}
	for(int i=mm-1;i>=0;--i){
		v2[i]=c+v2[i+1];
		if(it->first>=i){c+=it->second;--it;}
	}
	
	int s=INT_MAX;
	for(size_t i=0;i<v.size();++i){
		s=min(v[i]+v2[i],s);
	}
	cout << s << endl;
	
//	for(size_t i=0;i<v.size();++i){
//		cout << v2[i] << " ";
//	}cout << endl;
//	
//	for(size_t i=0;i<v.size();++i){
//		cout << v[i] << " ";
//	}cout << endl;
	
	return 0;
}
