/* Prim's Algorithm */

#include <iostream>
#include <vector>
#include <math.h>

#define INF 99999999999

using namespace std;
double pythagoras(double x1, double x2, double y1, double y2);
int main() {
	vector<vector<double>> adj;
	vector<vector<int>> F;
	vector<double> x, y, C;
	vector<int> E;
	int n;

	cin >> n;
	adj = vector<vector<double>>(n + 1, vector<double>(n + 1, 0));
	x.resize(n + 1);
	y.resize(n + 1);
	C.resize(n + 1, INF);
	E.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int u = 1; u <= n; u++) {
		for (int v = u + 1; v <= n; v++) {
			if (u != v) {
				adj[v][u] = adj[u][v] = pythagoras(x[u], x[v], y[u], y[v]);
			}
		}
	}
	/* prim */
	int u = 1, next = -1;
	double mini = INF;
	vector<bool> visit;
	visit.resize(n + 1);
	C[u] = 0;
	for (int k = 1; k <= n; k++) {
		visit[u] = true;
		for (int v = 1; v <= n; v++) {
			if (visit[v] != true && C[v] > adj[u][v]) {
				C[v] = adj[u][v];
				E[v] = u;
			}
		}
		mini = INF;
		for (int v = 1; v <= n; v++) {
			if (visit[v]!=true && mini > C[v]) {
				mini = C[v];
				next = v;
			}
		}
		if (mini == INF) break;
		F.push_back({ E[next],next }); 
		u = next;
	}
	vector<vector<int>>::iterator it = F.begin();
	vector<int>temp;
	double sum = 0;
	while (it != F.end()) {
		temp = *it;
		sum += adj[temp[0]][temp[1]];
		++it;
	}
	printf("%.2f", sum);
}

double pythagoras(double x1, double x2, double y1, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
