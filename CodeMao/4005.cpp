#include <iostream>

using namespace std;

const int maxN = 20001;
int f[maxN] = {0};

int find(int x) {
    while (f[x] != x) {
        x = f[x];
    }
    return x;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        f[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        int a2 = find(a);
        int b2 = find(b);

        if (a2 != b2) {
            f[b2] = a2;
        }
    }

    int q = 0;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int c = 0;
        int d = 0;
        cin >> c >> d;

        if (find(c) == find(d)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}