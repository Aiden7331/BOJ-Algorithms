#include <iostream>

using namespace std;

int main()
{
	int n;//µø±º¿« ≥–¿Ã
	int testCase = 1;
	int x = 0, y = 0;
	int **cave;
	int **length;
	char **touch;

    //cout << "Legend of ZELDA" << endl; 
	while (true) {
		cin >> n;
		if (n < 2 || n>125) {
			return 0;
		}
		cave = (int**)malloc(sizeof(int*)*n);
		touch = (char**)malloc(sizeof(char*)*n);
		length = (int**)malloc(sizeof(int*)*n);
		for (int i = 0; i < n; i++) {
			cave[i] = (int*)malloc(sizeof(int)*n);
			touch[i] = (char*)malloc(sizeof(char)*n);
			length[i] = (int*)malloc(sizeof(int)*n);
		}
		/*µµµœ ∑Á««¿« ∞≥ºˆ∏¶ ¿‘∑¬*/
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				cin >> cave[j][i];
				if (cave[j][i] < 0 || cave[j][i]>9) {
					i--;
					continue;
				}
				touch[j][i] = ' ';
				length[j][i] = -2;
			}
		}

		length[0][0] = cave[0][0];

		/*Dijkstra*/
		while (true) {
			int compKey;
			char vector;
			compKey = 999999999;
			vector = NULL;


			if (x == n - 1 && y == n - 1) {
				break;
			}

			if (x != 0 && length[y][x - 1] != -1) {//WEST
				if (length[y][x - 1] == -2 || length[y][x] + cave[y][x - 1] < length[y][x - 1]) {
					length[y][x - 1] = length[y][x] + cave[y][x - 1];
					touch[y][x - 1] = 'R';
				}
			}
			if (y != 0 && length[y - 1][x] != -1) {//NORTH
				if (length[y - 1][x] == -2 || length[y][x] + cave[y - 1][x] < length[y - 1][x]) {
					length[y - 1][x] = length[y][x] + cave[y - 1][x];
					touch[y - 1][x] = 'D';
				}
			}

			if (x != n - 1 && length[y][x + 1] != -1) {//EAST
				if (length[y][x + 1] == -2 || length[y][x] + cave[y][x + 1] < length[y][x + 1]) {
					length[y][x + 1] = length[y][x] + cave[y][x + 1];
					touch[y][x + 1] = 'L';
				}
			}
			if (y != n - 1 && length[y + 1][x] != -1) {//SOUTH
				if (length[y + 1][x] == -2 || length[y][x] + cave[y + 1][x] < length[y + 1][x]) {
					length[y + 1][x] = length[y][x] + cave[y + 1][x];
					touch[y + 1][x] = 'U';
				}
			}

			length[y][x] = -1;

			for (int j = 0; j < n; j++) {
				for (int i = 0; i < n; i++) {
					if (length[j][i] > -1 && compKey > length[j][i]) {
						compKey = length[j][i];
						y = j;
						x = i;
					}
				}
			}

			length[y][x] = compKey;
		}
		x = y = 0;
		cout << "Problem " << testCase++ <<": " << length[n - 1][n - 1] << endl;

		free(cave);
		free(touch);
		free(length);
	}
}