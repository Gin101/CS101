#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;
        string t;

        int l = 1;
        int r = 0;
        bool flag = false;
        while (l <= s.size() && r <= t.size()) {
            if (s[l] == t[r]) {
                l++;
                r++;
            } else if (t[r] == t[r - 1]) {
                r++;
            } else {
                flag = true;
                break;
            }
        }
        if (l <= s.size()) {
            flag = true;
        }
        while (t[r] == t[r - 1]) {
            r++;
        }
        if (r <= t.size()) {
            flag = true;
        }
        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
	
	return 0;
}