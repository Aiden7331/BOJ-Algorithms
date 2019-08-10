#include <iostream>
#include <vector>
#define mod 1000000
using namespace std;

vector<vector<long long>> divide(long long ex);
vector<vector<long long>> mMulti(vector<vector<long long>> a, vector<vector<long long>> b);
vector<vector<long long>> m;

int main() {
	vector<vector<long long>> m2;
	long long n;

	m = vector<vector<long long>>(3, vector<long long>(3, 0));
	m[1][1] = 1;
	m[1][2] = 1;
	m[2][1] = 1;
	m[2][2] = 0;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}else if (n == 1 || n == 2) {
		cout << 1;
		return 0;
	}
	m2=divide(n - 2);
	printf("%lli",(m2[1][1]%mod + m2[2][1]%mod)%mod);

}

vector<vector<long long>> divide(long long ex) {
	vector<vector<long long>> dp;
	
	if (ex == 1) {
		return m;
	}
	
	dp = divide(ex / 2);
	dp[1][1] %= mod;
	dp[1][2] %= mod;
	dp[2][1] %= mod;
	dp[2][2] %= mod;
	if (ex % 2 == 0) {
		return mMulti(dp, dp);
	}
	else if (ex % 2 == 1) {
		return mMulti(mMulti(dp, dp), m);
	}
}

vector<vector<long long>> mMulti(vector<vector<long long>> a, vector<vector<long long>> b) {
	vector<vector<long long>> rst = vector<vector<long long>>(3, vector<long long>(3, 0));
	//Çà·Ä°ö
	for (int row = 1; row <= 2; row++) {
		for (int col = 1; col <= 2; col++) {
			for (int indic = 1; indic <= 2; indic++) {
				rst[row][col] =(rst[row][col]%mod + ((a[row][indic]%mod) * (b[indic][col]%mod))%mod)%mod;
			}
		}
	}
	return rst;
}