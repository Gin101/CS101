#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;
const int maxN = 5e5 + 1;
long long tree[maxN] = {0};
int Rank[maxN] = {0};
struct Point {
    long long val = 0;
    int idx = 0;
} a[maxN];

bool cmp(Point x, Point y) {
    return x.val == y.val ? x.idx < y.idx : x.val < y.val;
}

void update(int idx, long long num) {
    while (idx <= n) {
        tree[idx] += num;
        idx += idx & -idx;
    }
}

long long query(int idx) {
    int result = 0;
    while (idx > 0) {
        result += tree[idx];
        idx -= idx & -idx;
    }

    return result;
}
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].idx = i;
    }

    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        Rank[a[i].idx] = i;
    }

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        update(Rank[i], 1);
        result += i - query(Rank[i]);
    }

    cout << result << endl;

    return 0;
} 