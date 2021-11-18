/*
题目描述
有一个箱子容量为V（正整数，0 ≤ V ≤ 20000），同时有n个物品（0 < n ≤ 30)，每个物品有一个体积（正整数）。

要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。

输入格式
1个整数，表示箱子容量

1个整数，表示有n个物品

接下来n行，分别表示这n个物品的各自体积

输出格式
1个整数，表示箱子剩余空间。
*/

#include <iostream>

using namespace std;

const int maxN = 31;
const int maxV = 20001;
int w[maxN] = {0};
bool dp[maxN][maxV] = {{false}}; // dp[i][j] means from 1 to i, bag is j

int main()
{
    int v = 0;
    cin >> v;

    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) {
                dp[i][j] |= dp[i - 1][j - w[i]];
            } 
        }
    }

    for (int i = v; i >= 0 ; i--) {
        if (dp[n][i]) {
            cout << v - i << endl;
            return 0;
        }
    }
    
    return 0;
}
