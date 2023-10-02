#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<int, set<int> > r;
map<int, set<int> > c;
set<int> :: iterator it;

int main()
{
    int h = 0;
    int w = 0;
    int x = 0;
    int y = 0;
    int n = 0;
    cin >> h >> w >> x >> y >> n;

    for (int i = 1; i <= n; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        r[a].insert(b);
        c[b].insert(a);
    }

    int q = 0;
    cin >> q;

    for (int i = 1; i <= q; i++) {
        char op;
        int t = 0;
        cin >> op >> t;

        if (op == 'L') {
            r[x].insert(0);
            r[x].insert(w + 1);
            y = max(y - t, (*(--r[x].upper_bound(y))) + 1);
        } else if (op == 'R') {
            r[x].insert(0);
            r[x].insert(w + 1);
            y = min(y + t, (*(r[x].upper_bound(y))) - 1);
        } else if (op == 'U') {
            c[y].insert(0);
            c[y].insert(h + 1);
            x = max(x - t, (*(--c[y].upper_bound(x))) + 1);
        } else {
            c[y].insert(0);
            c[y].insert(h + 1);
            x = min(x + t, (*(c[y].upper_bound(x))) - 1);
        }
        cout << x << ' ' << y << endl;
    }
	
	return 0;
}q