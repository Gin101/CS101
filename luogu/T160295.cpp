#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const long long MOD = 1e9 + 7;
const int maxN = 5e5;
int sum[maxN] = {0};

int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            sum[i]++;
        }
    }

    for (int i = 0; i < q; i++) {
        int l = 0;
        int r = 0;
        long long x = 0;  
        cin >> l >> r >> x;

        string tmp = s.substr(l - 1, r);
        sort(tmp.begin(), tmp.end());
        
        sum[r - 1] - sum[l - 1];
        int idx = log2(x & (~x + 1));
        for (int j = l - 1; j < r; j++) {
            x %= MOD;
            int cnt = 0;

            if (tmp[j] == '0') {
                
            } else {
                idx = 31 -  __builtin_clz(x);
            }

            x += (long long)(1 << idx) % MOD;
            x %= MOD;
        }

        x %= MOD;
        cout << x << endl;
    }

    return 0;
}