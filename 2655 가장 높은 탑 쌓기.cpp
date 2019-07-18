#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

#define INF 100000

using namespace std;

struct Block {
	int area;
	int height;
	int weight;
};

int main() {
	int n, count = 0;
	vector<Block> blocks;
	Block block;

	cin >> n;
	if (n < 1 || n>100) {
		return 0;
	}

	vector<vector<int>> M(n + 2, vector<int>(n + 2, 0));
	
	block.area = INF;
	block.height = 0;
	block.weight = INF;
	blocks.push_back(block);
	for (int i = 0; i < n; i++) {
		cin >> block.area >> block.height >> block.weight;
		if (block.area < 1 || block.area>10000 || block.height < 1 || block.height > 10000 || block.weight < 1 || block.weight > 10000) {
			return 0;
		}
		blocks.push_back(block);
	}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (blocks[i].area > blocks[j].area && blocks[i].weight>blocks[j].weight) {
				M[i][j] = blocks[j].height;
			}
			else {
				M[i][j] = -1;
			}
		}
	}
	
	/* topology sorting by DFS */ 
	stack<int> root;
	vector<bool> visit;
	deque<int> travel;
	int now;
	bool exceed=false;
	root.push(0);
	
	for (int i = 0; i <= n; i++) {
		visit.push_back(false);
	}

	while (root.empty() == false) {
		now = root.top();
		for (int i = 1; i <= n; i++) {
			if (M[now][i] != -1 && M[now][i] != 0 && visit[i]==false) {
				root.push(i);
				visit[i] = true;
				break;
			}
			if (i == n) {
				exceed = true;
			}
		}
		if (exceed == true) {
			travel.push_front(root.top());
			root.pop();
			exceed = false;
		}
	}

	/* Bellman - Ford Algorithm */

	vector<int> D, P;
	D.resize(n + 2);
	P.resize(n + 2);
	while(travel.empty()==false) {
		int i = travel.front();
		travel.pop_front();
		for (int j = 1; j <= n + 1; j++) {
			if (M[i][j] != -1 && D[i] + M[i][j] > D[j]) {
				D[j] = D[i] + M[i][j];
				P[j] = i;
			}
		}
	}

	/* print path of the optimal solution */
	int path = n + 1;
	int height = 0;
	vector<int> sol;
	while (P[path] != 0) {
		count++;
		height+=blocks[P[path]].height;
		sol.push_back(P[path]);
		path = P[path];
	}
	cout << count << endl;
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << endl;
	}
	cout << "total height :" << height;
}