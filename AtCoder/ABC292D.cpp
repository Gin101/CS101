#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 2e5;
bool flag[maxN] = {false};
vector<int> e[maxN];

struct Node {
    int idx = 0;
    int tag = -1;
} node[maxN];

void find(int u, int cnt) {
    if (flag[u]) {
        return;
    }

    node[u].tag = cnt;
    flag[u] = true;
    for (int i = 0; i < e[u].size(); i++) {
        find(e[u][i], cnt);
    }
}

bool cmp(Node x, Node y) {
    return x.tag < y.tag;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        e[u - 1].push_back(v - 1);
        e[v - 1].push_back(u - 1);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        node[i].idx = i;
        if (!flag[i]) {
            find(i, cnt++);
        }
    }

    sort(node, node + n, cmp);

    // for (int i = 0; i < n; i++) {
    //     cout << node[i].idx << ' ' << node[i].tag << endl;
    // }

    // cout << "------------" << endl;

    int tmp = e[node[0].idx].size();
    int pre = 0;
    for (int i = 1; i < n; i++) {
        if (node[i - 1].tag != node[i].tag) {
            if ((i - pre) != tmp / 2) {
                cout << "No" << endl;
                return 0;
            } else {
                pre = i;
            }
        } else {
            tmp += e[node[i].idx].size();
        }
    }

    if ((n - pre) != tmp / 2) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}