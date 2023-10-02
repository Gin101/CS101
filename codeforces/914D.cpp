#include <iostream>

using namespace std;

int n = 0;
const int maxN = 1 << 19;
int num[maxN * 2 | 1] = {0};

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

void update(int idx, int val) {
    num[idx += maxN] = val; 
    while (idx != 1) {
        idx /= 2;
        num[idx] = gcd(num[idx * 2], num[idx * 2 | 1]);
    }
}

int query(int idx, int val) {
    idx += maxN;
    while (idx != 1 && num[idx] % val == 0) {
        if (__builtin_popcount(idx + 1) == 1) {
            return n + 1;
        }
        idx = (idx + 1) / 2;
    }

    while (idx < maxN) {
        idx *= 2;
        idx += (num[idx] % val == 0);
    }
    return idx - maxN;
}
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a = 0;
        scanf("%d", &a);

        update(i, a);
    }

    int q = 0;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int op = 0;
        scanf("%d", &op);
        
        if (op == 1) {
            int l = 0;
            int r = 0;
            int x = 0;
            scanf("%d %d %d", &l, &r, &x);

            int tmp = query(l, x);
            if (tmp >= r || query(tmp + 1, x) > r) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            int I = 0;
            int y = 0;
            scanf("%d %d", &I, &y);

            update(I, y);
        }
    }

    return 0;
}