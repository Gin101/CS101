#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int n = 0;
const int maxN = 9;
string s[maxN];
set<string> se;
void dfs(string str, int idx) {
    if (str.size() > 16) {
        return;
    }
    if (idx == n + 1) {
        if (str.size() < 3 || se.count(str)) {
            return;
        }
        cout << str << endl;
        exit(0);
    }
    int tmp = 15 - str.size();
    for (int i = 1; i <= tmp; i++) {
        str += '_';
        dfs(str + s[idx], idx + 1);
    }
}

int main()
{
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        string t;
        cin >> t;
        se.insert(t);
    }

    sort(s + 1, s + n + 1);
    do {
        dfs(s[1], 2);
    } while (next_permutation(s + 1, s + n + 1));

    cout << -1 << endl;

    return 0;
}