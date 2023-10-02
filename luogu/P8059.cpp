#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 4e5 + 1;
int hand[maxN][2] = {{0}};
int result[maxN] = {0};
int l[maxN] = {0};
int r[maxN] = {0};
int f[maxN] = {0};
int head[maxN] = {0};
int tail[maxN] = {0};
int _next[maxN] = {0};
bool flag[maxN][2] = {{0}};

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}

void merge (int x, int y, int num) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
        return;
    }
    if (fx > fy) {
        swap(fx, fy);
    }
    if (fx == 1 && num != -1) {
        int idx = head[fy];
        while (idx) {
            result[idx] = num;
            idx = _next[idx];
        }
    }
	
    f[fy] = fx;
    _next[tail[fx]] = head[fy];
    tail[fx] = tail[fy];
} 

int main() 
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> hand[i][0] >> hand[i][1];
        result[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];

        flag[l[i]][r[i] - 1] = true;
    }

    for (int i = 1; i <= n; i++) {
        f[i] = i;
        head[i] = i;
        tail[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (!flag[i][0] && hand[i][0] != -1) {
            merge(i, hand[i][0], -1);
        }
        if (!flag[i][1] && hand[i][1] != -1) {
            merge(i, hand[i][1], -1);
        }
    }
	
    for (int i = m - 1; i >= 0; i--) {
        merge(l[i], hand[l[i]][r[i] - 1], i);
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << endl;
    }

	return 0;
} 