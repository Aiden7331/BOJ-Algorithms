#include <iostream>
#include <vector>
#define mod 10007

using namespace std;

int main() {
	vector<int> N;
	int n;
	cin >> n;

	N.resize(n + 1);
	N[1] = 1;
	N[2] = 2;
	for (int i = 3; i <= n; i++) {
		N[i] = (N[i - 2]%mod + N[i - 1]%mod)%mod;
	}
	cout << N[n];
}