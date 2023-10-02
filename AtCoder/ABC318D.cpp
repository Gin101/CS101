#include <iostream>

using namespace std;

const int maxHW = 2001;
int b[maxHW] = {0};
int qr[maxHW * maxHW] = {0};
int qc[maxHW * maxHW] = {0};
int dp[maxHW][maxHW] = {{0}};
int dr[5] = {0, 1, -1, 0, 0};
int dc[5] = {0, 0, 0, 1, -1};
char a[maxHW][maxHW];
int main()
{
    int h = 0;
    int w = 0;
    cin >> h >> w;

    b['>'] = 3;
    b['v'] = 1;
    b['<'] = 4;
    b['^'] = 2;

    int sr = 0;
    int sc = 0;
    int gr = 0;
    int gc = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
        for (int j = 1; j <= w; j++) {
            if (a[i][j] == 'S') {
                sr = i;
                sc = j;
            } else if (a[i][j] == 'G') {
                gr = i;
                gc = j;
            } else if (a[i][j] != '.') {
                dp[i][j] = -1;
            }
        }
    }
	
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            for (int k = 1, tmp = b[a[i][j]], d, r, c; r = i + k * dr[d], c = j + k * dc[d], d; k++) {
                if (r && c && r <= h && c <= w && dp[r][c] != -1) {
                    dp[r][c] = -2;
                } else {
                    break;
                }
            }
        }
    }

    if (dp[sr][sc]) {
        cout << -1 << endl;
        return 0;
    } 

    int l = 1;
    int r = 1;
    dp[sr][sc] = 1;
    qr[1] = sr;
    qc[1] = sc;
	
    while (l <= r) {
        int row = qr[l];
        int col = qc[l++];
        for (int i = 1; i <= 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr && nc && nr <= h && nc <= w && !dp[nr][nc]) {
                qr[++r] = nr;
                qc[r] = nc;
                dp[nr][nc] = dp[row][col] + 1;
            }
        }
    }

    cout << dp[gr][gc] - 1 << endl;

	return 0;
}