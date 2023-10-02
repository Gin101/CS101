#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;


int k = 0;
const int maxN = 1e5 + 1;
const int maxK = 51;
int a[maxN][maxK] = {{0}};
bool flag[maxN][maxK] = {{false}};
int px[maxN * maxK] = {0};
int py[maxN * maxK] = {0};
int qx[maxN * maxK] = {0};
int qy[maxN * maxK] = {0};
int pc = 0;
int qc = 0;
int c[maxN][maxK] = {{0}};
int cc = 0;
int cv[maxN * maxK] = {0};
int vv[maxN] = {0};
int d[maxN * maxK] = {0};
vector<int> e[maxN];
vector<int> re[maxN];
void f(int x, int y) {
    flag[x][y] = true;
    for (int i : e[x]) {
        if (!flag[i][(y + 1) % k]) {
            f(i, (y + 1) % k);
        }
    }
    //px[++pc] = x;
    py[pc] = y;
}

void g(int x, int y) {
    c[x][y] = cc;
    if (a[x][y] && vv[x] != cc) {
        vv[x] = cc;
        cv[cc]++;
    }
    qx[++qc] = x;
    qy[qc] = y;

    for (int i : re[x]) {
        if (!c[i][(y + k - 1) % k]) {
            g(i, (y + k - 1) % k);
        }
    }
}

int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        e[x].push_back(y);
        re[y].push_back(x);
    }
	
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%1d", a[i] + j);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (!flag[i][j]) {
                f(i, j);
            }
        }
    }

    for (int i = n * k; i >= 1; i--) {
        if (!c[px[i]][py[i]]) {
            cc++;
            g(px[i], py[i]);
        }
    }
    for (int i = n * k; i >= 1; i--) {
        int x = qx[i];
        int y = qy[i];
        int z = c[x][y];
        int tmp = 0;
        for (int j : e[x]) {
            if (c[j][(y + 1) % k] > z) {
                tmp = max(tmp, d[c[j][(y + 1) % k]]);
            }
        }
        d[z] = max(d[z], tmp + cv[z]);
    }
	
    cout << d[c[1][0]] << endl;

    return 0;
}