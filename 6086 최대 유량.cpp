#include <iostream>
#include <vector>
#include <algorithm>

#define Alpha 52
#define INF 99999999
using namespace std;

int ford_fulkerson(int s, int t);
int dfs(int s, int t, int c);
vector<vector<int>> flow, capacity;
bool visit[Alpha + 1];

int main() {
	char f, t;
	int c, n;

	cin >> n;

	flow = vector<vector<int>>(Alpha + 1, vector<int>(Alpha + 1, 0));
	capacity = vector<vector<int>>(Alpha + 1, vector<int>(Alpha + 1, 0));

	for (int i = 1; i <= n; i++) {
		cin >> f >> t >> c;
		

		if (f <= 'Z') {
			f = f - 'A' + 1;
		}
		else {
			f = (f - 'a') + 26 + 1;
		}
		
		if (t <= 'Z') {
			t = t - 'A' + 1;
		}
		else {
			t = (t - 'a') + 26 + 1;
		}

		capacity[f][t] += c;
		capacity[t][f] += c;
	}

	cout << ford_fulkerson(1, 26) << endl;
}

int ford_fulkerson(int s, int t) {
	int f, ans = 0;

	for (int i = 1; i <= Alpha; i++) {
		visit[i] = false;
	}

	while ((f = dfs(s, t, INF)) != 0) {
		ans += f;
		for (int i = 1; i <= Alpha; i++) {
			visit[i] = false;
		}
	}
	return ans;
}

int dfs(int s, int t, int c) {
	int f;
	if (visit[s]) {	return 0;}
	visit[s] = true;

	if (s == t) {
		return c;
	}

	for (int i = 1; i <= Alpha; i++) {
		if (flow[s][i] < capacity[s][i]) {
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