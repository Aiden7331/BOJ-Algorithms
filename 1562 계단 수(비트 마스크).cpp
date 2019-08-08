#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

long long fun(int i, int num, int used); 
int bitmask(int target, int dec);
static long long D[101][10][1024];
int n;
long long ans = 0, mod = 1000000000;

int main() {
	int pos = 1;
	cin >> n;

	if (n < 10) {
		cout << 0;
		return 0;
	}
	for (int num = 1; num <= 9; num++) {
		ans += fun(1, num, bitmask(0, num));
		ans %= mod;
	}
	cout << ans;
}

long long fun(int pos, int num, int used) {
	if (pos == n && used == 1023) {
		return D[pos][num][used] = 1;
	}
	else if(pos == n){
		return 0;
	}

	if (D[pos][num][used] != 0) {
		return D[pos][num][used] % mod;
	}
	if (num > 0 && num < 9) {
		return D[pos][num][used] = fun(pos + 1, num + 1, bitmask(used, num + 1)) + fun(pos + 1, num - 1, bitmask(used, num - 1));
	}
	else if (num > 0) {
		return D[pos][num][used] = fun(pos + 1, num - 1, bitmask(used, num - 1));
	}
	else if (num < 9) {
		return D[pos][num][used] = fun(pos + 1, num + 1, bitmask(used, num + 1));
	}
}

int bitmask(int target, int dec) {
	int bit = 1 << dec;
	return target|bit;
}