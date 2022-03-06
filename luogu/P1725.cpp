#include <iostream>
#include <algorithm>
#include <limits.h>
 
using namespace std;

const int maxN = 200001;
int n = 0;
int l = 0;
int r = 0;
int a[maxN] = {0};
int dp[maxN] = {0};

int dfs(int x){
    if (x > n) {
        return 0;
    }

    if (dp[x]) {
        return dp[x];
    }

    int tmp = INT_MIN;
    for (int i = x + l; i <= x + r; i++) {
        tmp = max(tmp, dfs(i));
    }

    return dp[x] = tmp + a[x];
}

int main()
{
    cin >> n >> l >> r;

    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    cout << dfs(0) << endl;

    return 0;
}