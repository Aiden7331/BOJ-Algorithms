#include <iostream>
#include <vector>
#define mod 1000

using namespace std;
vector<vector<long long>> multiple(vector<vector<long long>> a, vector<vector<long long>> b);
vector<vector<long long>> divide(long long ex);
vector<vector<long long>> M;
int n;
int main() {
	long long ex;
	cin >> n >> ex;
	M = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));
	vector<vector<long long>> m = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			cin >> M[row][col];
		}
	}
	m = divide(ex);
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			if (m[row][col] >= mod) { m[row][col] %= mod; }
			cout << m[row][col] << " ";
		}
		cout << endl;
	}
}
vector<vector<long long>> divide(long long ex) {
	vector<vector<long long>> temp;
	if (ex == 1) {
		return M;
	}
	temp = divide(ex/2);
	
	if (ex % 2 == 0) {
		return multiple(temp, temp);
	}
	else {
		return multiple(multiple(temp, temp), M);
	}

}
vector<vector<long long>> multiple(vector<vector<long long>> a, vector<vector<long long>> b) {
	vector<vector<long long>> rst = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			for (int indics = 1; indics <= n; indics++) {
				rst[row][col] = (rst[row][col]%mod + (a[row][indics]%mod * b[indics][col]%mod))%mod;
			}
		}
	}

	return rst;
}