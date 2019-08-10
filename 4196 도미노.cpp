#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

int noscc, v, e, cnt;

vector<int> dfsn, set;
vector<vector<int>> E;
vector<bool> finish;
stack<int> S;
int dfs(int i);

int main() {
	int ans, tc;
	vector<int> indegree;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		noscc = cnt = ans = 0;
		dfsn.clear();
		set.clear();
		finish.clear();
		indegree.clear();
		E.clear();
		
		cin >> v >> e;

		E = vector<vector<int>>(v + 1, vector<int>());

		for (int i = 1, u, v; i <= e; i++) {
			cin >> u >> v;
			E[u].push_back(v);
		}
		dfsn.resize(v + 1);
		set.resize(v + 1);
		finish.resize(v + 1);

		for (int i = 1; i <= v; i++) {
			if (dfsn[i] == 0) dfs(i);
		}
		indegree.resize(noscc + 1);

		for (int i = 1; i <= v; i++) {
			for (int j : E[i]) {
				if (set[i] != set[j]) {
					indegree[set[j]]++;
				}
			}
		}

		for (int i = 1; i <= noscc; i++) {
			if (indegree[i] == 0) {
				ans++;
			}
		}
		cout << ans << endl;
	}
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
