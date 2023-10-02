#include <iostream>
#include <set>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxN = 2e5 + 1;
int a[maxN] = {0};
long long result[maxN] = {0};
multiset<int> ms;
int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        ms.clear();
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
            ms.insert(a[j]);
        }

        int cnt = 0;
        long long num = 0;
        while (true) {
            cnt++;
            auto it = ms.lower_bound(cnt);
            if (it == ms.end()) {
                cnt--;
                break;
            }
            num += *it;
            ms.erase(it);
        }

        for (int j = n; j >= 0; j--) {
            result[j] = num - (long long)cnt * (cnt + 1) / 2;
            auto it = ms.lower_bound(a[j]);
            num -= a[j];

            if (it == ms.end()) {
                cnt--;
            } else {
                num += (*it);
                ms.erase(it);
            }
        }

        for (int j = 1; j <= n; j++) {
            printf("%lld ", result[j]);
        }
        cout << endl;
    }

    return 0;
}