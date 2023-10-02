#include <iostream>
#include <stdio.h>

using namespace std;

int s = 0;
const int maxS = 1024;
int tree[maxS][maxS] = {{0}};

void update(int l, int r, int num) {
    while (l <= s) {
        int tmp = r;
        while (tmp <= s) {
            tree[l][tmp] += num;
            tmp += tmp & -tmp;
        }
        l += l & -l;
    }
}

int query(int l, int r) {
    int result = 0;
    while (l > 0) {
        int tmp = r;
        while (tmp > 0) {
            result += tree[l][tmp];
            tmp -= tmp & -tmp;
        }
        l -= l & -l;
    }

    return result;
}

int main()
{
    int o = 0;
    cin >> o >> s;
    while (~scanf("%d", &o) && o != 3) {
        if (o == 1) {
            int x = 0;
            int y = 0;
            int a = 0;
            scanf("%d, %d, %d", &x, &y, &a);

            update(x, y, a);
        } else {
            int l = 0;
            int b = 0;
            int r = 0;
            int t = 0;
            scanf("%d %d %d %d", &l, &b, &r, &t);

            printf("%d\n", query(r, t) - query(l - 1, t) - query(r, b - 1) + query(l - 1, b - 1));
        }
    }

    return 0;
}