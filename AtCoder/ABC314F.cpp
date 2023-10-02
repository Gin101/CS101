#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int maxN = 5e5 + 2;
int p[maxN] = {0};
int idx[maxN] = {0};
int l[maxN] = {0};
int r[maxN] = {0};
set<int> s;
int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        idx[p[i]] = i;
    }

    s.insert(n + 1);
    idx[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
        s.insert(p[i]);
        if (i > k) {
            s.erase(p[i - k]);
        }
        r[l[idx[*s.upper_bound(p[i])]]] = i;
        l[i] = l[idx[*s.upper_bound(p[i])]];
        l[idx[*s.upper_bound(p[i])]] = i;
        r[i] = idx[*s.upper_bound(p[i])];
    }

    int idx2 = l[n + 1];
    int tmp = n;
    while (idx2) {
        p[idx2] = tmp;
        idx2 = l[idx2];
        tmp--;
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i] << endl;
    }

    return 0;
}