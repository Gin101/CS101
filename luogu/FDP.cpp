#include <iostream>
#include <string>
#include <map>

using namespace std;

long long result = 0;
map<string, bool> mp;

void ope(int a, int b, int c, string s) {
    if (!a && !b && !c && !mp.count(s)) {
        for (int i = 0; i < 8; i++) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                mp[s] = true;
                result++;
                return;
            }
        }
    }

    string tmp;
    if (a) {
        tmp = s + 'a';
        ope(a - 1, b, c, tmp);
    }
    if (b) {
        tmp = s + 'b';
        ope(a, b - 1, c, tmp);
    }
    if (c) {
        tmp = s + 'c';
        ope(a, b, c - 1, tmp);
    }
}

int main()
{
    ope(3, 5, 2, "");

    cout << result << endl;

    return 0;
}