#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int change(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        result += (s[i] - '0') * (pow(10, s.size() - i - 1));
    }

    return result;
}

bool special(string s) {
    if (s.size() != 1 && s[0] == '0') {
        return false;
    }

    return true;
}

bool check(string s) {
    char last;
    string tmp;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i != 0) {
            last = s[i - 1];
        }
        if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
            tmp += s[i];
            if (i == s.size() - 1) {
                cnt++;
                int tmp2 = change(tmp);
                if (cnt != 5 || tmp2 < 0 || tmp2 > 65535 || !special(tmp)) {
                    return false;
                }
            }
        } else if (s[i] == ':') {
            cnt++;
            int tmp2 = change(tmp);
            if (cnt != 4 || tmp2 < 0 || tmp2 > 255 || !special(tmp) || last == '.' || last == ':') {
                return false;
            }
            tmp = "";
        } else {
            cnt++;
            int tmp2 = change(tmp);
            if (cnt >= 4 || tmp2 < 0 || tmp2 > 255 || !special(tmp) || last == '.' || last == ':') {
                return false;
            }
            tmp = "";
        }
    }

    return true;
}

map<string, int> mp;
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string op;
        string ad;
        cin >> op >> ad;

        if (op == "Server") {
            if (!check(ad)) {
                cout << "ERR" << endl;
            } else {
                if (mp.count(ad)) {
                    cout << "FAIL" << endl;
                } else {
                    cout << "OK" << endl;
                    mp[ad] = i + 1;
                }
            }
        } else {
            if (!check(ad)) {
                cout << "ERR" << endl;
            } else {
                if (mp.count(ad)) {
                    cout << mp[ad] << endl;
                } else {
                    cout << "FAIL" << endl;
                }
            }
        }
    }

    return 0;
}