#include <iostream>
#include <vector>
#define INF 1000000
using namespace std;

vector<vector<int>> T;
int n, m, x;

int main() {
	
	cin >> n >> m >> x;

	if (n < 1 || n>1000 || m < 1 || m>10000 || x<1 || x>n) {
		return 0;
	}
	T = vector<vector<int>>(m + 1, vector<int>(4, 0));

	for (int i = 1; i <= m; i++) {
		cin >> T[i][1] >> T[i][2] >> T[i][3];
		if (T[i][1] < 1 || T[i][1] > 1000 || T[i][2] < 1 || T[i][2] > 1000 || T[i][3] < 1 || T[i][3] >100) {
			return 0;
		}
	}

	/* [Dijkstra] destination -> source */
	vector<int> touch, length;
	vector<bool> visit;
	int source = x, temp = 0;
	touch.resize(n + 1);
	length.resize(n + 1);
	visit.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		length[i] = INF;
	}
	for (int i = 1; i <= m; i++) {
		if (T[i][1] == x) {
			length[T[i][2]] = T[i][3];
			touch[T[i][2]] = x;
		}
	}
	visit[x] = true;
	for (int k = 1; k < n - 1; k++) {
		temp = INF;
		for (int i = 1; i <= n; i++) {
			if (visit[i] != true && temp > length[i]) {
				temp = length[i];
				source = i;
			}
		}
		for (int i = 1; i <= m; i++) {
			if (T[i][1] == source && length[source] + T[i][3] < length[T[i][2]]) {
				length[T[i][2]] = length[source] + T[i][3];
				touch[T[i][2]] = source;
			}
		}
		visit[source] = true;
	}
	/* [Dijkstra] source -> destination */
	vector<int> length2;
	source = x, temp = 0;
	touch.resize(n + 1);
	length2.resize(n + 1);
	
	for (int i = 1; i <= n; i++) {
		length2[i] = INF;
		visit[i] = false;
		touch[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		if (T[i][2] == x) {
			length2[T[i][1]] = T[i][3];
			touch[T[i][1]] = x;
		}
	}
	visit[x] = true;
	for (int k = 1; k <= n - 1; k++) {
		temp = INF;
		for (int i = 1; i <= n; i++) {
			if (visit[i] != true && temp > length2[i]) {
				temp = length2[i];
				source = i;
			}
		}
		for (int i = 1; i <= m; i++) {
			if (T[i][2] == source && length2[source] + T[i][3] < length2[T[i][1]]) {
				length2[T[i][1]] = length2[source] + T[i][3];
				touch[T[i][1]] = source;
			}
		}
		visit[source] = true;
	}
	/* solution */
	for (int i = 1; i <= n; i++) {
		if (i == x) {
			continue;
		}
		if (temp < length[i]+length2[i]) {
			temp = length[i]+length2[i];
		}
	}
	cout << temp;
}
