#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#define max 10001
using namespace std;

int Tarjan(int i);
vector<bool> visit,finish;
vector<int> E[max];
stack<int> S;
vector<vector<int>> SCC;
int v, e, cntr = 0, dfso[max], noSCC=0;

int main() {
	visit.resize(max);
	finish.resize(max);
	cin >> v >> e;
	for (int i = 1; i <= e; i++) {
		int u, w;
		cin >> u >> w;
		E[u].push_back(w); // 0부터 시작.
	}

	for (int i = 1; i <= v; i++) {
		if (dfso[i] == 0) {
			Tarjan(i);
		}
	}
	sort(SCC.begin(), SCC.end());
	cout << noSCC << endl;
	for (auto& temp : SCC) {
		for (int i : temp) {
			cout << i << " ";
		}
		puts("-1");
	}

}

int Tarjan(int i) {
	int rst;

	dfso[i] = ++cntr;
	S.push(i);
	rst = dfso[i];
	for (int j : E[i]) {
		if (dfso[j]==0) {
			rst = min(rst, Tarjan(j));
		}
		else if (finish[j]==false) {
			rst = min(rst, dfso[j]);
		}
	}
	if (rst == dfso[i]) {
		vector<int> subSCC;
		noSCC++;
		while (true) {
			int t = S.top();
			subSCC.push_back(t);
			finish[t] = true;
			S.pop();
			if (i == t) break;
		}
		sort(subSCC.begin(), subSCC.end());
		SCC.push_back(subSCC);
	}
	return rst;
}