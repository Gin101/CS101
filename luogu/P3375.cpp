#include <iostream>
#include <string>

using namespace std;

const int maxS = 1e6;
int kmp[maxS] = {0};
int result[maxS] = {0};
void ope(string s) {
    for (int i = 1; i < s.size(); i++) {
        int idx = kmp[i - 1];
        while (idx > 0 && s[i] != s[idx]) {
            idx = kmp[idx - 1];
        }

        if (s[i] == s[idx]) {
            idx++;
        }
        kmp[i] = idx;
    }
}
int main()
{
    string s;
    string t;
    cin >> s >> t;

    string tmp;
    tmp += t;
    tmp += '#';
    tmp += s;
    ope(tmp);

    for (int i = 0; i < tmp.size(); i++) {
        if (kmp[i] == t.size()) {
            cout << i - 2 * t.size() + 1 << endl;
        }
    }

    ope(t);

    for (int i = 0; i < t.size(); i++) {
        cout << kmp[i] << ' ';
    }

    cout << endl;

    return 0;
}