#include <cstdio>
#include <vector>
#define Y int
#define u e[i].U
#define C push_back
#define F(c,a,b) for(Y i=c;i!=a;i=b)
const Y N = 3e5;
struct V {
    Y x, y;
};
std::vector<V>Q[N];
std::vector<Y>W[N], R[N];
struct E {
    Y U, M;
} e[N * 2];
Y n, G, p[N], a[N], K[N * 2], o[N * 2], U[N];
Y fa[N], S[N], T[N], D[N], Z[N], B[N];
void A(Y x, Y y) {
    e[++G] = (E) {y, p[x]}, p[x] = G;
}
void I(Y s) {
    Y z = 0;
    Z[s] = 1;
    F(p[s], 0, e[i].M) {
        if (fa[s] == u)
            continue;

        fa[u] = s, D[u] = D[s] + 1, I(u), Z[s] += Z[u];

        if (Z[u] > z)
            z = Z[u], S[s] = u;
    }
}
void O(Y s) {
    T[s] = S[fa[s]] != s ? s : T[fa[s]];

    if (S[s])
        O(S[s]);

    F(p[s], 0, e[i].M)if (u != fa[s] && u != S[s])
        O(u);
}
Y L(Y x, Y y) {
    while (T[x] != T[y]) {
        if (D[T[x]] < D[T[y]])
            std::swap(x, y);

        x = fa[T[x]];
    }

    return D[x] < D[y] ? x : y;
}
void P(Y s) {
    Y y = n - D[s], l = K[D[s] + a[s]] + o[a[s] + y];

    F(p[s], 0, e[i].M) if (fa[s] != u)
        P(u);

    while (U[s])
        K[D[s]]++, U[s]--;

    F(R[s].size() - 1, -1, i - 1) o[R[s][i] + y]++;
    F(W[s].size() - 1, -1, i - 1)o[Q[s][i].y - D[Q[s][i].x] + n]--;
    B[s] += K[D[s] + a[s]] + o[a[s] + y] - l;
    F(W[s].size() - 1, -1, i - 1) K[D[W[s][i]]]--;
}
Y main() {
    Y m, x, y, z, s;
    scanf("%d%d", &n, &m);
    F(1, n, i + 1) scanf("%d%d", &x, &y), A(x, y), A(y, x);
    F(1, n + 1, i + 1) scanf("%d", &a[i]);
    I(1), O(1);

    while (m--) {
        scanf("%d%d", &x, &y), z = L(x, y), s = D[x] + D[y] - D[z] * 2;
        U[x]++, W[z].C(x), R[y].C(s);
        Q[z].C((V) {
            y, s
        });
    }

    P(1);
    F(1, n + 1, i + 1) printf("%d ", B[i]);
    return 0;
}