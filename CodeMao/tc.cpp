#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <stack>

using namespace std;

const int maxLen = 26;
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
        long long tmp = 1;
        stack<long long> pre;
        pre.push(1);
        bool flag2 = true;
        bool flag3 = true;
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
                if (flag[c] && flag2) {
                    cout << "ERR" << endl;
                    flag2 = false;
                }

                if (!flag2 || !flag3) {
                	pre.push(1);
                    continue;
                }

                if (x2[0] == 'n') {
                    x = 101;
                } else {
                    for (int k = 0; k < x2.size(); k++) {
                        x += (x2[k] - '0') * pow(10, x2.size() - 1 - k);
                    }
                }
                
                if (y2[0] == 'n') {
                    y = 101;
                } else {
                    for (int k = 0; k < y2.size(); k++) {
                        y += (y2[k] - '0') * pow(10, y2.size() - 1 - k);
                    }
                }

                flag[c] = true;
                if (y == 101 && x != 101) {
                	tmp = 101 * pre.top();
                    pre.push(tmp);
                } else {
                    tmp = y - x + 1;
                    if (tmp < 0) {
                    	tmp = pre.top();
                    	pre.push(1);
                        flag3 = false;
                    } else {
                    	pre.push(tmp * pre.top());
                    }
                }
            } else {
                if (pre.size() == 1 && flag2) {
                    cout << "ERR" << endl;
                    flag2 = false;
                } else {
                	pre.pop();
                }
            }
        }

        if (flag2) {
            long long need = 1;
            if (s.size() != 4) {
                int w = 0;
                for (int i = 4; i < s.size() - 1; i++) {
                    w += (s[i] - '0') * pow(10, s.size() - 2 - i);
                }

                need = pow(101, w);
            }
            if (pre.size() == 1 && tmp == need) {
                cout << "Yes" << endl;
            } else if (pre.size() > 1) {
                cout << "ERR" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}