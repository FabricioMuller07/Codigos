#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void cargar_datos(vector<stack<char>> &v) {
	string str;
	ifstream pilas("input.txt");
	for(int i=0;i<9;++i) { 
		getline(pilas,str);
		for(size_t j=0;j<str.size();++j) { 
			v[i].push(str[j]);
		}
	}
	pilas.close();
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string str; int c, f, t;
	vector<stack<char>> v(9);
	stack<char> aux;
	cargar_datos(v);
	while(cin >> str >> c >> str >> f >> str >> t){
		for(int i=0;i<c && !v[f-1].empty();++i) { 
			aux.push(v[f-1].top());
			v[f-1].pop();
		}
		while(!aux.empty()){
			v[t-1].push(aux.top());
			aux.pop();
		}
	}
	for(int i=0;i<9;++i) { 
		cout << v[i].top();
	}cout << endl;
	return 0;
}

