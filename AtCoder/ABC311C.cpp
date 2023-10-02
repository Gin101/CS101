#include <iostream>

using namespace std;

const int maxN = 2e5;
bool flag[maxN] = {false};
int a[maxN] = {0};

void num(int u, bool flag, int cnt, int stop) {
    if (flag && u == stop) {
        cout << cnt << endl;
        return;
    }
    num(a[u] - 1, true, cnt + 1, stop);
}

void out(int u, bool flag, int stop) {
    if (flag && u == stop) {
        cout << endl;
        return;
    }

    cout << u + 1 << ' ';
    out(a[u] - 1, true, stop);
}

void dfs(int u) {
    if (flag[u]) {
        num(u, false, 0, u);
        out(u, false, u);
        exit(0);
    }

    flag[u] = true;
    dfs(a[u] - 1);
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            dfs(i);
        }
    }

    return 0;
}