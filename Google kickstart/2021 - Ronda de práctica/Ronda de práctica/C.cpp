#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int t, n, num, h;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> t;
	for(int k=1;k<=t;++k) { 
		cin >> n;h=0;
		cout << "Case #" << k << ": ";
		for(int i=0;i<n;++i) { 
			cin >> num;
			if(num>h) pq.push(num);
			
			if(pq.size()>h)cout << ++h << " ";
			else cout << h << " ";
			while(!pq.empty() && pq.top()<=h)pq.pop();
		}cout << endl;
		while(!pq.empty())pq.pop();
	}
	return 0;
}

