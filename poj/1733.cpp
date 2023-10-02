#include <iostream>
#include <string>

using namespace std;

const int maxM = 5000;
struct Query {
    int l = 0;
    int r = 0;
    bool flag = false;
} num[maxM];
int sum[maxM * 2] = {0};
int f[maxM * 2] = {0};
int deep[maxM * 2] = {0};

int find(int x) {
    if (x == f[x]) {
        return x;
    }
    deep[x] ^= deep[f[x]];

    return f[x] = find(f[x]);
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    int idx = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> num[i].l >> num[i].r >> s;

        if (s == "odd") {
            num[i].flag = true;
        }

        sum[idx++] = num[i].l - 1;
        sum[idx++] = num[i].r;
    }

    sort(sum, sum + idx);

    int idx2 = unique(sum, sum + idx) - sum - 1;
    for (int i = 0; i < idx2; i++) {
        f[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int idx3 = lower_bound(sum, sum + idx2, num[i].l - 1) - sum;
        int idx4 = lower_bound(sum, sum + idx2, num[i].r) - sum;
        int idx5 = find(idx3);
        int idx6 = find(idx4);
        if (idx5 == idx6 && (deep[idx3] ^ deep[idx4]) != num[i].flag)  {
            cout << i << endl;
            return 0;
        } else {
            f[idx5] = idx6;
            deep[idx5] = num[i].flag ^ deep[idx3] ^ deep[idx4];
        }
    }

    return 0;
}