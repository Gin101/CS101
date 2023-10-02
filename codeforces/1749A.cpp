#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int m = 0;
        cin >> n >> m;

        for (int j = 1; j <= m; j++) {
            int x = 0;
            int y = 0;
            cin >> x >> y;
        }
        if (n == m) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

	return 0;
}