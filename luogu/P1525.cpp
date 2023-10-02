#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e4;
const int maxM = 1e5;
struct Relation {
    int a = 0;
    int b = 0;
    int c = 0;
} r[maxM];
int f[maxN] = {0};
int tmp[maxN] = {0};

bool cmp(Relation x, Relation y) {
    return x.c > y.c;
}

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
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> r[i].a >> r[i].b >> r[i].c;
    }

    sort(r, r + m, cmp);

    for (int i = 0; i < n; i++) {
        f[i] = i;
    }
    for (int i = 0; i < m; i++) {
        if (find(r[i].a) == find(r[i].b)) {
            cout << r[i].c << endl;
            return 0;
        } else {
            if (!tmp[r[i].a]) {
                tmp[r[i].a] = r[i].b;
            } else {
                f[find(tmp[r[i].a])] = find(r[i].b);
            }
            if (!tmp[r[i].b]) {
                tmp[r[i].b] = r[i].a;
            } else {
                f[find(tmp[r[i].b])] = find(r[i].a);
            }
        }
    }

    cout << 0 << endl;

    return 0;
}