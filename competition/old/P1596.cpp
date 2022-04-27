#include <iostream>

using namespace std;

int n = 0;
int m = 0;
const int maxNM = 100;
char lake[maxNM][maxNM] = {{0}};
int result = 0;

void dfs(int row, int col) {
	lake[row][col] = '.';
	if ((row + 1) < n && lake[row + 1][col] == 'W') {
		dfs(row + 1, col);
	}
	if ((row - 1) >= 0 && lake[row - 1][col] == 'W') {
		dfs(row - 1, col);
	}
	if ((col + 1) < m && lake[row][col + 1] == 'W') {
		dfs(row, col + 1);
	}
	if ((col - 1) >= 0 && lake[row][col - 1] == 'W') {
		dfs(row, col - 1);
	}
	if ((row - 1) >= 0 && (col - 1) >= 0 &&
		lake[row - 1][col - 1] == 'W') {
		dfs(row - 1, col - 1);
	}
	if ((row - 1) >= 0 && (col + 1) < m &&
		lake[row - 1][col + 1] == 'W') {
		dfs(row - 1, col + 1);
	}
	if ((row + 1) < n && (col - 1) >= 0 &&
		lake[row + 1][col - 1] == 'W') {
		dfs(row + 1, col - 1);
	}
	if ((row + 1) < n && (col + 1) < m &&
		lake[row + 1][col + 1] == 'W') {
		dfs(row + 1, col + 1);
	}
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lake[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lake[i][j] == 'W') {
				dfs(i, j);
				result++;
			}
		}
	}
	
	cout << result << endl;
	
	return 0;
}