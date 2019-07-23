#include <iostream>
#include <fstream>

using namespace std;
void swap(int a, int b);
bool isDouble(int a, int size);
int *A;

int main()
{
	ifstream input;
	int n;

	n = 5;

	A=(int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i] < 1 || A[i]>5 || isDouble(A[i],i)) {
			return 0;
		}
	}
	for (int j = n - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (A[i] > A[i + 1]) {
				swap(i, i + 1);
				for (int a = 0; a < n; a++) {
					cout << A[a] << " ";
					if (a == n - 1)
						cout << endl;
				}
			}
		}
	}
}
void swap(int a, int b) {
	int temp;
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

bool isDouble(int a, int size) {
	for (int i = 0; i < size; i++) {
		if (A[i] == a) {
			return true;
		}
	}
	return false;
}