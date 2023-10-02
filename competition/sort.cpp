#include <iostream>

using namespace std;

const int maxN = 8000;
int a[maxN] = {0};
int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        int o = 0;
        cin >> o;
        
        int result = 0;
        int result2 = 0;
        if (o == 1) {
            int x = 0;
            int v = 0;
            cin >> x >> v;

            a[x - 1] = v;
        } else {
            int x = 0;
            cin >> x;

            for (int i = 0; i < x; i++) {
                if (a[i] > a[x - 1]) {
                    result++;
                }
            }

            for (int i = x; i < n; i++) {
                if (a[i] < a[x - 1]) {
                    result2++;
                }
            }

            cout << x - result + result2 << endl;
        }
    }
    
    return 0;
}