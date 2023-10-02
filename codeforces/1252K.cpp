#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxN = 1e5 + 1;
const int MOD = 1e9 + 7;
string s;
long long pre[maxN * 4] = {0};
struct Matrix {
    long long num[2][2] = {{0}};
    friend Matrix operator*(Matrix x, Matrix y) {
        Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    result.num[i][j] = (result.num[i][j] + x.num[i][k] * y.num[k][j] % MOD) % MOD;
                }
            }
        }

        return result;
    }
} tree[maxN * 4][2], ma, mb;

void build(int idx, int l, int r) {
    if (l == r) {
        if (s[l - 1] == 'A') {
            tree[idx][0] = ma;
            tree[idx][1] = mb;
        } else {
            tree[idx][0] = mb;
            tree[idx][1] = ma;
        }
        return;
    }

    build(idx * 2, l, (l + r) / 2);
    build(idx * 2 | 1, (l + r) / 2 + 1, r);
    tree[idx][0] = tree[idx * 2][0] * tree[idx * 2 | 1][0];
    tree[idx][1] = tree[idx * 2][1] * tree[idx * 2 | 1][1];
}

void Reverse(int idx) {
    swap(tree[idx][0], tree[idx][1]);
    pre[idx] ^= 1;
}

void Flip(int idx) {
    if (pre[idx]) {
        Reverse(idx * 2);
        Reverse(idx * 2 | 1);
        pre[idx] ^= 1;
    }
}

void update(int idx, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
        Reverse(idx);
        return;
    }
    Flip(idx);

    if (a <= (l + r) / 2) {
        update(idx * 2, l, (l + r) / 2, a, b);
    }
    if (b > (l + r) / 2) {
        update(idx * 2 | 1, (l + r) / 2 + 1, r, a, b);
    }
    tree[idx][0] = tree[idx * 2][0] * tree[idx * 2 | 1][0];
    tree[idx][1] = tree[idx * 2][1] * tree[idx * 2 | 1][1];
}

Matrix query(int idx, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
        return tree[idx][0];
    }
    Flip(idx);

    Matrix result;
    result.num[0][0] = 1;
    result.num[1][1] = 1;
    if (a <= (l + r) / 2) {
        result = result * query(idx * 2, l, (l + r) / 2, a, b);
    }
    if (b > (l + r) / 2) {
        result = result * query(idx * 2 | 1, (l + r) / 2 + 1, r, a, b);
    }

    return result;
}

int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q >> s;

    ma.num[0][0] = 1;
    ma.num[1][0] = 1;
    ma.num[1][1] = 1;
    mb.num[0][0] = 1;
    mb.num[0][1] = 1;
    mb.num[1][1] = 1;
    build(1, 1, n);
    for (int i = 0; i < q; i++) {
        int o = 0;
        cin >> o;
        if (o == 1) {
            int l = 0;
            int r = 0;
            cin >> l >> r;

            update(1, 1, n, l, r);
        } else {
            int l = 0;
            int r = 0;
            long long a = 0;
            long long b = 0;
            cin >> l >> r >> a >> b;

            Matrix tmp = query(1, 1, n, l, r);
            cout << (tmp.num[0][0] * a % MOD + tmp.num[1][0] * b % MOD) % MOD << ' ' << (tmp.num[0][1] * a % MOD + tmp.num[1][1] * b % MOD) % MOD << endl;
        }
    }

    return 0;
}