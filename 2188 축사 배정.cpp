#include <iostream>
#include <vector>

using namespace std;

bool dfs(int s, int t);
int ford_fulkerson(int s, int t);
vector<bool> visit;
vector<vector<int>> f, c;
int n, m, t;

int main() {
	int tm, tc;

	cin >> n >> m;
	t = n + m + 1;
	f = c = vector<vector<int>>( t + 1, vector<int>(t + 1, 0));
	
	for (int i = 1; i <= n; i++) {
		c[0][i] = 1;
		cin >> tm;
		for(int j=1; j<=tm; j++){
			cin >> tc;
			c[i][n + tc] = 1;
			c[n + tc][t] = 1;
		}
	}
	cout << ford_fulkerson(0,t) << endl;
}

int ford_fulkerson(int s, int t) {
	int ans = 0;
	visit.resize(t + 1);
	for (int i = 0; i <= t; i++) {
		visit[i] = false;
	}

	while (dfs(s, t)) {
		ans ++;

		for (int i = 0; i <= t; i++) {
			visit[i] = false;
		}
	}

	return ans;
}

bool dfs(int s, int t) {
	visit[s] = true;
	if (s == t) {
		return true;
	}

	for (int i = 1; i <= t; i++) {
		if (visit[i] == false && c[s][i] > f[s][i]) {
			if (dfs(i,t)) {
				f[s][i] ++;
				f[i][s] --;
				return true;
			}
		}
	}
	return false;
}