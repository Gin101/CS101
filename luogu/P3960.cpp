#include <iostream>
#include <vector>

using namespace std;

const int maxS = 6e5 + 2;
const int maxN = 3e5 + 1;
int n = 0;
int m = 0;
int q = 0;
int s[maxS] = {0};
int l[maxS] = {0};
int r[maxS] = {0};
int a[maxN] = {0};
vector<long long> e[maxS];
long long d[maxS] = {0};
long long result = 0;
int cnt = 0;
int ope(int &now, int k, int x, int y) {
    if (!now) {
        now = ++cnt;
        s[now] = y - x + 1;
    }
    s[now]--;

    if (x == y) {
        return x;
    }

    int tmp = l[now] ? s[l[now]] : x + y >> 1 - x + 1;
    if (tmp >= k) {
        return ope(l[now], k, x, x + y >> 1);
    } else {
        return ope(r[now], k - tmp, x + y >> 1 + 1, y);
    }
}
int main() 
{
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        d[i] = 1ll * i * m;
    }

    int tmpn = n + q;
    int tmpm = m + q;
    for (int i = 0; i < q; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        d[n] = (y == m) ? d[result = ope(a[0], x, 1, tmpn)] : (e[x].push_back(d[ope(a[0], x, 1, tmpn)]), 
        (result = ope(a[x], y, 1, tmpm) < m) ? (x - 1ll) * m + result : e[x][result - m]);

        cout << d[n] << endl;
        n++;
    }

    return 0;
}