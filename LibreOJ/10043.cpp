#include <string>
#include <iostream>

using namespace std;

const int maxN = 1001;
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
        for (int i = 1; i < t.size(); i++) {
            while (idx && t[idx] != t[i]) {
                idx = kmp[idx - 1];
            }

            if (t[idx] == t[i]) {
                idx++;
            }

            kmp[i] = idx;
        }

        idx = 0;
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            while (idx && t[idx] != s[i]) {
                idx = kmp[idx - 1];
            }

            if (t[idx] == s[i]) {
                idx++;
            }

            if (idx == t.size()) {
                result++;
                idx = 0;
            }
        }

        printf("%d\n", result);
    }

    return 0;
}