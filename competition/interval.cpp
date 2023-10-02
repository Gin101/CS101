#include <iostream>
#include <map>

using namespace std;

const int maxN = 1e5;
struct Interval {
    int b = 0;
    int e = 0;
} in[maxN];

bool cmp(Interval x, Interval y) {
    return x.b == y.b ? x.e < y.e : x.b < y.b;
}
map<int, bool> mp;

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> in[i].b >> in[i].e;
    }

    sort(in, in + n, cmp);

    int result = 0;
    int cnt = 0;
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (cnt != 0) {
            if (in[i].b <= r) {
                r = max(r, in[i].e);
                if (!mp.count(in[i].b)) {
                    mp[in[i].b] = true;
                    cnt++;
                }
                if (!mp.count(in[i].e)) {
                    mp[in[i].e] = true;
                    cnt++;
                }
            } else {
                result += cnt - 1;
                cnt = 0;
            }
        } 
        if (cnt == 0) {
            l = in[i].b;
            mp[l] = true;
            cnt++;
            r = in[i].e;
            if (!mp.count(r)) {
                mp[r] = true;
                cnt++;
            }
        }
    }

    cout << result + max(0, cnt - 1) << endl;

    return 0;
}