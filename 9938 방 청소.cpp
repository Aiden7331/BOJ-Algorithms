#include <iostream>
#include <vector>

using namespace std;
int parent[300001];
int root[300001];

void merge(int a, int b);
int find(int i);

int main() {
	int n, l, a, b;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;
	for(int i=1; i<=l; i++){
		parent[i] = i;
		root[i] = 1;
	}
	for (int k = 1, ta, tb; k <= n; k++) {	
		cin >> a >> b;
		a = find(a);
		b = find(b);
		if (root[a] >= 1) {
			root[a]--;
			merge(a, b);
			root[b] += root[a];
		}
		else if (root[b] >= 1) {
			root[b]--;
			merge(b, a);
			root[a] += root[b];
		}
		else {
			printf("SMECE\n");
		}
	}
}

int find(int i) {
	if (parent[i]==i) {
		return i;
	}
	else {
		return parent[i] = find(parent[i]);
	}
}

void merge(int a, int b) {
	if (find(a) != find(b)) {
		parent[a] = b;
	}
	printf("LADICA\n");
}