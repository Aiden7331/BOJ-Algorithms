#include <iostream>
#include <vector>
#include <math.h>

#define UNIT 10000
using namespace std;

int binary(vector<vector<int>> v, int val, int low, int high);

int main() {
	vector<vector<int>> league1(7 + 1, vector<int>(2, 0));
	vector<vector<int>> league2(6 + 1, vector<int>(2, 0));
	
	league1[1][0] = 500 * UNIT;
	league1[2][0] = 300 * UNIT;
	league1[3][0] = 200 * UNIT;
	league1[4][0] = 50 * UNIT;
	league1[5][0] = 30 * UNIT;
	league1[6][0] = 10 * UNIT;
	league1[7][0] = 0;
	league1[7][1] = 100;
	league2[6][0] = 0;
	league2[6][1] = 64;

	for (int i = 1, count = 9; i <= 6; i++) {
		league1[i][1] = league1[i-1][1] + i;
		if (i != 6) {
			league2[i][0] = pow(2, count--) * UNIT;
			league2[i][1] = league2[i-1][1] + pow(2, i - 1);
		}
	}
	int f, s, n;
	cin >> n;
	if (n < 1 || n>1000) {
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> f >> s;
		if (f < 0 || f>100 || s < 0 || s> 64) {
			return 0;
		}
		f = binary(league1, f, 0, league1.size());
		s = binary(league2, s, 0, league2.size());
		cout << league1[f][0] + league2[s][0] << endl;
	}
}

int binary(vector<vector<int>> v, int val, int low, int high) {
	int i = (low + high)/2;

	if (low >= high) {
		return i;
	}

	if (v[i][1] == val) {
		return i;
	}
	else if (v[i][1] < val) {
		return binary(v, val, i + 1, high);
	}
	else {
		return binary(v, val, low, i);
	}
}