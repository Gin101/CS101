#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

const int maxN = 2e5;
const int maxK = 2e5;
string s;
int n = 0;
int k = 0;
int d = 0;
int tmp = 0;
int tmp3[maxK] = {0};
int result[maxN] = {0};
void dfs(int idx, int num, int tmp2[], int idx2) {
    if (num == k) {
        for (int i = 0; i < k; i++) {
            result[tmp2[i]]++;
        }
        tmp++;
        return;
    }

    if (idx > n - 1) {
        return;
    }

    if (s[idx] == 'x') {
        dfs(idx + 1, num, tmp2, idx2);
    } else {
        tmp2[idx2] = idx;
        dfs(idx + d + 1, num + 1, tmp2, idx2 + 1);
        tmp2[idx2] = 0;
        dfs(idx + 1, num, tmp2, idx2);
    }
}

int main()
{
    // freopen("extra.in", "r", stdin);
    // freopen("extra.out", "w", stdout);

    cin >> n >> k >> d;
    cin >> s;

    dfs(0, 0, tmp3, 0);

    int result2 = 0;
    for (int i = 0; i < n; i++) {
        if (result[i] == tmp) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}