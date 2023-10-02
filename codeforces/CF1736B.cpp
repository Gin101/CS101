#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[i];
        }
        bool flag = true;
        for (int j = 1; j <= n - 2; j++) {
            flag = flag & (a[j] % __gcd(a[j - 1], a[j + 1] == 0));
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
	
    return 0;
}