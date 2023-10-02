#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int maxN = 5e4 + 1;
struct Query {
    int l = 0;
    int r = 0;
    Query *nxt;
    long long num = 0;
} query[maxN], *qhead[maxN];
const int maxK = 1 << 8;
const int MOD = 201314;
int n = 0;
int dfsclock = 0;
int head[maxN] = {0};
int _next[maxN] = {0};
int cnt[maxN][maxK] = {{0}};
int dfn[maxN] = {0};
int dfr[maxN] = {0};
long long result[maxK] = {0};
long long bit[maxN] = {0};
void dfscnt(int x) {
    cnt[x][x / maxK] = 1;
    dfn[x] = ++dfsclock;

    for (int i = head[x]; ~i; i = _next[i]) {
        dfscnt(i);
        for (int j = 0; j < n / maxK; j++) {
            cnt[x][j] += cnt[i][j];
        }
    }

    dfr[x] = dfsclock;
}
void inc(int x, int v) {
    for (int i = 0; i < n / maxK; i++) {
        result[i] += v * cnt[x][i];
    }

    for (int i = dfn[x]; i <= n; i += i & -i) {
        bit[i] += v;
    }
    for (int i = dfr[x] + 1; i <= n; i += i & -i) {
        bit[i] -= v;
    }
}
long long sum(int x) {
    long long total = 0;
    for (int i = dfn[x]; i; i &= i - 1) {
        total += bit[i];
    }

    return total;
}
void dfs(int x) {
    inc(x, 1);

    for (Query *i = qhead[x]; i; i = i -> nxt) {
        int l = i -> l;
        int r = i -> r + 1;
        if (l / maxK == r / maxK) {
            while (l < r) {
                i -> num += sum(l);
                l++;
            }
        } else {
            for (l; l % maxK; l++) {
                i -> num += sum(l);
            }
            for (r; r % maxK; i -> num += sum(r)) {
                r--;
            }
            for (l = l / maxK, r = r / maxK; l < r; l++) {
                i -> num += result[l];
            }
        }
    }

    for (int i = head[x]; ~i; i = _next[i]) {
        dfs(i);
    }
    inc(x, -1);
}
int main() 
{
    int q = 0;
    cin >> n >> q;

    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++) {
        int f = 0;
        cin >> f;

        _next[i] = head[f];
        head[f] = i;
    }

    for (int i = 0; i < q; i++) {
        int z = 0;
        cin >> query[i].l >> query[i].r >> z;

        query[i].nxt = qhead[z];
        qhead[z] = &query[i];
    }

    dfscnt(0);
    dfs(0);

    for (int i = 0; i < q; ++i) {
        cout << query[i].num % MOD << endl;
    }

    return 0;
}