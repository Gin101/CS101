#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n = 0;
int top = 0;
const int maxN = 1e5 + 1;
int deg[maxN] = {0};
int id[maxN] = {0};
long long a[maxN] = {0};
long long b[maxN] = {0};
vector<int> e[maxN];

queue<int> q;
void gtps(void) {
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        id[++top] = u;

        for (int i = 0; i < e[u].size(); ++i) {
            int v = e[u][i];
            long long ta = a[u];
            long long tb = b[u] * e[u].size();
            a[v] = a[v] * tb + ta * b[v];
            b[v] *= tb;

            long long d = __gcd(a[v], b[v]);
            b[v] /= d;
            a[v] /= d;
            --deg[v];

            if (!deg[v]) {
                q.push(v);
            }
        }
    }
}

int main() 
{
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        b[i] = 1;
        int d = 0;
        cin >> d;

        for (int j = 1; j <= d; j++) {
            int x = 0;
            cin >> x;

            deg[x]++;
            e[i].push_back(x);
        }
    }

    for (int i = 1; i <= m; i++) {
        a[i] = 1;
    }

    gtps();

    for (int i = 1; i <= n; i++) {
        if (!e[i].size()) {
            cout << a[i] << ' ' << b[i] << endl;
        }
    }

    return 0;
}