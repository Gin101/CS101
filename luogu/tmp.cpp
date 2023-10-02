#include <iostream>

using namespace std;

int n = 0;
int m = 0;
const int maxNM = 100;
char chess[maxNM][maxNM] = {{0}};

void dfs(int row, int col) {
	bool flag = false;
	if (chess[row][col] == 'B') {
		flag = true;
	}
	
	if ((row + 1) < n && chess[row + 1][col] == '.') {
		if (flag) {
			chess[row + 1][col] = 'W';
		} else {
			chess[row + 1][col] = 'B';
		}
		dfs(row + 1, col);
	}
	if ((row - 1) >= 0 && chess[row - 1][col] == '.') {
		if (flag) {
			chess[row - 1][col] = 'W';
		} else {
			chess[row - 1][col] = 'B';
		}
		dfs(row - 1, col);
	}
	if ((col + 1) < m && chess[row][col + 1] == '.') {
		if (flag) {
			chess[row][col + 1] = 'W';
		} else {
			chess[row][col + 1] = 'B';
		}
		dfs(row, col + 1);
	}
	if ((col - 1) >= 0 && chess[row][col - 1] == '.') {
		if (flag) {
			chess[row][col - 1] = 'W';
		} else {
			chess[row][col - 1] = 'B';
		}
		dfs(row, col - 1);
	}
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chess[i][j] == '.') {
				chess[i][j] = 'B';
				dfs(i, j);	
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << chess[i][j];
		}
		cout << endl;
	}
	
	return 0;
}