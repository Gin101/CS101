#include <iostream>
#include <vector>

using namespace std;

const int maxN = 15e4 + 1;
const int maxXY = 3e6 + 1;
vector <int> v[maxN];
int dp[maxXY] = {0}; // dp[i] means we choose the 1 ~ i, and the max result

int main()
{
    int n = 0;
    cin >> n;

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        v[y].push_back(x - 1);
        tmp = max(tmp, y);
    }

    // base case : 0

    for (int i = 1; i <= tmp; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < v[i].size(); j++) {
            dp[i] = max(dp[i], dp[v[i][j]] + i - v[i][j]);
        }
    }

    cout << dp[tmp] << endl;

    return 0;
}