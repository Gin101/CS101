#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int maxN = 3000;
vector<int> e[maxN];
map<pair<pair<int, int>, int>, bool> flag;
queue<pair<pair<int,int>,int> > q;
map<pair<int, int>, pair<int, int> > f;
map<pair<int, int>, bool> flag2;
void dfs(int x, int y) {
    if (x) {
        dfs(f[make_pair(x, y)].first, f[make_pair(x, y)].second);
    }

    cout << y << ' ';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    int m = 0;
    int k = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        e[x].push_back(y);
        e[y].push_back(x);
    }

    for (int i = 0; i < k; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        cin >> a >> b >> c;
        
        flag[make_pair(make_pair(a, b), c)] = true;
    }

    q.push(make_pair(make_pair(0, 1), 0));
    while (!q.empty()) {
        if (q.front().first.second == n) {
            cout << q.front().second << endl;
            dfs(q.front().first.first, q.front().first.second);
            cout << endl;
            return 0;
        }

        for (int i = 0; i < e[q.front().first.second].size(); i++) {
            if (!flag[make_pair(make_pair(q.front().first.first, q.front().first.second), e[q.front().first.second][i])] && !flag2[make_pair(q.front().first.second, e[q.front().first.second][i])]) {
                q.push(make_pair(make_pair(q.front().first.second, e[q.front().first.second][i]), q.front().second + 1));
                flag2[make_pair(q.front().first.second, e[q.front().first.second][i])] = true;
                f[make_pair(q.front().first.second, e[q.front().first.second][i])] = make_pair(q.front().first.first, q.front().first.second);
            }
        }

        q.pop();
    }
	
    cout << -1 << endl;

    return 0;
}