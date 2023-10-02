#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;

int main()
{
    int n = 0;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            int a = 0;
            cin >> a;

            mp[-a]++;
        }

        for (auto it : mp) {
            cout << it.second << endl;
        }
        for (int i = 1; i <= n - (int)mp.size(); i++) {
            cout << 0 << endl;
        }
    }

	return 0;
}