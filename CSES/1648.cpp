#include <iostream>

using namespace std;

int n = 0;
const int maxN = 2e5 + 1;
long long x[maxN] = {0};
long long tree[maxN] = {0};

void update(int u, long long num) {
    while (u <= n) {
        tree[u] += num;
        u += u & -u;
    }
}

long long sum(int u) {
    long long result = 0;
    while (u > 0) {
        result += tree[u];
        u -= u & -u;
    }
    return result;
}

int main()
{
    int q = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        update(i, x[i]);
    }

    for (int i = 0; i < q; i++) {
        int o = 0;
        cin >> o;

        if (o == 1) {
            int k = 0;
            long long u = 0;
            cin >> k >> u;

            update(k, u - x[k]);
            x[k] = u;
        } else {
            int a = 0;
            int b = 0;
            cin >> a >> b;

            cout << sum(b) - sum(a - 1) << endl;
        }
    }

    return 0;
}