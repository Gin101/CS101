#include <iostream>
#include <stdio.h>

using namespace std;

int n = 0;
int m = 0;
const int maxN = 5e5 + 1;
struct Node {
    int u = 0;
    int v = 0;
    int w = 0;
    int idx = 0;
    int fu = 0;
    int fv = 0;
} e[maxN];

int f[maxN] = {0};
int num[maxN] = {0};

bool cmp(Node x, Node y) {
    return x.w < y.w;
}

bool cmp2(Node x, Node y) {
    return x.idx < y.idx;
}

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        e[i].idx = i;
    }

    sort(e + 1, e + m + 1, cmp);

    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }

    int l = 1;
    while (l <= m) {
        int r = l;
        do {
            e[r].fu = find(e[r].u);
            e[r].fv = find(e[r].v);
            r++;
        } while (r <= m && e[r].w == e[r - 1].w);

        while (l < r) {
            while (l < r && find(e[l].u) == find(e[l].v)) {
                l++;
            }
            if (l < r) {
                f[find(e[l].v)] = find(e[l].u);
            }
        }
        l = r;
    }

    sort(e + 1, e + m + 1, cmp2);
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }

    int q = 0;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int k = 0;
        scanf("%d", &k);
        
        bool flag = false;
        for (int j = 0; j < k; j++) {
            int tmp = 0;
            scanf("%d", &tmp);

            num[j] = tmp;
            if (find(e[tmp].fu) == find(e[tmp].fv)) {
                flag = true;
            }
            f[find(e[tmp].fu)] = find(e[tmp].fv);
        }

        for (int j = 0; j < k; j++) {
            f[e[num[j]].fu] = e[num[j]].fu;
            f[e[num[j]].fv] = e[num[j]].fv;
        }

        if (!flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
	
    return 0;
} 