#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;

const int maxN = 400;
int dr[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int result[maxN][maxN] = {{0}};
bool flag[maxN][maxN] = {{false}};

int main()
{
	int n = 0;
	int m = 0;
	int r = 0;
	int c = 0;
	cin >> n >> m >> r >> c;
	
    r--;
    c--;
	queue<pair<int, int> > q;
	q.push(make_pair(r, c));
	memset(result, -1, sizeof(result));
	result[r][c] = 0;
	flag[r][c] = true;
	while (!q.empty()) {
		for (int i = 0; i < 8; i++) {
			int sumr = q.front().first + dr[i];
			int sumc = q.front().second + dc[i];
			if (sumr >= 0 && sumc >= 0 && !flag[sumr][sumc] && sumr < n && sumc < m) {
                flag[sumr][sumc] = true;
				result[sumr][sumc] = result[q.front().first][q.front().second] + 1;
				q.push(make_pair(sumr, sumc));
			}
		}	
		q.pop();
	}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%-5d", result[i][j]);
        }
        cout << endl;
    }

	return 0;
}