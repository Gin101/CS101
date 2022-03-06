#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 11;
const int _maxN = 1 << maxN;
long long sta[_maxN] = {0};
long long sit[_maxN] = {0};
long long dp[maxN][_maxN][maxN * maxN] = {{{0}}};
int n = 0;
int k = 0;
int cnt = 0;
void dfs(int x, int num, int idx) {
    if (idx >= n) { 
        sit[++cnt] = x;
        sta[cnt] = num;
        return;
    }
    dfs(x, num, idx + 1);  
    dfs(x + (1 << idx), num + 1, idx + 2);  
}

bool check(int j, int x) {
    if ((sit[j] & sit[x]) || ((sit[j] << 1) & sit[x]) || (sit[j] & (sit[x] << 1)) ) {
        return false;
    }

    return true;
}

int main() 
{
    cin >> n >> k;
    dfs(0, 0, 0); 
    for (int j = 1; j <= cnt; j++) {
        dp[1][j][sta[j]] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= cnt; j++) {
            for (int x = 1; x <= cnt; x++) {
                if (!check(j, x)) {
                    continue;
                } 
                for (int l = sta[j]; l <= k; l++) {
                    dp[i][j][l] += dp[i - 1][x][l - sta[j]];
                } 
            }
        }
    }
        
    long long result = 0;
    for (int i = 1; i <= cnt; i++) {
        result += dp[n][i][k]; 
    }
    cout << result << endl;

    return 0;
}