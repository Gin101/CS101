#include <iostream>

using namespace std;

int n = 0;
int q = 0;
const int maxN = 1e5 + 1;
const int MOD = 1e9 + 7;
long long x[maxN] = {0};
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
} tree[maxN * 4], f[maxN * 4], tmp, tmp2, now;

Matrix ope(int num) {
    Matrix result = tmp2;
    Matrix tmp3 = now;
    while (num) {
        if (num & 1) {
            result = result * tmp3;
        }
        tmp3 = tmp3 * tmp3;

        num /= 2;
    }

    return result;
}

void up(int idx) {
    for (int i = 0; i < 2; i++) {
        f[idx].num[0][i] = (f[idx * 2].num[0][i] + f[idx * 2 | 1].num[0][i]) % MOD;
    }
}

void build(int idx, int l, int r) {
    tree[idx] = tmp2;
    if (l == r) {
        f[idx] = tmp * ope(x[l]);
        return;
    }

    build(idx * 2, l, (l + r) / 2);
    build(idx * 2 | 1, (l + r) / 2 + 1, r);
    up(idx);
}

void add(int idx, Matrix x) {
    f[idx] = f[idx] * x;
    tree[idx] = tree[idx] * x;
}

void init(int idx) {
    add(idx * 2, tree[idx]);
    add(idx * 2 | 1, tree[idx]);
    tree[idx] = tmp2;
}

void update(int idx, int l, int r, int a, int b, Matrix x) {
    if (b < l || r < a) {
        return;
    }
    if (a <= l && r <= b) {
        add(idx, x);
        return;
    }
    init(idx);

    update(idx * 2, l, (l + r) / 2, a, b, x);
    update(idx * 2 | 1, (l + r) / 2 + 1, r, a, b, x);
    up(idx);
}

int query(int idx, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
        return f[idx].num[0][0];
    }
    init(idx);

    if (b <= (l + r) / 2) {
        return query(idx * 2, l, (l + r) / 2, a, b);
    }
    if (a > (l + r) / 2) {
        return query(idx * 2 | 1, (l + r) / 2 + 1, r, a, b);
    }
    return (query(idx * 2, l, (l + r) / 2, a, b) + query(idx * 2 | 1, (l + r) / 2 + 1, r, a, b)) % MOD;
}
int main()
{
    cin >> n >> q;

    tmp.num[0][1] = 1;
    tmp2.num[0][0] = 1;
    tmp2.num[1][1] = 1;
    now.num[0][0] = 1;
    now.num[1][0] = 1;
    now.num[0][1] = 1;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    build(1, 1, n);
    for (int i = 0; i < q; i++) {
        int o = 0;
        int l = 0;
        int r = 0;
        cin >> o >> l >> r;

        if (o == 1) {
            int x = 0;
            cin >> x;

            update(1, 1, n, l, r, ope(x));
        } else {
            cout << query(1, 1, n, l, r) << endl;
        }
    }

	return 0;
}
/*
qq c;memset(c.a,0,sizeof(c.a));
	for(int k=0;k<2;k++)for(int i=0;i<2;i++)for(int j=0;j<2;j++)
		(c.a[i][j]+=1ll*a.a[i][k]*b.a[k][j]%mod)%=mod;
	return c;
*/