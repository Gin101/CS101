#include <iostream>
#include <set>

using namespace std;

const int maxN = 5e5 + 1;
int a[maxN] = {0};

int main()
{
    int n = 0;
    int k = 0;
    int q = 0;
    cin >> n >> k >> q;
	int n, k, q;

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(0);
    }
    auto it = s.begin();
    for (int i = 0; i < k; i++) {
        it++;
    }

    int pos = k - 1;
    long long result = 0;
    for (int i = 0; i < q; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        y = -y;

        int old = a[--x];
        a[x] = y;

        s.insert(y);
        if (y < *it) {
            result += y;
            result -= *it;
            it--;
        }
        auto o = s.find(old);
        if (old <= *it) {
            result += *++it;
            result -= old;
        }

        s.erase(o);
        cout << -result << endl;
    }

	return 0;
}