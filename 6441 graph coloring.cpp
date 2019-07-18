#include <iostream>
#include <vector>

using namespace std;

void m_coloring(int i, int black = 0);
bool promising(int i);
int n, m, bmax = 0;
vector<int> vcolor;
vector<vector<bool>> W;
vector<int> bcolor;

int main() {
	int k;
	cin >> m;
	if (m < 1) {
		return 0;
	}
	for (int l = 1; l <= m; l++) {
		cin >> n >> k;
		if (n < 1 || n > 100) {
			return 0;
		}
		vcolor.resize(n + 1);
		W = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));

		for (int i = 1; i <= k; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			if (v1 == v2 || v1 < 1 || v1 > n || v2 < 1 || v2 > n ) {
				return 0;
			}
			W[v2][v1] = W[v1][v2] = true;
		}
		m_coloring(0);
		cout << bmax << endl;
		for (int i = 0; i < bmax; i++) {
			cout << bcolor[i] << " ";
		}
		cout << endl;
		bmax = 0;
	}
}

void m_coloring(int i, int black) {

	if (promising(i)) {
		if (i == n) {
			if (black > bmax) {
				bmax = black;
				bcolor.clear();
				for (int j = 1; j <= n; j++) {
					if (vcolor[j] == 1) {
						bcolor.push_back(j);
					}
				}
			}
			return;
		}
		else {
			vcolor[i + 1] = 1;
			m_coloring(i + 1, black + 1);
			vcolor[i + 1] = 2;
			m_coloring(i + 1, black);
		}
	}
}

bool promising(int i) {
	int j = 1;
	bool promise = true;

	while (j < i && promise) {
		if (W[i][j] && vcolor[i] == 1 && vcolor[j] == 1) {
			promise = false;
		}
		j++;
	}
	return promise;
}