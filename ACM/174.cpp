#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxM = 800001;
int f[maxM] = {0};
vector<pair<int, int> >v;
vector<pair<int, int> >num;

int find(int x) {
    if (x == f[x]) {
        return x;
    } else {
        return f[x] = find(f[x]);
    }
}

int main()
{
    int m = 0;
    cin >> m;

    v.assign(2 * m, make_pair(0, 0));
    for (int i = 0; i < 2 * m; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);
        num.push_back(v[i]);
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int i = 0; i < maxM; i++) {
        f[i] = i;
    }

    int result = 0;
    for (int i = 0; i < m; i++) {
        int tmp = lower_bound(num.begin(), num.end(), v[2 * i]) - num.begin();
        int tmp2 = lower_bound(num.begin(), num.end(), v[2 * i + 1]) - num.begin();
        if (find(tmp) == find(tmp2)) {
            result = i + 1;
            break;
        } else {
            f[find(tmp)] = find(tmp2);
        }
    }

    cout << result << endl;

    return 0;
}