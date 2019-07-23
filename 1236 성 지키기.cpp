#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> M;
vector<int> R, C;
int n, m;

int main() {
	int ans = 0;
	cin >> n >> m;
	M = vector<vector<char>>(n + 1, vector<char>(m + 1, 0));
	R.resize(n + 1);
	C.resize(m + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> M[i][j];
			if (M[i][j] == 'X') {
				R[i]++;
				C[j]++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (R[i] == 0) {
			for (int j = 1; j <= m; j++) {
				if (C[j] == 0) {
					M[i][j] = 'X';
					C[j]++;
					R[i]++;
					ans++;
					break;
				}
				else if (j == m) {
					M[i][j] = 'X';
					C[j]++;
					R[i]++;
					ans++;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (C[i] == 0) {
			for (int j = 1; j <= n; j++) {
				if (R[j] == 0) {
					M[j][i] = 'X';
					C[i]++;
					R[j]++;
					ans++;
					break;
				}
				else if (j == n) {
					M[j][i] = 'X';
					C[i]++;
					R[j]++;
					ans++;
				}
			}
		}
	}

	cout << ans;
}