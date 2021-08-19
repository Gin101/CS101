#include <iostream>

using namespace std;

const int maxN = 1000;
int f[maxN] = {0};
int e[maxN] = {0};
bool flag[maxN] = {false};

int find(int x) {
    while (f[x] != x) {
        x = f[x];
    }
    return x;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        f[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int p = 0;
        int x = 0;
        int y = 0;

        cin >> p >> x >> y;

        if (p == 0 && find(x) != find(y)) {
            f[y] = f[x];
        } else {
            if (find(x) != find(e[y]) && e[y] != 0) {
                f[e[y]] = x;
            }
            if (find(y) != find(e[x]) && e[x] != 0) {
                f[y] = e[x];
            }
            e[x] = y;
            e[y] = x;
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (!flag[find(i)]) {
            flag[find(i)] = true;
            result++;
        } 
    }

    cout << result << endl;

    return 0;
}