#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1001;
int tree[2][2][maxN][maxN] = {{{{0}}}};
int n = 0;
int w = 0;
void update(int x, int y) {
    int idx = x;
    while (idx <= n) {
        int idx2 = y;
        while (idx2 <= n) {
            tree[x & 1][y & 1][idx][idx2] ^= w;
            idx2 += idx2 & -idx2;
        }
        idx += idx & -idx;
    }
}

int result = 0;
void query(int x, int y) {
    int idx = x;
    while (idx != 0) {
        int idx2 = y;
        while (idx2 != 0) {
            result ^= tree[x & 1][y & 1][idx][idx2];
            idx2 -= idx2 & -idx2;
        }
        idx -= idx & -idx;
    }
}

int main()
{
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int o = 0;
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        scanf("%d %d %d %d %d", &o, &x1, &y1, &x2, &y2);
        if (o == 1) {
            result = 0;
            query(x2, y2);
            query(--x1, y2);
            query(x2, --y1);
            query(x1, y1);
            printf("%d\n", result);
        } else {
            scanf("%d", &w);
            update(x1, y1);
            update(x1, ++y2);
            update(++x2, y1);
            update(x2, y2);
        }
    }

    return 0;
}