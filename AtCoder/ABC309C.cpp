#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 3e5;
struct Pill {
    int a = 0;
    int b = 0;
} p[maxN];

bool cmp(Pill x, Pill y) {
    return x.a > y.a;
}

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> p[i].a >> p[i].b;
    }

    sort(p, p + n, cmp);

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += p[i].b;
        if (tmp > k) {
            cout << p[i].a + 1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;

    return 0;
}