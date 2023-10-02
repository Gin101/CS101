#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define int long long

const int maxN = 1e4;
vector<int> e[maxN];
bool turn[maxN] = {false};
bool flag[maxN] = {false};
vector<int> under[maxN];
int num[maxN] = {0};
int pre[maxN] = {0};
bool vis[maxN] = {false};
bool vis2[maxN] = {false};
bool t[maxN] = {false};
long long result = 0;
long long zechen = 0;
bool zero = false;

int ope (long long num) {
    int cnt = 0;
    long long real = 0;
    while (num && cnt < 9) {
        long long power = 1;
        for (int i = 0; i < cnt; i++) {
            power *= 10;
        }

        real += num % 10 * power;
        num /= 10;
        cnt++;
    }

    return real;
}

void tu (int u, int stop) {
    turn[u] = true;
    if (u == stop) {
        return;
    }
    for (int i = 0; i < e[u].size(); i++) {
        if (!t[e[u][i]]) {
            t[e[u][i]] = true;
            tu(e[u][i], stop);
            t[e[u][i]] = false;
        }
    }
}

void check(int u) {
    for (int i = 0; i < e[u].size(); i++) {
        if (vis2[e[u][i]]) {
            continue;
        }
        if (flag[e[u][i]]) {
            tu(u, u);
        } else {
            flag[e[u][i]] = true;
            check(e[u][i]);
            flag[e[u][i]] = false;
        }
    }
    vis2[u] = true;
}

void Re (int u) {
    pre[u] = result;

    if (!turn[1] && turn[u]) {
        cout << "inf" << endl;
        exit(0);
    }

    for (int i = 0; i < under[u].size(); i++) {
        if (!flag[under[u][i]]) {
            if (vis[under[u][i]]) {
                result += num[under[u][i]];
                zechen += num[under[u][i]];
                result = ope(result);
                continue;
            }
            flag[under[u][i]] = true;
            Re(under[u][i]);
            flag[under[u][i]] = false;
        }
    }

    if (zechen >= 1e9) {
        zero = true;
    }

    vis[u] = true;  
    num[u] = result - pre[u];
}
 
signed main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        e[a - 1].push_back(b - 1);
        under[b - 1].push_back(a - 1);
    }

    vis2[0] = true;
    check(0);
    memset(flag, false, sizeof(flag));
    vis[0] = true;
    num[0] = 1;
    Re(1);

    long long total = ope(result);
    if (zero && total < 1e8) {
        for (int i = 1; i < 1e9 / total; i *= 10) {
            cout << '0';
        }
    }

    cout << total << endl;

    return 0;
}