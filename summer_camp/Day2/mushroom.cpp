#include <iostream>
#include <algorithm>
#include <map>
#include <limits.h>

using namespace std;

const int maxN = 1000;
int l[maxN] = {0};
int c[maxN] = {0};
map<int, int> mp;
int main()
{
    freopen("mushroom.in", "r", stdin);
    freopen("mushroom.out", "w", stdout);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    mp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto item : mp) {
            int tmp = __gcd(item.first, l[i]);
            if (!mp.count(tmp)) {
                mp[tmp] = INT_MAX;
            }
            mp[tmp] = min(mp[tmp], item.second + c[i]);
        }
    }

    if (!mp.count(1)) {
        cout << "Imposible" << endl;
    } else {
        cout << mp[1] << endl;
    }

    return 0;
}