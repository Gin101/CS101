#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <stack>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxLen = 26;
const int maxL = 100;
bool flag[maxLen] = {false};

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int l = 0;
        string s;
        cin >> l >> s;

        memset(flag, false, sizeof(flag));
        int cnt = 0;
        stack<int> pre;
        stack<char> rec;
        pre.push(0);
        bool flag2 = true;
        int idx = 0;
        int idx2 = 0;
        for (int j = 0; j < l; j++) {
            char o;
            cin >> o;

            if (o == 'F') {
                char c; 
                int x = 0;
                int y = 0;
                string x2;
                string y2;
                cin >> c >> x2 >> y2;

                c -= 97; 
                rec.push(c);
                if (!flag2) {
                	pre.push(pre.top());
                    continue;
                }

                if (flag[c]) {
                    cout << "ERR" << endl;
                    flag2 = false;
                }

                if (x2[0] == 'n') {
                    x = 100;
                } else {
                    for (int k = 0; k < x2.size(); k++) {
                        x += (x2[k] - '0') * pow(10, x2.size() - 1 - k);
                    }
                }
                
                if (y2[0] == 'n') {
                    y = 100;
                } else {
                    for (int k = 0; k < y2.size(); k++) {
                        y += (y2[k] - '0') * pow(10, y2.size() - 1 - k);
                    }
                }

                flag[c] = true;
                if (y == 100 && x != 100) {
                    pre.push(pre.top() + 1);
                } else {
                    if (y - x + 1 < 0) {
                        pre.push(INT_MIN);
                    } else {
                        pre.push(pre.top());
                    }
                }
            } else {
                if (!flag2) {
                    continue;
                }
                if (pre.size() <= 1) {
                    cout << "ERR" << endl;
                    flag2 = false;
                } else {
                    cnt = max(cnt, pre.top());
                    flag[rec.top()] = false;
                    rec.pop();
                	pre.pop();
                }
            }
        }

        if (flag2) {
            int cnt2 = 0;
            if (s.size() != 4) {
                for (int i = 4; i < s.size() - 1; i++) {
                    cnt2 += (s[i] - '0') * pow(10, s.size() - 2 - i);
                }
            }

            if (pre.size() == 1 && cnt == cnt2) {
                cout << "Yes" << endl;
            } else if (pre.size() != 1) {
                cout << "ERR" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}