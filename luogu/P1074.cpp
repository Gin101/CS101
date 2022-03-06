#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

struct Row {
    int cnt = 0;
    int idx = 0;
    int maxS = 0;
} p[10];
int square[3] = {0};

int num[10][10] = {{0}};
int result = -1;
bool cmp(Row x, Row y) {
    return x.cnt == y.cnt ? x.maxS > y.maxS : x.cnt < y.cnt;
}

bool check(int r, int f, int n){
    for (int i = 1; i <= 9; i++) {
        if (num[r][i] == n) {
        	return false;
        }
        if (num[i][f] == n) {
        	return false;
        }
        if (num[3 * ((r - 1) / 3) + ((i - 1) / 3) + 1][3 * ((f - 1) / 3) + ((i - 1) % 3) + 1] == n) {
            return false;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (num[(r - 1) / 3 * 3 + 1 + i][(f - 1) / 3 * 3 + 1 + j] == n) {
            	return false;	
            }
        }
    }        
    return true;
}

void dfs(int r, int c) {
    if (r > 9) {
        int sum = 0;
        for (int i = 1; i <= 9; i++) {
        	for (int j = 1; j <= 9; j++) {
            	sum += num[i][j] * 6;
        	}
    	}

        for (int i = 2; i <= 8; i ++) {
            for (int j = 2; j <= 8; j++) {
                sum += num[i][j];
            }
        }

        for (int i = 3; i <= 7; i++) {
            for (int j = 3; j <= 7; j++) {
                sum += num[i][j];
            }
        }

        for (int i = 4; i <= 6; i++) {
            for (int j = 4; j <= 6; j++) {
                sum += num[i][j];
            }
        }
        sum += num[5][5];   
        result = max(result, sum);
    }
    if (num[p[r].idx][c] > 0) {
        if (c == 9) {
        	dfs(r + 1, 1);
        } else {
        	dfs(r, c + 1);
        }
    } else {
        for (int i = 1; i <= 9; i++) {
            if (check(p[r].idx, c, i)) {
                num[p[r].idx][c] = i;
                if (c == 9) {
                	dfs(r + 1, 1);
                } else {
                	dfs(r, c + 1);
                }
                num[p[r].idx][c] = 0;
            }
    	}	
    }
}
int main() 
{
	for (int i = 1; i <= 9; i++) {
        memset(square, 0, sizeof(square));
		for (int j = 1; j <= 9; j++) {
            scanf("%d", &num[i][j]);
            if (num[i][j] == 0) {
                p[i].cnt++;
                if (j <= 3) {
                    square[0]++;
                } else if (j <= 6) {
                    square[1]++;
                } else {
                    square[2]++;
                }
            }
            p[i].maxS = max(square[0], max(square[1], square[2]));
            p[i].idx = i;
		}
	}

    sort(p + 1, p + 10, cmp);

    dfs(1, 1);

    printf("%d\n", result);
    
    return 0;
}