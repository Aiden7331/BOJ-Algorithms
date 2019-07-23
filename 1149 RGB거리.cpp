#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<vector<int>> H;
	int n;

	cin >> n;
	H = vector<vector<int>>(n + 1, vector<int>(3 + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> H[i][j];
		}
	}

	for (int i = 2; i <= n; i++) {
		H[i][1] += min(H[i - 1][2], H[i - 1][3]);
		H[i][2] += min(H[i - 1][1], H[i - 1][3]);
		H[i][3] += min(H[i - 1][1], H[i - 1][2]);
	}

	cout << min(min(H[n][1], H[n][2]),H[n][3]) << endl;
}