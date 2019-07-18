#include <iostream>
#include <vector>

#define INF 100001

using namespace std;

int main() {
	int n, k;
	int temp;
	vector<int> coins;
	vector<int> D;
	
	cin >> n >> k;
	if (n < 1 || n >100 || k < 1 || k > 10000) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < 1 || temp > 100000) {
			return 0;
		}
		coins.push_back(temp);
	}
	D.resize(k + 1);

	for (int i = 1; i <= k; i++) {
		temp = INF;
		for (int j = 0; j < coins.size(); j++) {
			if (i - coins[j] > -1 && D[i - coins[j]]!=-1 && D[i - coins[j]] < temp) {
				temp = D[i - coins[j]];
			}
		}
		D[i] = (temp==INF?-1:temp + 1);
	}
	cout << D[k];
}