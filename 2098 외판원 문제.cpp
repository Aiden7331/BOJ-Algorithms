#include <iostream>
#include <vector>
#include <math.h>

#define INF 100000000

using namespace std;

int n;
vector<vector<int>> D;
vector<vector<int>> P;
int main() {
	
	int temp;
	cin >> n;
	if (n<2 || n>16) {
		return 0;
	}
	vector<vector<int>> M(n + 1, vector<int>(n + 1,0));
	D = vector<vector<int>>(n + 1, vector<int>((int)pow(2,n)-1 + 1, INF));
	P = vector<vector<int>>(n + 1, vector<int>((int)pow(2,n)-1 + 1, 0));

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			cin >> temp;
			if (temp < 0 || temp > 1000000) {
				return 0;
			}
			else if (temp == 0) {
				temp = INF;
			}
			M[j][i] = temp;
		}
	}
	vector<int> A;
	int count;
	int left;
	for (int j = 1; j < (int)pow(2, n) - 1; j++){
		count = 1;
		left = j;
		
		while (left == 1 || left / 2 != 0) {
			if (left % 2 == 1) {
				A.push_back(count);
			}
			left /= 2;
			count++;
		}
		
		for (int i = 1; i <= n; i++) {
			if (A.size() == 1) {
				if (A[0] == i) {
					D[i][j] = INF;
					continue;
				}
				else if (A[0] != 1) {
					D[i][j] = M[i][A[0]] + M[A[0]][1];
					continue;
				}
				else {
					D[i][j] = M[i][A[0]];
					continue;
				}
			}

			for (int k = A.size() - 1; k >= 0; k--) {
				if (A[k] == i) {//i가 A에 속해있으면 0을 반환.
					D[i][j] = INF;
					continue;
				}

				if (M[i][A[k]] + D[A[k]][j - (int)pow(2, A[k] - 1)] < D[i][j]) {
					D[i][j] = M[i][A[k]] + D[A[k]][j - (int)pow(2, A[k] - 1)];
					//D[i][left] = M[i][A[k]] + D[(int)pow(2, A[k] - 1)][left - (int)pow(2, A[k] - 1)];
					P[i][j] = A[k];
				}
			}
		}
		A.clear();
	}

	cout << D[1][(int)pow(2, n) - 2];
}