#include <iostream>
#include <vector>
#include <math.h>

#define INF 999999999
using namespace std;
vector<int> N;
int main() {
	
	int n, k;
	long double min = INF, mean, dev; // dev = standard deviation

	cin >> n >> k;

	N.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> N[i];
	}
	
	for (int diff = k; diff <= n; diff++) {
		for (int i = 0; i+diff <= n; i++) {
			dev = mean = 0;
			for (int j = i + 1; j <= i+diff; j++) {
				mean += N[j];
			}
			mean /= diff;
			for (int j = i + 1; j <= i + diff; j++) {
				dev += pow(N[j] - mean, 2);
			}
			dev /= diff;
			dev = sqrt(dev);
			if (min > dev) {
				min = dev;
			}
		}
		if (diff == n) {
			dev = mean = 0;
			for (int j = 1; j <= diff; j++) {
				mean += N[j];
			}
			mean /= (long double)diff;
			for (int j = 1; j <= diff; j++) {
				dev += pow(N[j] - mean, 2);
			}
			dev /= diff;
			dev = sqrt(dev);
			if (min > dev) {
				min = dev;
			}
		}
	}
	printf("%0.11LF", min);
}
