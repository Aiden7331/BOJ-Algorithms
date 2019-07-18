#include <iostream>
#include <vector>

using namespace std;

void sudoku(int i, int j);
bool promising(int i, int j);

vector<vector<int>> M;

int main() {
	M = vector<vector<int>>(9 + 1, vector<int>(9 + 1, 0));
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> M[i][j];
			if (M[i][j] < 0 || M[i][j]>9) {
				return 0;
			}
		}
	}
	sudoku(1, 0);

}

void sudoku(int i, int j) {
	if (promising(i,j)) {
		if (i == 9 && j == 9) {
			for (int n = 1; n <= i; n++) {
				for (int m = 1; m <= j; m++) {
					cout << M[n][m] << " ";
				}
				cout << endl;
			}
			exit(0);
		}
		if (j == 9) {
			i++;
			j = 0;
		}
		if (M[i][j + 1] == 0) {
			for (int k = 1; k <= 9; k++) {
				M[i][j + 1] = k;
				sudoku(i, j + 1);
			}
			/* 다 실패한 경우 */
			M[i][j + 1] = 0;
		}
		else {
			sudoku(i, j + 1);
		}
		
	}
}

bool promising(int i, int j) {
	bool promise = true;
	int rect = 1;
	int ri = 1 + ((i - 1) / 3)*3;
	int rj = 1 + ((j - 1) / 3)*3;

	if (i == 0 || j == 0) {
		return promise;
	}
	while (promise && rect<=9) {
		if (j!= rect && M[i][j] == M[i][rect]) {
			promise = false;
		}
		if (i != rect && M[i][j] == M[rect][j]) {
			promise = false;
		}
		if (i != ri && j != rj && M[i][j] == M[ri][rj]) {
			promise = false;
		}
		if (rj % 3 == 0) {
			ri++;
			rj = 1 + ((j - 1) / 3) * 3;
		}
		else {
			rj++;
		}
		rect++;
	}
	return promise;
}