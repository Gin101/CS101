#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int maxN = 5e5 + 1;
string s;
basic_string<int> bs[maxN];
vector<pair<int, int> > e[maxN];
int result[maxN] = {0};
int num[maxN] = {0};
void dfs(int u, int d) {
    for (int i = 0; i < e[u].size(); i++) {
        result[e[u][i].second] ^= num[e[u][i].first];
    }
    num[d] ^= 1 << s[u - 1] - 'a';
    for (int i : bs[u]) {
        dfs(i, d + 1);
    }
    for (int i = 0; i < e[u].size(); i++) {
        result[e[u][i].second] ^= num[e[u][i].first];
    }
}
int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int p = 0;
        cin >> p;

        bs[p] += i;
    }

    cin >> s;

    for (int i = 1; i <= q; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        e[a].push_back({b, i});
    }

    dfs(1, 1);

    for (int i = 1; i <= q; i++) {
        puts((result[i] & -result[i]) == result[i] ? "Yes" : "No");
    }

    return 0;
}