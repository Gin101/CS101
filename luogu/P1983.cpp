#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <cstring>

using namespace std;

const int maxN = 1000;
const int maxM = 1000;
int num[maxN] = {0};
int dp[maxN] = {0};
int in[maxN] = {0};
int out[maxN] = {0};
bool vis[maxN][maxM] = {{0}};
vector<int> e[maxN];
bool flag[maxN] = {0};
queue<int> q;
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        memset(flag, false, sizeof(flag));
        int s = 0;  
        cin >> s;

        for (int j = 1; j <= s; j++) {
            cin >> num[j];
            flag[num[j]] = true;
        }

        for (int j = num[1]; j <= num[s]; j++) {
            if (!flag[j]) {
                for (int k = 1; k <= s; k++) {
                    if (!vis[j][num[k]]) {
                        e[num[k]].push_back(j);
                        in[j]++;
                        out[num[k]]++;
                        vis[j][num[k]] = true;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }

    while (!q.empty()) {
        for (int i = 0; i < e[q.front()].size(); i++) {
            dp[e[q.front()][i]] = dp[q.front()] + 1;
            in[e[q.front()][i]]--;
            if (in[e[q.front()][i]] == 0) {
                q.push(e[q.front()][i]);
            }
        }

        q.pop();
    }
 
    int result = INT_MIN;
    for (int i = 1; i <= n; i++) {
        result = max(result, dp[i]);
    }

    cout << result << endl;

    return 0;
}