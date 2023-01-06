#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
double dist(double x, double y,double xf, double yf){
	return sqrt(pow(x-xf,2)+pow(y-yf,2));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	vector<pair<double,double>> c(5),j(5);
	pair<double,double> tp;
	double dm1, dm2;
	int t, p;
	cin >> t;
	while(t--){
		cin >> tp.first >> tp.second; p=0; dm1=dm2=1000;
		
		for(int i=0;i<5;++i) { 
			cin >> c[i].first >> c[i].second;
			dm1=min(dm1,dist(tp.first,tp.second,c[i].first,c[i].second));
		}cout << endl;
		
		for(int i=0;i<5;++i) { 
			cin >> j[i].first >> j[i].second;
			dm2=min(dm2,dist(tp.first,tp.second,j[i].first,j[i].second));
		}cout << endl;
		
		
		if(dm1>dm2){
			for(int i=0;i<5;++i) { 
				dm2=dist(tp.first,tp.second,j[i].first,j[i].second);
				if(dm1>dm2) p++;
			}
		}
		else if(dm1<dm2){
			for(int i=0;i<5;++i) { 
				dm1=dist(tp.first,tp.second,c[i].first,c[i].second);
				if(dm1<dm2) p++;
			}
		}
		cout << p << endl;
	}
	return 0;
}

