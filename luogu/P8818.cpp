#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

const int maxNM = 2e5 + 2;
int a[maxNM] = {0};
int b[maxNM] = {0};
int dnmax[maxNM] = {0};
int dnmin[maxNM] = {0};
int dmmax[maxNM] = {0};
int dmmin[maxNM] = {0};
pair<int, int> dzero[maxNM];

void buildN(int s, int t, int r) {
    if (s == t) {
        dnmax[r] = dnmin[r] = a[s];
        return;
    }

    int mid = (s + t) / 2;
    buildN(s, mid, r * 2);
    buildN(mid + 1, t, r * 2 + 1);

    dnmax[r] = max(dnmax[r * 2], dnmax[r * 2 + 1]);
    dnmin[r] = min(dnmin[r * 2], dnmin[r * 2 + 1]);
}
void buildM(int s, int t, int r) {
    if (s == t) {
        dmmax[r] = dmmin[r] = b[s];
        return;
    }

    int mid = (s + t) / 2;
    buildM(s, mid, r * 2);
    buildM(mid + 1, t, r * 2 + 1);

    dmmax[r] = max(dmmax[r * 2], dmmax[r * 2 + 1]);
    dmmin[r] = min(dmmin[r * 2], dmmin[r * 2 + 1]);
}
void buildZero(int s, int t, int r) {
    if (s == t) {
        if (a[s] >= 0) {
            dzero[r] = make_pair(a[s], INT_MIN);
        } else {
            dzero[r] = make_pair(INT_MAX, a[s]);
        }
        return;
    }

    int mid = (s + t) / 2;
    buildZero(s, mid, r * 2);
    buildZero(mid + 1, t, r * 2 + 1);

    dzero[r].first = min(dzero[r * 2].first, dzero[r * 2 + 1].first);
    dzero[r].second = max(dzero[r * 2].second, dzero[r * 2 + 1].second);
}

int findNmax(int l, int r, int s, int t, int now) {
    if (l <= s && t <= r) {
        return dnmax[now];
    }

    int mid = (s + t) / 2;
    int result = INT_MIN;
    if (l <= mid) {
        result = max(result, findNmax(l, r, s, mid, now * 2));
    }
    if (r > mid) {
        result = max(result, findNmax(l, r, mid + 1, t, now * 2 + 1));
    }
  
    return result;
}
int findNmin(int l, int r, int s, int t, int now) {
    if (l <= s && t <= r) {
        return dnmin[now];
    }

    int mid = (s + t) / 2;
    int result = INT_MAX;
    if (l <= mid) {
        result = min(result, findNmin(l, r, s, mid, now * 2));
    }
    if (r > mid) {
        result = min(result, findNmin(l, r, mid + 1, t, now * 2 + 1));
    }
  
    return result;
}
int findMmax(int l, int r, int s, int t, int now) {
    if (l <= s && t <= r) {
        return dmmax[now];
    }

    int mid = (s + t) / 2;
    int result = INT_MIN;
    if (l <= mid) {
        result = max(result, findMmax(l, r, s, mid, now * 2));
    }
    if (r > mid) {
        result = max(result, findMmax(l, r, mid + 1, t, now * 2 + 1));
    }
  
    return result;
}
int findMmin(int l, int r, int s, int t, int now) {
    if (l <= s && t <= r) {
        return dmmin[now];
    }

    int mid = (s + t) / 2;
    int result = INT_MAX;
    if (l <= mid) {
        result = min(result, findMmin(l, r, s, mid, now * 2));
    }
    if (r > mid) {
        result = min(result, findMmin(l, r, mid + 1, t, now * 2 + 1));
    }
  
    return result;
}
pair<int, int> findZero(int l, int r, int s, int t, int now) {
    if (l <= s && t <= r) {
        return dzero[now];
    }

    int mid = (s + t) / 2;
    pair<int, int> result;
    result.first = INT_MAX;
    result.second = INT_MIN;
    if (l <= mid) {
        pair<int, int> tmp = findZero(l, r, s, mid, now * 2);
        result.first = min(result.first, tmp.first);
        result.second = max(result.second, tmp.second);
    }
    if (r > mid) {
        pair<int, int> tmp = findZero(l, r, mid + 1, t, now * 2 + 1);
        result.first = min(result.first, tmp.first);
        result.second = max(result.second, tmp.second);
    }

    return result;
}


int main()
{
    int n = 0;
    int m = 0;
    int q = 0;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    buildN(1, n, 1);
    buildM(1, m, 1);
    buildZero(1, n, 1);

    for (int i = 0; i < q; i++) {
        int l1 = 0;
        int r1 = 0;
        int l2 = 0;
        int r2 = 0;
        cin >> l1 >> r1 >> l2 >> r2;

        int fnmin = findNmin(l1, r1, 1, n, 1);
        int fnmax = findNmax(l1, r1, 1, n, 1);
        int fmmin = findMmin(l2, r2, 1, m, 1);
        int fmmax = findMmax(l2, r2, 1, m, 1);
        pair<int, int> fzero = findZero(l1, r1, 1, n, 1);

        // cout << "fzero : " << fzero.first << ' ' << fzero.second << endl;
        if (fmmin >= 0) {
            cout << fmmin * fnmax << endl;
        } else if (fmmax <= 0) {
            cout << fmmax * fnmin << endl;
        } else {
            cout << max(fzero.first * fmmin, fzero.second * fmmax) << endl;
        }
    }   

    return 0;
}