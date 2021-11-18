#include <iostream>
#include <map>

using namespace std;

const int maxN = 100001;
int num[maxN] = {0};
int tmp[maxN] = {0};
map<int, int> mp;

int dfs(int x) {
    if (tmp[x] == x) {
        return x;
    }

    tmp[x] = dfs(tmp[x]);
    return tmp[x];
}

int main()
{
    int n = 0;
    int a = 0;
    int b = 0;
    cin >> n >> a >> b;

    for (int i = 0; i < n;i++) {
        cin >> num[i];
        mp[num[i]] = i;
    }

    for (int i = 0; i < n + 2; i++) {
        tmp[i] = i;
    }
    
    int idx = 0;
    for (int i = 0; i < n; i++) {
        idx = dfs(i) ;
        if (mp.count(a - num[i])) {
            tmp[idx] = dfs(mp[a - num[i]]);
        } else {
            tmp[idx] = dfs(n);
        }

        idx = dfs(i) ;
        if (mp.count(b - num[i])) {
            tmp[idx] = dfs(mp[b - num[i]]);
        } else {
            tmp[idx] = dfs(n + 1);
        }
    }

    if (dfs(n) == dfs(n + 1)) {
        cout << "NO" << endl;
        return 0 ;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if (dfs(i) == dfs(n)) {
            cout << 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
    
    cout << endl;

    return 0 ;
}