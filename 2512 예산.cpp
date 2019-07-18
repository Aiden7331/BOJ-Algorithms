#include <iostream>
#include <vector>

using namespace std;
vector<long long> N;

void quick(int low, int high);
int partition(int low, int high);
int binary(int val, int low, int high);

int main() {
	long long budget, m, margin, tm;
	int n, del, pdel;

	cin >> n;
	N.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> N[i];
	}
	quick(1, n);
	cin >> budget;
	m = budget / n;
	budget -= m * n;
	pdel = 0;
	while (true) {
		del = binary(m, pdel, n);
		if (del == pdel) {
			if (N[n] < m) {
				m = N[n];
			}
			break;
		}
		margin = 0;
		for (int i = pdel + 1; i <= del; i++) {
			margin += (m - N[i]);
		}
		if (n - del != 0) {
			m += (tm = (budget + margin) / (n - del));
			budget+=(margin - tm * (n - del));
		}
		else {
			m = N[n];
			break;
		}
		pdel = del;
	}
	
	cout << m;
}

int binary(int val, int low, int high) {
	int mid = (low + high) / 2;
	if (low >= high) {
		return high;
	}

	if (N[mid] == val) {
		return mid;
	}else if (N[mid] < val) {
		binary(val, mid, high);
	}
	else {
		binary(val, low, mid - 1);
	}
}

void quick(int low, int high) {
	int mid;
	if (low > high) {
		return;
	}
	mid = partition(low, high);
	quick(low, mid - 1);
	quick(mid + 1, high);
}

int partition(int low, int high) {
	int pivot, i;
	long long pivotItem, temp;

	pivot = i = low;
	pivotItem= N[pivot];
	for (int j = low + 1; j <=high; j++) {
		if (pivotItem > N[j]) {
			temp = N[++i];
			N[i] = N[j];
			N[j] = temp;
		}
	}
	N[pivot] = N[i];
	N[i] = pivotItem;
	return i;
}