#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxN = 1e5 + 1;

struct Bridge {
    int t = 0;
    int idx = 0;
    bool flag = false;
} p[maxN * 2];

bool cmp (Bridge x, Bridge y) {
    return x.t < y.t;
}

int num[maxN] = {0};
int cnt1[maxN] = {0};
int cnt2[maxN] = {0};
void ope(int n, int m, int cnt[]) {
    for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        p[i * 2].t = a;
        p[i * 2].idx = i;
        p[i * 2].flag = false;
        p[i * 2 + 1].t = b;
        p[i * 2 + 1].idx = i;
        p[i * 2 + 1].flag = true;
    }

    sort(p, p + 2 * m, cmp);
    int tmp = 0;
    int tmp2 = 0;
    priority_queue<int> q;
    for (int i = 0; i < 2 * m; i++) {
        if (!p[i].flag) {
            if (q.empty()) {
                tmp++;
                num[p[i].idx] = tmp;
            } else {
                tmp2 = -q.top();
                num[p[i].idx] = tmp2;
                q.pop();
            }
        } else {
            q.push(-num[p[i].idx]);
        }
    }
        
    for (int i = 0; i < m; i++) {
        cnt[num[i]]++;
    }

    for (int i = 1; i <= tmp; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = tmp + 1; i <= n; i++) {
        cnt[i] = m;
    }
}

int main() 
{
    int n = 0;
    int m1 = 0;
    int m2 = 0;
    cin >> n >> m1 >> m2;

    ope(n, m1, cnt1);
    ope(n, m2, cnt2);

    int result = 0;
    for (int i = 0; i <= n; i++) {
        result = max(result, cnt1[i] + cnt2[n - i]);
    }

    cout << result << endl;

    return 0;
}