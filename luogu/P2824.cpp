#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int maxN = 1e5 + 1;
int n = 0;
int m = 0;
int k = 0;
int a[maxN] = {0};
struct Query {
    int l = 0;
    int r = 0;
    int k = 0;
} q[maxN];

struct Node {
    int l = 0;
    int r = 0;
    int v = 0;
    Node(int l, int r = -1, int v = 0) : l(l), r(r), v(v) {}
    Node() {}
    bool operator < (const Node& t) const {
        return l < t.l;
    }
};

set<Node> s;
set<Node> :: iterator spli(int pos) {
    auto it = s.lower_bound(Node(pos));
    if (it != s.end() && it -> l == pos) {
        return it;
    }
    it--;
    int l = it -> l;
    int r = it -> r;
    int v = it -> v;

    s.erase(it);
    s.insert(Node(l, pos - 1, v));

    return s.insert(Node(pos, r, v)).first;
}

int countone(int l, int r) {
    auto itr = spli(r + 1);
    auto itl = spli(l);
    
    int result = 0;
    while (itl != itr) {
        if (itl -> v == 1) {
            result += itl -> r - itl -> l + 1;
        }
        itl++;
    }

    return result;
}

void change(int l, int r, int v) {
    auto itr = spli(r + 1);
    auto itl = spli(l);

    s.erase(itl, itr);
    s.insert(Node(l, r, v));
}

bool check(int x) {
    s.clear();
    for (int i = 1; i <= n; i++) {
        s.insert(Node(i, i, a[i] >= x));
    }
    s.insert(Node(n + 1, n + 1, -1));

    for (int i = 1; i <= m; i++) {
        int l = q[i].l;
        int r = q[i].r;
        int numone = countone(l, r);

        if (!q[i].k) {
            change(r - numone + 1, r, 1);
            change(l, r - numone, 0);
        } else {
            change(l, l + numone - 1, 1);
            change(l + numone, r, 0);
        }
    }

    return spli(k) -> v == 1;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i].k >> q[i].l >> q[i].r;
    }

    cin >> k;

    int l = 1;
    int r = n;
    int result = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            result = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}