#include <iostream>
#include <vector>

#define INF 100000

using namespace std;

int main() {
	vector<int> from, to, cost, touch, length;
	int n, m, source = 1;
	
	cin >> n >> m;
	
	if (n < 1 || n>1000 || m < n - 1) {
		return 0;
	}

	length.resize(n + 1);
	touch.resize(n + 1);

	from.resize(m + 1);
	to.resize(m + 1);
	cost.resize(m + 1);
	
	for (int i = 1; i <= m; i++) {
		cin >> from[i] >> to[i] >> cost[i];
		if (from[i] < 1 || from[i]>1000 || to[i] < 1 || to[i]>1000 || cost[i] < 1 || cost[i]>10) {
			return 0;
		}
	}
	/*Dijkstra*/
	int min;
	for (int i = 1; i <= n; i++) {
		length[i] = INF;
	}
	length[source] = -1;
	for (int i = 1; i <= m; i++) {
		if (from[i] == source) {
			length[to[i]] = cost[i];
			touch[to[i]] = source;
		}
		/* full duplex */
		if (to[i] == source) {
			length[from[i]] = cost[i];
			touch[from[i]] = source;
		}
	}
	
	for (int k = 1; k <= n - 1; k++) {
		min = INF;
		for (int i = 1; i <= n; i++) {
			if (length[i] != -1 && length[i] != 0 && length[i] < min) {
				source=i;
				min = length[i];
			}
		}
		for (int j = 1; j <= m; j++) {
			if (from[j] != source && to[j] != source) {
				continue;
			}
			if (from[j] == source && length[to[j]] != -1 && length[source] + cost[j] < length[to[j]]) {
				length[to[j]] = length[source] + cost[j];
				touch[to[j]] = source;
			}
			/* full duplex */
			if (to[j] == source && length[from[j]] != -1 && length[source] + cost[j] < length[from[j]]) {
				length[from[j]] = length[source] + cost[j];
				touch[from[j]] = source;
			}
		}

		length[source] = -1;
	}

	cout << n - 1 << endl;

	for (int i = 1; i <= n; i++) {
		if (touch[i] == 0) {
			continue;
		}
		cout << i << " " <<  touch[i] << endl;
	}
}