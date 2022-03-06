/*
dp[i]表示从起点到i的最大分数
dp[i] = max(dp[j] + v[i]) j 到 i 有边
O(n + m)
选出度为 0 的点中dp值最大的点
*/

#include <iostream>
#include <algorithm>
#include <vector>;

using namespace std;

const int maxN = 1e5;
const int maxM = 1e6;
int num[maxN] = {0};
int dp[maxN] = {0};
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
    }


    return 0;
}