#include <iostream>

using namespace std;

long long multiple(long long a, long long b, long long c);

int main() {
	long long a, b, c;
	long long rst;
	cin >> a >> b >> c;

	rst = multiple(a, b, c);
	cout << rst % c;
}

long long multiple(long long a, long long b, long long c) {
	long long rst;
	if (b == 1) {
		return a%c;
	}

	rst = multiple(a, b / 2, c);

	if (b % 2 == 0) {
		return ((rst%c)*(rst % c))%c;
	}
	else {
		return (((rst%c)*(rst%c)%c)*(a % c))%c;
	}
}
