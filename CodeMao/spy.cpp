#include <iostream>
#include <string>

using namespace std;

char p[26] = {0};
char p2[26] = {0};

int main()
{
    string s;
    string s2;
    string s3;
    cin >> s >> s2 >> s3;

    for (int i = 0; i < s.size(); i++) {
        if (p2[s2[i] - 'A'] != 0 && p2[s2[i] - 'A'] != s[i]) {
            cout << "Failed" << endl;
            return 0;
        }
        p[s[i] - 'A'] = s2[i];
        p2[s2[i] - 'A'] = s[i];
    }

    for (int i = 0; i < 26; i++) {
        cout << p2[i] << endl;
        if (p2[i] == ' ') {
            cout << "Failed" << endl;
            return 0;
        }
    }

    for (int i = 0; i < s3.size(); i++) {
        if (p[s3[i] - 'A'] == ' ') {
            cout << "Failed" << endl;
            return 0;
        } else {
            s3[i] = p[s3[i] - 'A'];
        }
    }

    cout << s3 << endl;

    return 0;
}