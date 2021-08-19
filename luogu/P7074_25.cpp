#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <limits.h>

using namespace std;

int n = 0;
int m = 0;
const int maxNM = 1000;
int number[maxNM][maxNM] = {{0}};
int result = INT_MIN;
bool flag[maxNM][maxNM] = {{false}};
int tmp[maxNM * maxNM] = {0};

bool cmp(int x, int y) {
	return x > y;
}

void dfs(int sum, int row, int col) {
    if (row == n - 1 && col == m - 1) {
        result = max(result, sum);
        return;
    }
    
//    printf("sum: %d, row: %d, col: %d\n", sum, row, col);

	int maxSum = sum;

	for (int i = 0; i < (n + row - 1 + n + col - 1); i++) {
		maxSum += tmp[i];
	}
	
	if (maxSum <= result) {
		return;
	}
    
    // up
    int nextStep = row - 1;
    if (nextStep >= 0 && !flag[nextStep][col]) {
    	flag[nextStep][col] = true;
    	dfs(sum + number[nextStep][col], nextStep, col);
    	flag[nextStep][col] = false;
	}
	
	// right
	nextStep = col + 1;
	if (nextStep < m && !flag[row][nextStep]) {
		flag[row][nextStep] = true;
		dfs(sum + number[row][nextStep], row, nextStep);
		flag[row][nextStep] = false;
	}
	
	// down
	nextStep = row + 1;
	if (nextStep < n && !flag[nextStep][col]) {
    	flag[nextStep][col] = true;
    	dfs(sum + number[nextStep][col], nextStep, col);
    	flag[nextStep][col] = false;
	}
}

int main()
{
    freopen("P7074.in", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> number[i][j];
            tmp[i * m + j] = number[i][j];
        }
    }
    
    sort(tmp, tmp + n * m, cmp);

	flag[0][0] = true;
    dfs(number[0][0], 0, 0);

    cout << result << endl;

    return 0;
}
