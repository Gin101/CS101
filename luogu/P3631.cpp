#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n = 0;
int m = 0;
int k = 0;
const int maxNM = 2e5 + 1;
const int maxK = 1e5 + 1;
const int MOD = 1e9;
int x[maxK] = {0};
int y[maxK] = {0};
int z[maxK] = {0};
int f[maxNM] = {0};
int g[maxNM] = {0};

int find(int x) {
    if (f[x] == x) {
        return x;
    }

    int tmp = find(f[x]);
    g[x] ^= g[f[x]];
    return f[x] = tmp;
}

long long power(long long x, long long y) {
    long long result = 1;
    while (y != 0) {
        if (y & 1) {
            result *= x;
            result %= MOD;
        }
        x *= x;
        x %= MOD;
        y /= 2;
    }

    return result;
}

int ope(int num) {
    for (int i = 1; i <= n + m; i++) {
        f[i] = i;
        g[i] = 0;
    }

    f[n + 1] = 1;
    if (num == 1) {
        for (int i = 1; i <= k; i++) {
            if (x[i] > 1 && y[i] > 1) {
                z[i] ^= 1;
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        if (::x[i] != 1 || ::y[i] != 1) {
            int fx = find(::x[i]);
            int fy = find(n + ::y[i]);
            int tmp = g[::x[i]] ^ g[n + ::y[i]] ^ ::z[i];
            if (fx != fy) {
                f[fy] = fx;
                g[fy] = tmp;
            } else if (tmp) {
                return 0;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n + m; i++) {
        if (i == find(i)) {
            result++;
        }
    }

    return power(2, result - 1);
}

int main()
{
	cin >> n >> m >> k;

    int num = -1;
    for (int i = 1; i <= k; i++) {
        cin >> x[i] >> y[i] >> z[i];
        if ((!(x[i] & 1)) && (!(y[i] & 1))) {
            z[i] ^= 1;
        }
        if (x[i] == 1 && y[i] == 1) {
            num = z[i];
        }
    }

    if (num != -1) {
        cout << ope(num) << endl;
    } else {
        cout << (ope(0) + ope(1)) % MOD << endl;
    }

	return 0;
}