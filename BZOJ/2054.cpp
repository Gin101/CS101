#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxN = 1e6 + 1;
int f[maxN] = {0};
int result[maxN] = {0};

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}

int main()
{
    int n = 0;
    int m = 0;
    int p = 0;
    int q = 0;
    cin >> n >> m >> p >> q;

    for (int i = 1; i <= n + 1; i++) {
        f[i] = i;
    }

    for (int i = m; i >= 1; i--) {
        int l = (i * p + q) % n + 1;
        int r = (i * q + p) % n + 1;
        if (l > r) {
            swap(l, r);
        }
        int idx = find(l);
        while (idx <= r) {
            f[idx] = idx + 1;
            result[idx] = i;
            idx = find(idx + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}