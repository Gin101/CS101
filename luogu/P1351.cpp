#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e5 + 1;
const int MOD = 10007;
int w[maxN] = {0};
int u[maxN] = {0};
int v[maxN] = {0};
int mx[maxN] = {0};
int s[maxN] = {0};
int main() 
{
    int n = 0;
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> u[i] >> v[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
   
    int result = 0;
    int result2 = 0;
    for (int i = 1; i < n; i++) {
        result = max(result, max(w[u[i]] * mx[v[i]], w[v[i]] * mx[u[i]]));
        result2 = (result2 + 1ll * (w[u[i]] % MOD) * (s[v[i]] % MOD) + 1ll * (w[v[i]] % MOD) * (s[u[i]] % MOD)) % MOD;
        s[u[i]] += w[v[i]];
        s[v[i]] += w[u[i]];
        mx[u[i]] = max(mx[u[i]], w[v[i]]);
        mx[v[i]] = max(mx[v[i]], w[u[i]]);
    }

    cout << result << ' ' << result2 * 2 % MOD << endl;

    return 0;
}