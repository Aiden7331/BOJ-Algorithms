#include <iostream>
#include <vector>

using namespace std;


int main() {
	int n;

	cin >> n;

	if (n < 0 || n>90) {
		return 0;
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	vector<vector<long long>> pinary(n,vector<long long>(2,0));

	

	pinary[0][1] = 1;
	pinary[1][0] = 1;

	for (int i = 2; i < n; i++) {
		pinary[i][0] = pinary[i - 1][0] + pinary[i - 1][1];
		pinary[i][1] = pinary[i - 1][0];
	}
	cout << pinary[n - 1][0] + pinary[n - 1][1];
}
