#include <iostream>
#include <string>

using namespace std;

const int maxN = 101;
string s[maxN];
int n = 0;
bool check() {
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << endl << n << endl;
        for (int j = i + 1; j <= n; j++) {
            cout << s[i] << endl << s[j] << endl;
            if (s[i] == s[j]) {
                return false;
            }
        }
    }

	for (int i = 2; i <= n; i++) {
        if (s[i][0] != s[i - 1][s[i - 1].size() - 1]) {
            return false;
        }
	}
	return true;
}
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    cout << n << endl;
    if (!check()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

	return 0;
}