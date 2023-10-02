#include <iostream>
#include <queue>

using namespace std;

const int maxN = 1e5 + 1;
int n = 0;
int cnt = 0;
int result = 0;
int head[maxN] = {0};
int dp[maxN] = {0};
int ru[maxN] =  {0};
int ts[maxN] = {0};
struct Edge {
    int idx = 0;
    int next = 0;
} e[maxN << 2];
void add(int x, int y) {
    e[++cnt].next = head[x];
    e[cnt].idx = y;
    head[x] = cnt;
}

void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ru[i] == 0) {
            q.push(i);
            ts[++result] = i;
        }
    }

    while (!q.empty()) {
        for (int i = head[q.front()]; i; i = e[i].next) {
            ru[e[i].idx]--;
            if (ru[e[i].idx] == 0) {
                q.push(e[i].idx);
                ts[++result] = e[i].idx;
            }
        }
        q.pop();
    }
}
int main()
{
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        add(x, y);
        ru[y]++;
    }

	topsort();

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = head[ts[i]]; j; j = e[j].next) {
            dp[e[j].idx] = max(dp[e[j].idx], dp[ts[i]] + 1);
        }
    }

	for (int i = 1; i <= n; i++) {
        cout << dp[i] << endl;
    }

	return 0;
}