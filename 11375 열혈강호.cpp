#include <iostream>
#include <algorithm>
#include <vector>
#define INF 999999999

using namespace std;

int ford_fulkerson(int s, int t);
int dfs(int s, int t, int c);

vector<vector<int>> capacity, flow;
vector<bool> visit;
int n, m;

int main() {
	int m, s = 0, t;
	
	cin >> n >> m;
	t = n + m + 1;
	capacity = vector<vector<int>>(t + 1, vector<int>(t + 1, 0));
	flow = vector<vector<int>>(t + 1, vector<int>(t + 1, 0));
	visit.resize(t + 1);
	
	for (int i = 1, work; i <= n; i++) {
		cin >> work;
		capacity[s][i] = 1;
		for (int j = 1, w; j <= work; j++) {
			cin >> w;
			w += n;
			capacity[i][w] = 1;
			capacity[w][t] = 1;
		}
	}

	cout << ford_fulkerson(s,t);

}

int ford_fulkerson(int s, int t) {
	int ans = 0, f;

	for (int i = 0; i <= t; i++) {
		visit[i] = false;
	}

	while ((f=dfs(s, t, INF)) != 0) {
		ans += f;

		for (int i = 0; i <= t; i++) {
			visit[i] = false;
		}
	}

	return ans;
}

int dfs(int s, int t, int c) {
	int f;
	if (visit[s]) {
		return 0;
	}
	visit[s] = true;
	if (s == t) {
		return c;
	}

	for (int i = 1; i <= t; i++) {
		if (capacity[s][i] > flow[s][i]) {
			f = dfs(i, t, min(c, capacity[s][i] - flow[s][i]));
			if (f != 0) {
				flow[s][i] += f;
				flow[i][s] -= f;
				return f;
			}
		}
	}
	return 0;
}