#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

bool zs(int x) {
    int t = sqrt(x);

    for (int i = 2; i <= t; ++i) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int S = 0;
int A = 0;
int g[6][6] = {{0}};
int hz[100001] = {0};
int qz[100001] = {0};
int jx1 = 0;
int jx2 = 0;
int sum = 0;
int L[10] = {0};
int R[10] = {0};
int p[6] = {1, 10, 100, 1000, 10000, 100000};
void outp() {
    for (int i = 1; i <= 5; ++i) {
        cout << L[i] << endl;
    }

    cout << endl;
}
void add(int x) {
    int a[6] = {0, x / 10000, x / 1000 % 10, x / 100 % 10, x / 10 % 10, x % 10};

    if (a[1] + a[2] + a[3] + a[4] + a[5] != S) {
        return;
    }

    if (!zs(x)) {
        return;
    }

    int i = x;
    qz[i / 10000] = qz[i / 1000] = qz[i / 100] = qz[i / 10] = qz[i] = true;
    hz[i % 10000] = hz[i % 1000] = hz[i % 100] = hz[i % 10] = hz[i] = true;
}
void dfs(int x, int y) {
    if (y == 6) {
        y = 1;
        x += 1;
    }

    if (x == 6) {
        ++sum;
        outp();
        return ;
    }

    bool ok1 = false;
    bool ok2 = false;
    bool ok3 = false;
    bool ok4 = false;

    for (int i = 0; i <= 9; ++i) {
        ok1 = qz[L[x] * 10 + i];
        ok2 = qz[R[y] * 10 + i];
        ok3 = ((x != y) || (x == y && qz[jx1 * 10 + i]));
        ok4 = ((x + y != 6) || (x + y == 6 && hz[jx2 + i * p[x - 1]]));

        if (!(ok1 && ok2 && ok3 && ok4)) {
            continue;
        }

        L[x] = L[x] * 10 + i;
        R[y] = R[y] * 10 + i;

        if (x == y) {
            jx1 = jx1 * 10 + i;
        }

        if (x + y == 6) {
            jx2 = jx2 + i * p[x - 1];
        }

        dfs(x, y + 1);
        L[x] /= 10;
        R[y] /= 10;

        if (x == y) {
            jx1 /= 10;
        }

        if (x + y == 6) {
            jx2 -= i * p[x - 1];
        }
    }
}
int main() 
{
    cin >> S >> A;

    for (int i = 10003; i <= 99999; i += 2) {
        add(i);
    }

    memset(g, -1, sizeof(g));
    g[1][1] = A;
    L[1] = R[1] = jx1 = A;
    dfs(1, 2);

    if (sum == 0) {
        cout << "NONE" << endl;
    }

    return 0;
}