#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>
#include <algorithm>
#define vmax 10001
#define emax 99999999
using namespace std;

int noscc, v, e, cnt, dest;
int dfsn[emax], set[vmax], nocity[vmax];
vector<int> E[vmax], adj[vmax];
vector<bool> finish;
stack<int> S;
int dfs(int i);
void go(int i);
void bellman_ford();

int main() {
	int s;
	noscc = cnt = 0;
	
	cin >> v >> e >> s >> dest;

	
	for (int i = 1, u, v; i <= e; i++) {
		cin >> u >> v;
		E[u].push_back(v);
	}
	finish.resize(v + 1);
	memset(dfsn, 0, emax);
	memset(set, 0, vmax);
	memset(nocity, 0, vmax);
	dfs(s);
	
	for (int i = 1; i <= v; i++) {
		nocity[set[i]]++;
	}

	if (dfsn[dest] == 0) {
		cout << 0; 
		return 0;
	}
	finish.clear();
	finish.resize(noscc + 1);
	vector<bool>(finish).swap(finish);
	for (int i = 1; i <= v; i++) {
		for (int j : E[i]) {
			if (set[i] != set[j]) {
				adj[set[i]].push_back(set[j]);
			}
		}
	}
	while (S.empty() == false) {
		S.pop();
	}
	s = set[s];
	dest = set[dest];
	memset(dfsn, 0, emax);
	go(s);
	bellman_ford();
	cout << dfsn[dest];
	//dijkstra(set[s]);
	//cout << l[set[dest]];
}
int dfs(int i) {
	int rst;
	S.push(i);

	dfsn[i] = ++cnt;
	rst = dfsn[i];

	for (int j : E[i]) {
		if (dfsn[j] == 0) {
			rst = min(rst, dfs(j));
		}
		else if (finish[j] == false) {
			rst = min(rst, dfsn[j]);
		}
	}

	if (rst == dfsn[i]) {
		int t;
		noscc++;
		while (true) {
			t = S.top();
			S.pop();
			finish[t] = true;
			set[t] = noscc;
			if (t == i) break;
		}
	}
	return rst;
}

void go(int i) {
	bool reach = false;
	finish[i] = true;
	for (int j : adj[i]) {
		if (finish[j] == false) {
			go(j);
		}
	}
	S.push(i);
}

void bellman_ford() {
	int u = S.top();
	
	dfsn[u] = nocity[u];
	S.pop();
	while (S.empty() == false) {
		for (int j : adj[u]) {
			if (dfsn[j] < dfsn[u] + nocity[j]) {
				dfsn[j] = dfsn[u] + nocity[j];
			}

		}
		u = S.top();
		S.pop();
	}
}