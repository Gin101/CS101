#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e5;
struct House {
    int h = 0;
    int c = 0;
} p[maxN];

bool cmp(House x, House y) {
    if (x.h != y.h) {
        return x.h < y.h;
    }
    return x.c < y.c;
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].h >> p[i].c;
    }

    sort(p, p + n, cmp);

    cout << 0 << endl;

    return 0;
}