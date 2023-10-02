#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e5 + 1;
long long tree[maxN] = {0};
int s = 0;
int e = 0;
int n = 0;
bool flag = false;
void init(int idx, long long val) {
    while (idx <= n) {
        tree[idx] += val;
        idx |= idx + 1;
    }
}

long long sum(int idx) {
    long long result = 0;
    while (idx >= 0) {
        result += tree[idx];
        idx = (idx & (idx + 1)) - 1;
    }

    return result;
}
long long query(int l, int r) {
    if (l > r) {
        swap(l, r);
    }
    return sum(r) - sum(l - 1);
}
int ope(int val) {
    if (!flag) {
        return s + val;
    }
    return e - val;
}
int main()
{
    int q = 0;
	cin >> n >> q;

    for (int i = 0; i < n; i++) {
        init(i, 1);
    }

    e = n - 1;
    for (int i = 0; i < q; i++) {
        int op = 0;
        cin >> op;
        if (op == 1) {
            int p = 0;
            cin >> p;
            if ((e - s + 1) / 2 < p) {
                p = e - s + 1 - p;
                flag ^= 1;
            }
            for (int j = 1; j <= p; j++) {
                init(ope(2 * p - j), query(ope(j - 1), ope(j - 1)));
            }
            if (!flag) {
                s += p;
            } else {
                e -= p;
            }
        } else {
            int l = 0;
            int r = 0;
            cin >> l >> r;
            cout << query(ope(l), ope(r - 1)) << endl;
        }
    }
	
	return 0;
}
