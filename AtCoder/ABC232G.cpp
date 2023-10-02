#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxN = 4e5 + 1;
const int INF = 0x3f3f3f3f;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
vector<pair<int, int> > e[maxN];
int v[maxN] = {0};
int l[maxN] = {0}; 
int d[maxN] = {0};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] = (m - v[i]) % m;
        l[i] = i;
        l[i + n] = i + n;
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        cin >> v[i];
        e[i].push_back({0, i - n});
    }

    n *= 2;
    stable_sort(l + 1, l + 1 + n, [](int i, int j) { return v[i] < v[j]; });
    for (int i = 1; i <= n; i++) {
        e[l[i]].push_back({(v[l[i % n + 1]] + m - v[l[i]]) % m, l[i % n + 1]});
    }

    fill(d + 1, d + 1 + n, INF);
    q.push({0, 1});
    while (!q.empty()) {
        pair<int, int> tmp = q.top();
        q.pop();
        if (tmp.first < d[tmp.second]) {
            d[tmp.second] = tmp.first;
        }

        for (pair<int, int> i : e[tmp.second]) {
            q.push({tmp.first + i.first, i.second});
        }
    }

    cout << d[n] << endl;

    return 0;
}