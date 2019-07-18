#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int paint(int x, int y);

struct point {
	int x;
	int y;
};

vector<vector<int>> M;
queue<point> pPath;
int numbering = 1;
int n;

int main() {
	char temp;

	cin >> n;
	
	if (5 > n || n > 25) {
		return 0;
	}

	M=vector<vector<int>>(n+1, vector<int>(n+1, 0));
	vector<int> P;
	priority_queue<int,vector<int>,greater<int>> num;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			if ((temp-'1' > 0)) {
				return 0;
			}
			if (temp != '\n') {
				M[i][j] = (int)temp - '0';
			}
		}
	}
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (M[i][j] == 1) {
				num.push(paint(j,i));
			}
		}
	}

	cout << num.size() << endl;
	while (num.empty() != true) {
		cout << num.top() << endl;
		num.pop();
	}

	return 0;
}

int paint(int x, int y) {
	int count = 0;
	point P = { x,y };
	point temp;
	pPath.push(P);
	
	numbering++;

	while (pPath.empty() != true) {
		P = pPath.front();
		pPath.pop();
		if (M[P.y][P.x] == 1) {
			M[P.y][P.x] = numbering;
			count++;
		}
		else {
			continue;
		}
		/*WEST*/
		if (P.x - 1 > 0 && M[P.y][P.x - 1] == 1) {
			temp = { P.x - 1,P.y};
			pPath.push(temp);
		}
		
		/*NORTH*/
		if (P.y - 1 > 0 && M[P.y - 1][P.x] == 1) {
			temp = { P.x,P.y - 1 };
			pPath.push(temp);
		}

		/*EAST*/
		if (P.x + 1 <= n && M[P.y][P.x + 1] == 1) {
			temp = { P.x + 1, P.y};
			pPath.push(temp);
		}

		/*SOUTH*/
		if (P.y + 1 <= n && M[P.y + 1][P.x] == 1) {
			temp = { P.x, P.y + 1};
			pPath.push(temp);
		}
	}
	return count;
}