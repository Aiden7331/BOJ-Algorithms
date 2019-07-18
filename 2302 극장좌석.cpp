#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	vector<vector<long long>> seats;
	queue<int> vip;
	int n, m;
	
	cin >> n >> m;
	if (n < 1 || n>40 || m<0 || m>n) {
		return 0;
	}
	seats = vector<vector<long long>>(n + 1, vector<long long>(3, 0));
	for (int i = 1, temp; i <= m; i++) {
		cin >> temp;
		if (temp<1 || temp>n) {
			return 0;
		}
		vip.push(temp);
	}

	if (vip.empty() == false && vip.front() == 1) {
		seats[1][0] = 1;
		vip.pop();
	}
	else {
		seats[1][0] = 1;
		seats[1][2] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (vip.empty() == false && vip.front() == i) {
			seats[i][0] = seats[i - 1][0] + seats[i - 1][1];
			vip.pop();
		}
		else{
			seats[i][0] = seats[i - 1][0] + seats[i - 1][1];
			seats[i][1] = seats[i - 1][2];
			seats[i][2] = seats[i - 1][0] + seats[i - 1][1];
		}
	}
	cout << seats[n][0] + seats[n][1];
}