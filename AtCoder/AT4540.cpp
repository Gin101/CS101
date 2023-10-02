#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string k;
int d = 0;
const int maxD = 100;
const int MOD = 1e9 + 7;
int dp[maxD * maxD][maxD][2] = {{{0}}};
int dfs(int idx, int num, bool flag) {
    if (idx == k.size()) {
        return !num;
    }

    int &result(dp[idx][num][flag]);
    if (~result) {
        return result;
    }

    result = 0;
    for (int i = 0; i <= (flag ? k[idx] - '0' : 9); i++) {
        result = (result + dfs(idx + 1, (num + i) % d, flag && i == (flag ? k[idx] - '0' : 9))) % MOD;
    }

    return result;
}

int main()
{
    cin >> k >> d;

    memset(dp, -1, sizeof(dp));

    cout << (dfs(0, 0, 1) - 1 + MOD) % MOD << endl;

    return 0;
}