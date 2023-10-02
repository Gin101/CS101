#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int idx = 0;
const int maxN = 5e5 + 1;
const int maxM = 1e6 + 1;
const int maxK = 2e6 + 1;
int a[maxN] = {0};
int b[maxN] = {0};
int c[maxN] = {0};
bool flag[maxN] = {false};
int mem[maxK] = {0};
map<pair<int, int>, int> mp;
vector<int> v[maxN];

struct Node {
    int f = 0;
    int idx = 0;
} fa[maxM], num[maxK];

int find(int x) {
    if (fa[x].f == x) {
        return x;
    }
    return find(fa[x].f);
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fa[fx].idx > fa[fy].idx) {
        swap(fx, fy);
    }
    num[++idx] = fa[fx];
    mem[idx] = fx;
    num[++idx] = fa[fy];
    mem[idx] = fy;
    fa[fy].idx += fa[fx].idx;
    fa[fx].f = fy;
}

int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n * 2; i++) {
        fa[i].f = i;
        fa[i].idx = 1;
    }

    for (int i = 1; i <= m; i++) {
        if (c[a[i]] == c[b[i]]) {
            int fa = find(a[i]);
            int fb = find(b[i]);
            if (fa == fb) {
                flag[c[a[i]]] = true;
            } else {
                merge(a[i], b[i] + n);
                merge(b[i], a[i] + n);
            }
        }
    }
	
    int cnt = 0;
    for  (int i = 1; i <= m; i++) {
        if (c[a[i]] != c[b[i]] && !flag[c[a[i]]] && !flag[c[b[i]]]) {
            int tmpa = c[a[i]];
            int tmpb = c[b[i]];
            if (tmpa > tmpb) {
                swap(tmpa, tmpb);
            }

            int tmpm = mp[make_pair(tmpa, tmpb)];
            if (!tmpm) {
                tmpm = ++cnt;
                mp[make_pair(tmpa, tmpb)] = cnt;
            }

            v[tmpm].push_back(i);
        }
    }
	
    long long result = 0;
    int tmpt = 0;
    for (auto i : mp) {
        tmpt = idx;
        for (int j : v[i.second]) {
            if (find(a[j]) == find(b[j])) {
                result--;
                break;
            }
            merge(a[j], b[j] + n);
            merge(a[j] + n, b[j]);
        }
        while (tmpt != idx) {
            fa[mem[idx]] = num[idx];
            idx--;
        }
    }
	
    cnt = 0;
    for (int i = 1; i <= k; i++) {
        if (!flag[i]) {
            cnt++;
        }
    }

    cout << result + 1ll * cnt * (cnt - 1) / 2 << endl;

	return 0;
}