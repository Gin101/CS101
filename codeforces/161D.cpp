#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxN = 50000;
const int maxK = 500;
vector<int> e[maxN];
int dis[maxN][maxK] = {{0}};// dis[i][j] means the descendants of node i have several nodes with a distance of j
int dp[maxN][maxK] = {{0}};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        e[u - 1].push_back(v - 1);
    }

    for (int i = 0; i < n; i++) {
        dis[i][0] = 1;
    } //giganic

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < k; j++) {
            for (int k = 0; k < e[i].size(); k++) {
                dis[i][j] += dis[e[i][k]][j - 1];
            }
        }
    }

    dp[0][0] = 1;//giganic
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            for (int l = 0; l < k; l++) {
                
            }
        }
    }

    return 0;
}