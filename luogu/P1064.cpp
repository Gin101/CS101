#include <iostream>
#include <algorithm>

using namespace std;

const int maxM = 61;
const int maxN = 32001;
int mv[maxM] = {0};// main v
int mp[maxM] = {0};// main p
int av[maxM][2] = {0};//annex v
int ap[maxM][2] = {0};//annex p
int uv[maxM][4] = {{0}};//union v
int up[maxM][4] = {{0}};//union p
int idx[maxM] = {0};
int dp[maxN] = {0};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int v = 0;
        int p = 0;
        int q = 0;
        cin >> v >> p >> q;

        if (q != 0) {
            av[q][idx[q]] = v;
            ap[q][idx[q]++] = v * p;
        } else {
            mv[i] = v;
            mp[i] = v * p;
        }
    }

    for (int i = 1; i <= m; i++) {
        uv[i][0] = mv[i];
        uv[i][1] = mv[i] + av[i][0];
        uv[i][2] = mv[i] + av[i][1];
        uv[i][3] = mv[i] + av[i][1] + av[i][0];
        up[i][0] = mp[i];
        up[i][1] = mp[i] + ap[i][0];
        up[i][2] = mp[i] + ap[i][1];
        up[i][3]= mp[i] + ap[i][1] + ap[i][0];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 0; j--) {
            if (j >= uv[i][0]) {
                dp[j] = max(dp[j], dp[j - uv[i][0]] + up[i][0]);
            }
            if (j >= uv[i][1]) {
                dp[j] = max(dp[j], dp[j - uv[i][1]] + up[i][1]);
            }
            if (j >= uv[i][2]) {
                dp[j] = max(dp[j], dp[j - uv[i][2]] + up[i][2]);
            }
            if (j >= uv[i][3]) {
                dp[j] = max(dp[j], dp[j - uv[i][3]] + up[i][3]);
            }
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}