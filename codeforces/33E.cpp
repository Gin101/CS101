#include <bitset>
#include <iostream>

using namespace std;

const int maxN = 1024;
long long u[maxN] = {0};
long long v[maxN] = {0};
bitset<maxN> w[maxN];
int main()
{
    int n = 0;
    int m = 0;
    int q = 0;
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> u[i] >> v[i];
    }
    for (int i = 0; i < m; i++) {
        long long r = 0;
        long long a = 0;
        long long b = 0;
        cin >> r >> a >> b;
        
        for (int j = 1; j <= n; j++) {
            if ((u[j] - a) * (u[j] - a) + (v[j] - b) * (v[j] - b) < r * r) {
                w[j].set(i);   
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;
        
        cout << (w[a] ^ w[b]).count() << endl;
    }
  
    return 0;
}