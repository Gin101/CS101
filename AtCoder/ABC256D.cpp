#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;

int main() 
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        mp[u]++;
        mp[v]--;
    }

    int cnt = 0;
    for (auto idx : mp) {
        if (!cnt) {
            cout << idx.first << ' ';
        } 
        cnt += idx.second;
        if (!cnt) {
            cout << idx.first << endl;
        }
    }

    return 0;
}