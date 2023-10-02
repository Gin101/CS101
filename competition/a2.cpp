#include <iostream>
#include <stdio.h>

#define int long long

using namespace std;

int n = 0;
const int maxN = 20;
const int maxNum = 2e5;
int a[maxN] = {0};
int num[maxNum] = {0};
int result = 0;
int prime(int num) {
    if (num == 1) {
        return 1;
    }
    int tmp = 2;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i == num) {
                tmp++;
            } else {
                tmp += 2;
            }
        }
    }

    return tmp;
}

void dfs(int idx, int cnt, int limit, int sum) {
    if (cnt == limit) {
        result += prime(sum);
        return;
    }

    for (int i = idx; i < n; i++) {
        dfs(i + 1, cnt + 1, limit, sum + a[i]);
    }
}

signed main()
{
    freopen("a2.in", "r", stdin);
    freopen("a2.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        dfs(0, 0, i + 1, 0);
    }

    cout << result << endl;

    return 0;
}