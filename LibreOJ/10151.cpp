#include <iostream>

using namespace std;

#define int long long
int n = 0;
const int maxN = 1e6 + 1;
int t[maxN] = {0};
int t2[maxN] = {0};
int lowbit(int x) {
    return x & -x;
}
void add(int k, int v) {
    int tmp = k * v;
    while (k <= n) {
        t[k] += v;
        t2[k] += tmp;
        k += lowbit(k);
    }
}

int getsum(int t[], int k) {
    int result = 0;
    while (k) {
        result += t[k];
        k -= lowbit(k);
    }
    return result;
}
signed main()
{
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;

        add(i + 1, num);
        add(i + 2, -num);
    }

    for (int i = 0; i < m; i++) {
        int op = 0;
        cin >> op;

        int x = 0;
        int y = 0;
        if (op == 1) {
            int k = 0;
            cin >> x >> y >> k;

            add(x, k);
            add(y + 1, -k);
        } else {
            cin >> x >> y;

            cout << (y + 1) * getsum(t, y) - x * getsum(t, x - 1) - (getsum(t2, y) - getsum(t2, x - 1)) << endl;
        }   
    }

    return 0;
}