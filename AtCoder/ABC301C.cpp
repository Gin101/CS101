#include <iostream>
#include <string>

using namespace std;

const int maxS = 200;
int cnt[maxS] = {0};
int cnt2[maxS] = {0};

int main()
{
    string s;
    string t;
    cin >> s >> t;

    for (int i = 0; i < t.size(); i++) {
        cnt[t[i]]++;
        cnt2[s[i]]++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '@') {
            continue;
        }
        if (cnt[s[i]] > 0) {
            cnt[s[i]]--;
        } else if (cnt['@'] > 0 && (s[i] == 'a' || s[i] == 't' || s[i] == 'c' || s[i] == 'o' || s[i] == 'd' || s[i] == 'e' || s[i] == 'r')) {
            cnt['@']--;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '@') {
            continue;
        }
        if (cnt2[t[i]] > 0) {
            cnt2[t[i]]--;
        } else if (cnt2['@'] > 0 && (t[i] == 'a' || t[i] == 't' || t[i] == 'c' || t[i] == 'o' || t[i] == 'd' || t[i] == 'e' || t[i] == 'r')) {
            cnt2['@']--;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}