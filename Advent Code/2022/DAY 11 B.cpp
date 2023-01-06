#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
ifstream s("INDAY11.txt");

class monkey{
	vector<ll> v;
	char op;
	ll opn, div;
	pair<ll,ll> mon;
	ll c=0;
public:
	void Leer() {
		string str; int num;
		s.ignore();
		getline(s,str);
		stringstream ss(str);
		while(ss >> num){
			v.push_back(num);
		}
		s >> op;
		s >> str;
		if(str=="old") opn=-1;
		else opn=stoi(str);
		s >> div;
		s >> mon.first >> mon.second;
	}
	void largar_v() {
		for(size_t i=0;i<v.size();++i) { 
			cout << v[i] << " ";
		}cout << endl;
	}
	void trow(vector<monkey> &m) {
		for(size_t i=0;i<v.size();++i) { 
			c++;
			if(op=='+'){
				v[i]=(v[i]+opn)%9699690;
			}
			else{
				if(opn==-1)v[i]=(v[i]*v[i])%9699690;
				else v[i]=(v[i]*opn)%9699690;
			}
			
			if(v[i]%div==0) m[mon.first].recive(v[i]);
			else m[mon.second].recive(v[i]);
			
		}
		v.clear();
	}
	void recive(ll &item) {
		v.push_back(item);
	}
	int buisness(){
		return c;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	vector<monkey> m(8);
	for(int i=0;i<8;++i) { 
		m[i].Leer();
	}
	for(int i=0;i<10000;++i) { 
		for(int j=0;j<8;++j) { 
			m[j].trow(m);
		}
	}
	ll m1=0, m2=0;
	for(int i=0;i<8;++i) { 
		if(m[i].buisness()>m1){
			m2=m1;m1=m[i].buisness();
		}
		else if(m[i].buisness()>m2){
			m2=m[i].buisness();
		}
	}
	cout << m1*m2 << endl;
	return 0;
}

