#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int NN = 1;
vector<long long> N;
unsigned int n;

void generator(long long num, int i, int delimit);

int main() {
	long long num = 0;

	cin >> n;
	
	if (n < 0 || n>1000000) {
		return 0;
	}

	while (N.size() < n + 1 ) {
		if (NN == 11) {
			cout << -1 << endl;
			return 0;
		}
		generator(0,NN++,10);
	}
	cout << N.at(n) << endl;
	return 0;
}
void generator(long long num, int i, int delimit) {
	if (i == 0 || N.size() >= n + 1) {
		return ;
	}
	for (int k = 0; k < delimit; k++) {
		num -= (num%(long long)pow(10, i));
		num+=k* (long long)pow(10, i - 1);
		if (i == 1) {
			N.push_back(num);
			if (N.size() >= n + 1) {
				return;
			}
		}
		else {
			generator(num, i - 1, k);
		}
	}
}
