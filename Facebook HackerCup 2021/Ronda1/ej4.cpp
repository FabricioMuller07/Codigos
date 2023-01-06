#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << endl;
#define RAYA cerr << "================" << endl;
typedef long long ll;
using namespace std;

int main() {
	freopen("traffic_control_validation_input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cases, n, m, a, b;
	cin >> cases;
	for(int k=0;k<cases;++k){
		cin >> n >> m >> a >> b;
		if(n+m-1>a || n+m-1>b) cout << "Case #" << k+1 << ": Impossible" << endl;
		else{
			vector<vector<int>> v(n,vector<int>(m,1000));
			for(int i=0;i<n;++i){
				v[i][0]=1;
			}
			for(int i=0;i<m;++i){
				v[0][i]=1;
			}
			for(int i=0;i<n;++i){
				v[i][m-1]=1;
			}
			v[n-1][m-1]=a-(n+m-2);
			v[n-1][0]=b-(n+m-2);
			cout << "Case #" << k+1 << ": Possible" << endl;
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					cout << v[i][j] << " "; 
				}
				cout << endl;
			}
			
		}
	}
	return 0;
}

