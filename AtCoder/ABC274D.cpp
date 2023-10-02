#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

const int t = 1e4;
const int maxM = 2e4 + 1;
bitset<maxM> h;
bitset<maxM> s;
int main()
{
    int n = 0;
    int x = 0;
    int y = 0;
    int a = 0;
    cin >> n >> x >> y >> a;

    h[t + a] = 1;
    s[t] = 1;
    for (int i = 2; i <= n; i++) {
        int a = 0;
        cin >> a;

        a = abs(a);
        if (i & 1) {
            h = (h << a) | (h >> a);
        } else {
            s = (s << a) | (s >> a);
        }
    }

    if (h[t + x] && s[t + y]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
	return 0;
}
