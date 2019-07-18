#include <iostream>
#include <vector>

using namespace std;
vector<int> memo;
vector<int> gates;
int cnt=0;

int find(int i);
void init(int n);
bool open = true;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int G, P;
	cin >> G;
	init(G);
	cin >> P;
	for (int i = 0,temp; i < P; i++) {
		cin >> temp;
		if ((temp = find(temp))>0) {
			gates[temp]--;
			cnt++;
		}
		else {
			break;
		}

	}
	cout << cnt << '\n';
}

void init(int n) {
	memo.resize(n + 1);
	gates.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		gates[i] = i;
		memo[i] = i;
	}
}

int find(int i) {
	if (gates[i] == i) {
		return i;
	}
	return gates[i] = find(gates[i]);
}
