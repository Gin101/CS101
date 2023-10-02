/*
dp[i]表示从起点到i的最大分数
dp[i] = max(dp[j] + v[i]) j 到 i 有边
O(n + m)
选出度为 0 的点中dp值最大的点
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 1e5;
const int INF = 0x3f3f3f3f;
int num[maxN] = {0};
int in[maxN] = {0};
int out[maxN] = {0};
int dp[maxN] = {0};
queue<int> q;
struct Node {
    int next = 0;
    int val = 0;
};
vector<Node> e[maxN];

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 1; i < m; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;
        
        in[v - 1]++;
        out[u - 1]++;
        e[u - 1].push_back(Node{v - 1, num[v - 1]});
    }

    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            dp[i] = num[i];
        } else {
            dp[i] = -INF;
        }
    }

    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            in[i] = -1;
            q.push(i);
            dp[i] = 1;
        }
    }

    while (!q.empty()) {
        for (int i = 0; i < e[q.front()].size(); i++) {
            dp[e[q.front()][i].next] = dp[q.front()] + 1;
            in[e[q.front()][i].next]--;
            if (in[e[q.front()][i].next] == 0) {
                q.push(e[q.front()][i].next);
            }
        }

        q.pop();
    }


    return 0;
}