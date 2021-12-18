#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

const int maxS = 1e4;
struct Num {
    int val;
    int idx;
} num[maxS], maxV, tmp;

vector<Num> r[maxS];
int idx2[maxS] = {0};

int main()
{
    string s;
    cin >> s;

    stack<char> st;
    int cnt = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'a') {
            idx2[i] = cnt++;
            st.push(s[i]);
        } else {
            cnt = idx2[i - (s[i] - '0')];
            idx2[i] = cnt;
            for (int j = 0; j < s[i] - '0'; j++) {
                idx2[i - j - 1] = cnt;
                st.pop();
            }
            st.push(s[i] - '0' - 1 + 'a');
            cnt++;
        }
    } // input

    stack<int> st2;
    while (!st.empty()) {
        st2.push(st.top());
        st.pop();
    } // reserve

    int idx = 0; // how many struct
    while (!st2.empty()) {
        num[idx].idx = idx;
        num[idx++].val = st2.top() - 'a' + 1;
        st2.pop();
    } // get input

    for (int i = 0; i < idx; i++) {
        num[i].val += i;
        if (maxV.val < num[i].val) {
            maxV.val = num[i].val;
            maxV.idx = num[i].idx;
        }
    } // the first line (giganic)

    if (maxV.idx != idx - 1) {
        r[0].push_back(maxV);
    }
    r[0].push_back(num[idx - 1]); // the first set (giganic)
    
    for (int i = 1; i < idx; i++) {
        if ((num[i - 1].val - i + idx < r[i - 1][0].val - 1) && r[i - 1][0].idx > 0) {
            tmp.val = r[i - 1][0].val - 1;
            tmp.idx = r[i - 1][0].idx - 1;
            r[i].push_back(tmp);
        }

        tmp.val = num[i - 1].val - i + idx;
        tmp.idx = idx - 1;
        r[i].push_back(tmp);
    } // monotonic queue

    // for (int i = 0; i < idx; i++) {
    //     for (int j = 0; j < r[i].size(); j++) {
    //         cout << r[i][j].val << ' ';
    //     }
    //     cout << endl;
    // }

    int result = INT_MAX;
    int resultIdx = 0;
    for (int i = 0; i < idx; i++) {
        if (result > r[i][0].val) {
            result = r[i][0].val;
            resultIdx = i;
        }
    }

    cout << result << endl;

    // for (int i = 0; i < s.size(); i++) {
    //     cout << idx2[i] << ' ';
    // }
    // cout << endl;

    for (int i = 0; i < s.size(); i++) {
        if (idx2[i] == resultIdx) {
            for (int j = i; j < s.size() - 1; j++) {
                cout << s[j];
            }

            for (int j = 0; j < i; j++) {
                cout << s[j];
            }

            cout << s[s.size() - 1] << endl;
            
            break;
        }
    }

    return 0;
}