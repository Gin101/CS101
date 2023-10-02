#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
const int maxN = 3e5;
vector<pair<long long, long long> > e[maxN];
bool flag[maxN][2] = {{false}};
long long num[maxN][2] = {{0}};
long long cnt = 0;
long long ope(int x, int t) {
    if (flag[x][t]) {
        return num[x][t];
    }
    flag[x][t] = true;
    if (e[x].empty()) {
        return num[x][t] = 0;
    }
    num[x][t] = 1e16;
    long long tmp = t ? 0 : 1e16;
    for (auto [i, j] : e[x]) {
        long long tmp2 = ope(i, t ^ 1) + j;
        tmp = t ? max(tmp, tmp2) : min(tmp, tmp2);
    }

    return num[x][t] = tmp;
} 

signed main()
{
    int n = 0;
    int m = 0;
    long long s = 0;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        long long c = 0;
        cin >> a >> b >> c;

        e[a].push_back({b, c});
    }
   
    long long result = ope(s, 0);
    if (result > 1e15) {
        cout << "INFINITY" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
