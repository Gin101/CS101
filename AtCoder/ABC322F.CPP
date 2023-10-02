#include <iostream>
#include <atcoder/all>

using namespace std;

array<int, 7> op(array<int, 7> a, array<int, 7> b){
    array<int, 7> c{};
    c[0] = a[0] == a[4] ? a[0] + b[0] : a[0];
    c[1] = b[1] == b[4] ? a[1] + b[1] : b[1];
    c[2] = a[2] == a[4] ? a[2] + b[2] : a[2];
    c[3] = b[3] == b[4] ? a[3] + b[3] : b[3];
    c[4] = a[4] + b[4];
    c[5] = max(max(a[5], b[5]), a[1] + b[0]);
    c[6] = max(max(a[6], b[6]) ,a[3] + b[2]);
    return c;
}

array<int, 7> e() {
    return array<int, 7>{0, 0, 0, 0, 0};
}

array<int, 7> mp(int f, array<int, 7> x) {
    if (f) {
        swap(x[0], x[2]);
        swap(x[1], x[3]);
        swap(x[5], x[6]);
    }
    return x;
}

int cmp(int f, int g) {
    return f ^ g;
}
int id() {
    return 0;
}
int main()
{
    int n = 0;
    int q = 0;
    string s;
    cin >> n >> q >> s;

    
    vector<array<int, 7> > v(n);
    for (int i = 0; i < n; i++) {
        v[i] = s[i] == '0' ? array<int, 7>{1, 1, 0, 0, 1, 1, 0} : array<int, 7>{0, 0, 1, 1, 1, 0, 1};
    }

    atcoder :: lazy_segtree<array<int, 7>, op, e, int, mp, cmp, id> seg(v);
    while(q--) {
        int c = 0;
        int l = 0;
        int r = 0;
        cin >> c >> l >> r;

        l--;
        if (c == 1) {
            seg.apply(l, r, 1);
        } else {
            cout << seg.prod(l, r)[6] << endl;
        }
    }

    return 0;
}