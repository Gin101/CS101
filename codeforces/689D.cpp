#include <iostream>
#include <cmath>

using namespace std;

const int maxN = 2e5 + 1;
int n = 0;
int a[maxN][25] = {{0}};
int b[maxN][25] = {{0}};

int query(int l, int r) {
    if (l == r) {
        return a[l][0];
    }

    int tmp = log2(r - l);
    return max(a[l][tmp], a[r - (1 << tmp) + 1][tmp]);
}

int query2(int l, int r) {
    if (l == r) {
        return b[l][0];
    }

    int tmp = log2(r - l);
    return min(b[l][tmp], b[r - (1 << tmp) + 1][tmp]);
}

int search(int l) {
    int _l = l;
    int _r = n;
    while (_l < _r) {
        int mid = (_l + _r) / 2;
        if (query(l, mid) >= query2(l, mid)) {
            _r = mid;
        } else {
            _l = mid + 1;
        }
    }
    if (query(l, _r) != query2(l, _r)) {
        return -1;
    }
 
    return _r;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i][0];
    }

    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (j + (1 << i) - 1 > n) {
                break;
            }
            a[j][i] = max(a[j][i - 1], a[j + (1 << (i - 1))][i - 1]);
            b[j][i] = min(b[j][i - 1], b[j + (1 << (i - 1))][i - 1]);
        }
    }

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        int x0 = search(i);
        if (x0 == -1) {
            continue;
        }

        if (query(i, n) == query2(i, n)) {
            result += n - x0 + 1;
            continue;
        }

        int _l = i;
        int _r = n;
        while (_l < _r) {
            int mid = (_l + _r) / 2;
            if (query(i, mid) <= query2(i, mid)) {
                _l = mid + 1;
            } else {
                _r = mid;
            }
        }

        result += _r - x0;
    }
    
    cout << result << endl;

    return 0;
}