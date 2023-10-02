#include <iostream>
#include <vector>

using namespace std;

const int maxN = 2e5;
vector<pair<int, int> > e[maxN][2];
bool flag[maxN][2] = {{false}};
int x = 0;
int y = 0;
bool cycle = false;
void dfs(pair<int, int> u, pair<int, int> pre) {
    if (!flag[u.first][u.second]) {
        flag[u.first][u.second] = true;
    } else {
        x++;
        cycle = true;
        return;
    }
    for (int i = 0; i < e[u.first][u.second].size(); i++) {
        if (e[u.first][u.second][i] != pre) {
            dfs(e[u.first][u.second][i], u);
        }
    }

    if (!cycle && e[u.first][u.second].size() == 1) {
        y++;
    }
    return;
}

int main()
{   
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        e[i][0].push_back(make_pair(i, 1));
        e[i][1].push_back(make_pair(i, 0));
    }

    for (int i = 0; i < m; i++) {
        int a = 0;
        char b;
        int c = 0;
        char d;
        cin >> a >> b >> c >> d;

        if (a == c) {
            x += 2;
            y -= 2;
            continue;
        }

        if (b == 'R') {
            if (d == 'R') {
                e[a - 1][0].push_back(make_pair(c - 1, 0));
                e[c - 1][0].push_back(make_pair(a - 1, 0));
            } else {
                e[a - 1][0].push_back(make_pair(c - 1, 1));
                e[c - 1][1].push_back(make_pair(a - 1, 0));
            }
        } else {
            if (d == 'R') {
                e[a - 1][1].push_back(make_pair(c - 1, 0));
                e[c - 1][0].push_back(make_pair(a - 1, 1));
            } else {
                e[a - 1][1].push_back(make_pair(c - 1, 1));
                e[c - 1][1].push_back(make_pair(a - 1, 1));
            }
        }
    }   

    for (int i = 0; i < n; i++) {
        if (!flag[i][0]) {
            cycle = false;
            dfs(make_pair(i, 0), make_pair(0, 0));
        }
    }

    cout << x / 2 << ' ' << y / 2 << endl;

    return 0;
}