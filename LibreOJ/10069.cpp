#include <iostream>
#include <algorithm>

using namespace std;

const int maxV = 5e4 + 1;
const int maxE = 1e5 + 1;
struct E {
    int s = 0;
    int t = 0;
    int c = 0;
    int col = 0;
} p[maxE];
int f[maxV] = {0};
int mid = 0;
bool cmp (E x, E y) {
    return -0.1 * x.col + x.c + x.col * mid < -0.1 * y.col + y.c + y.col * mid;
}

int find (int x) {
    if (f[x] == x) {
        return x;
    } 
    return f[x] = find(f[x]);
}

int main()
{
    int v = 0;
    int e = 0;
    int need = 0;
    cin >> v >> e >> need;

    need = v - 1 - need;

    for (int i = 1; i <= e; i++) {
        cin >> p[i].s >> p[i].t >> p[i].c >> p[i].col;
        p[i].s++;
        p[i].t++;
    }

    int l = -100;
    int r = 100;
    int result = 0;
    while (l <= r) {
        for (int i = 1; i <= v; i++) {
            f[i] = i;
        }

        mid = (l + r) / 2;
        sort(p + 1, p + e + 1, cmp);

        int cnt = 0;
        int tmp = 0;
        for (int i = 1; i <= e; i++) {
            if (find(p[i].s) != find(p[i].t)) {
                f[f[p[i].s]] = f[p[i].t];
                cnt += p[i].col;
                tmp += p[i].c;
            }
        }

        if (cnt >= need) {
            result = tmp + (cnt - need) * mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}