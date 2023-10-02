#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN = 2e4 + 1;
struct BIT {
    long long tree[maxN];

    void init() {
        memset(tree, 0, sizeof(tree));
    }
    long long getsum(int idx) {
        long long result = 0;
        while (idx > 0) {
            result += tree[idx];
            idx -= idx & -idx;
        }
        return result;
    }

    void update(int idx, long long num) {
        while (idx <= maxN) {
            tree[idx] += num;
            idx += idx & -idx;
        }   
    }
} t, t2;
struct Node {
    long long vi;
    long long vj;
} V[maxN];
bool cmp(Node x, Node y) {
    return x.vi == y.vi ? x.vj < y.vj : x.vi < y.vi;
}
int main(){
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> V[i].vi >> V[i].vj;
    }

    t.init();
    t2.init();
    sort(V, V + n, cmp);
    long long result = 0;
    long long sum = 0;
    long long sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 = t.getsum(V[i].vj);
        long long tmp = t2.getsum(V[i].vj);
        result += ((sum - tmp * 2) * V[i].vi);
        result += ((sum2 * 2 - i) * V[i].vi * V[i].vj);
        t2.update(V[i].vj, V[i].vj);
        t.update(V[i].vj, 1);
        sum += V[i].vj;
    }

    cout << result << endl;

    return 0;
}