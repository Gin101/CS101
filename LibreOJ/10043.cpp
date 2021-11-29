#include <iostream>
#include <string>

using namespace std;

const int maxN = 1000;
int kmp[maxN] = {0};

int main() 
{
    while (true) {
        string s;
        cin >> s;

        if (s.size() == 1 && s[0] == '#') {
            break;
        }

        string t;
        cin >> t;

        int idx = 0;
        for (int i = 0; i < t.size(); i ++) {
            while (idx && t[idx + 1] != t[i]) {
                idx = kmp[idx];
            }

            if (t[idx + 1] == t[i]) {
                idx++;
            }

            kmp[i] = idx;
        }

        idx = 0;
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            while (idx && t[idx + 1] != s[i]) {
                idx = kmp[idx];
            }

            if (s[i] == t[idx + 1])
                idx++ ;

            if (idx == t.size()) {
                result++;
                idx = 0;
            }
        }

        cout << result << endl;
    }

    return 0;
}