#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k = 0;
const int maxN = 2e5 + 1;
const int maxK = 2e5 + 1;
int result[100000] = {0};
struct Tshirt {
    int c = 0;
    int q = 0;
} t[500000];
struct People {
    int v = 0;
    int idx = 0;
    bool operator<(People x) const {
        return v == x.v ? idx < x.idx : v < x.v;
    }
} b[500000];

struct Node {
    int l = 0;
    int r = 0;
    int c = 0;
    int q = 0;
};
vector<Node> num;

bool cmp(Tshirt x, Tshirt y) {
    return x.q == y.q ? x.c < y.c : x.q > y.q;
}
void ope() {
    for (int i = 0; i < num.size(); i++) {
        for (int j = num[i].l; j <= num[i].r; j++) {
            result[b[j].idx] += num[i].q;
            b[j].v -= num[i].c;
        }
    }

    num.clear();
    sort(b + 1, b + k + 1);
    num.push_back({1, k, 0, 0});
}
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t[i].c >> t[i].q;
    }
    sort(t + 1, t + n + 1, cmp);

    cin >> k;

    for (int i = 1; i <= k; i++) {
        cin >> b[i].v;
        b[i].idx = i;
    }
    sort(b + 1, b + k + 1);
    num.push_back({1, k, 0, 0});
    for (int i = 1; i <= n; i++) {
        int s = num.size();
        for (int j = 0; j < s; j++) {
            if (num[j].c + t[i].c <= b[num[j].l].v) {
                num[j].q++;
                num[j].c += t[i].c;
            } else if (num[j].c + t[i].c <= b[num[j].r].v) {
                int tmp = lower_bound(b + 1, b + k + 1, People{num[j].c + t[j].c, 0}) - b;
                num.push_back({tmp, num[j].r, num[j].c + t[i].c, num[j].q + 1});
                num[j].r = tmp - 1;
            }
        }
        if (num.size() > 444) {
            ope();
        }
    }
	
    ope();
    for (int i = 1; i <= k; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;

	return 0;
}