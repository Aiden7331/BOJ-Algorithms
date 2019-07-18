#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point {
	int x;
	int y;
};
vector<vector<int>> M, D, P;
vector<vector<int>> V;

int n, m;

void init_visit();

int main() {
	queue<point> bfs;
	point p;
	int year=0;
	bool anniversary = true;

	cin >> m >> n;
	
	if (n < 3 || m < 3 || n > 300 || m > 300) {
		return 0;
	}

	M = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1, temp; j <= n; j++) {
			cin >> temp;
			M[i][j] = temp;
		}
	}

	D = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
	P = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
	V = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

	point temp;
	while (true) {
		anniversary = true;
		for (int y = 1; y <= m; y++) {
			for (int x = 1; x <= n; x++) {
				if (M[y][x] != 0) {
					if (anniversary) {
						temp.x = x;
						temp.y = y;
						bfs.push(temp);
						anniversary = false;
					}
					/* µÎ µ¢¾î¸®°¡ µÊ*/
					if (P[y][x] != year) {
						cout << year - 1;
						return 0;
					}
					if (x - 1 > 0 && M[y][x - 1] == 0) {
						D[y][x]++;
					}
					if (y - 1 > 0 && M[y - 1][x] == 0) {
						D[y][x]++;
					}
					if (x + 1 <= n && M[y][x + 1] == 0) {
						D[y][x]++;
					}
					if (y + 1 <= m && M[y + 1][x] == 0) {
						D[y][x]++;
					}
				}
			}
		}
		if (anniversary == true) {
			cout << 0;
			return 0;
		}
		year++;
		
		while (bfs.empty() != true) {
			p = bfs.front();
			bfs.pop();
			P[p.y][p.x] = year;
			if (V[p.y][p.x] == 0) {
				V[p.y][p.x] = 1;
				if (p.x - 1 > 0 && M[p.y][p.x - 1] != 0) {
					temp.x = p.x - 1;
					temp.y = p.y;
					bfs.push(temp);
				}
				if (p.y - 1 > 0 && M[p.y - 1][p.x] != 0) {
					temp.x = p.x;
					temp.y = p.y - 1;
					bfs.push(temp);
				}
				if (p.x + 1 <= n && M[p.y][p.x + 1] != 0) {
					temp.x = p.x + 1;
					temp.y = p.y;
					bfs.push(temp);
				}
				if (p.y + 1 <= m && M[p.y + 1][p.x] != 0) {
					temp.x = p.x;
					temp.y = p.y + 1;
					bfs.push(temp);
				}
				M[p.y][p.x] = M[p.y][p.x] < D[p.y][p.x] ? 0 : M[p.y][p.x] - D[p.y][p.x];
				D[p.y][p.x] = 0;
			}
		}
		init_visit();
	}
}

void init_visit() {
	for (int y = 1; y <= m; y++) {
		for (int x = 1; x <= n; x++) {
			if(V[y][x] == 1) V[y][x]=0;
		}
	}
}