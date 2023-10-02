#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 2e5;
vector<pair<int, int> > e[maxN];

int n = 0;
int dis[maxN] = {0};
bool flag[maxN] = {false};
int cnt[maxN] = {0};
queue<int> q;

bool spfa() {
    for (int i = 0; i < n; i++) {
        flag[i] = true;
        dis[i] = 1;
        q.push(i);
    }

    while (!q.empty()) {
        flag[q.front()] = false;
        for (int i = 0; i < e[q.front()].size(); i++) {
            if (dis[e[q.front()][i].first] < dis[q.front()] + e[q.front()][i].second) {
                dis[e[q.front()][i].first] = dis[q.front()] + e[q.front()][i].second;
                if (++cnt[e[q.front()][i].first] == n) {
                    return false;
                }

                if (!flag[e[q.front()][i].first]) {
                    flag[e[q.front()][i].first] = true;
                    q.push(e[q.front()][i].first);
                }
            }
        }

        q.pop();
    }

    return true;
}

int main() 
{
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x = 0;
        int a = 0;
        int b = 0;
        cin >> x >> a >> b;

        if (a == b && !(x & 1)) {
            cout << -1 << endl;
            return 0;
        }
        if (x == 1) {
            e[a - 1].push_back(make_pair(b - 1, 0));
            e[b - 1].push_back(make_pair(a - 1, 0));
        } else if (x == 2) {
            e[a - 1].push_back(make_pair(b - 1, 1));
        } else if (x == 3) {
            e[b - 1].push_back(make_pair(a - 1, 0));
        } else if (x == 4) {
            e[b - 1].push_back(make_pair(a - 1, 1));
        } else {
            e[a - 1].push_back(make_pair(b - 1, 0));
        }
    }

    if (!spfa()) {
        cout << -1 << endl;
        return 0;
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += dis[i];
    }

    cout << result << endl; 
    
    return 0;
}