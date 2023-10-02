#include <iostream>

using namespace std;

struct Node {
    int l;
    int r;
    long long sum;
    long long lazy;
} t[400004];
void build(int rt, int l, int r) {
	t[rt].l = l;
    t[rt].r = r;
    t[rt].lazy = 0;
    if (l == r) {
        cin >> t[rt].sum;
        return;
    }

	build(rt << 1, l, (l + r) >> 1);
	build(rt << 1 | 1, ((l + r) >> 1) + 1, r);
	t[rt].sum = t[rt << 1].sum + t[rt << 1 | 1].sum;
}
void down(int rt) {
	if (t[rt].lazy){
		t[rt << 1].lazy += t[rt].lazy;
		t[rt << 1 | 1].lazy += t[rt].lazy;
		t[rt << 1].sum += (t[rt << 1].r - t[rt << 1].l + 1) * t[rt].lazy;
		t[rt << 1 | 1].sum += (t[rt << 1 | 1].r - t[rt << 1 | 1].l + 1) * t[rt].lazy;
		t[rt].lazy =0;
	}
}
void update(int rt, int c, int l, int r) {
	if (t[rt].l == l && t[rt].r == r) {
		t[rt].sum += (t[rt].r - t[rt].l + 1) * c;
		t[rt].lazy+=c;
		return;
	}

	down(rt);
	int mid = (t[rt].l + t[rt].r) / 2;
	if (r <= mid){
		update(rt << 1, c, l, r);
	} else if (l > mid) {
		update(rt << 1 | 1, c, l, r);
	} else {
		update(rt << 1, c, l, mid);
		update(rt << 1 | 1, c, mid + 1, r);
	}
	t[rt].sum = t[rt << 1].sum + t[rt << 1 | 1].sum;
}
long long query(int rt, int l, int r) {
	if (t[rt].l == l && t[rt].r == r) {
		return t[rt].sum;
	}

	down(rt);
	int mid = (t[rt].l + t[rt].r) / 2;
    long long result = 0;
	if (r <= mid) {
		result += query(rt << 1, l, r);
	} else if (l > mid) {
        result += query(rt << 1 | 1, l, r);
    } else {
        result += query(rt << 1, l, mid);
        result += query(rt << 1 | 1, mid + 1, r);
    }

	return result;
}
int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;


    build(1, 1, n);
    string op;
    int a,b,c;
    for (int i = 0; i < q; i++) {
        char op;
        int a = 0;
        int b = 0;
        cin >> op;
        if (op == 'Q') {
            cin >> a >> b;

            cout << query(1, a, b) << endl;
        } else {
            int c = 0;
            cin >> a >> b >> c;

            update(1, c, a, b);
        }
    }
	return 0;
}