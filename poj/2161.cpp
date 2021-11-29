#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int maxS = 1e6;
struct Num {
    int val = 0;
    int idx = 0;
} num[maxS], maxV;

vector<Num> r[maxS];

int main()
{
    string s;
    cin >> s;

    stack<char> st;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'a') {
            st.push(s[i]);
        } else {
            for (int j = 0; j < s[i] - '0'; j++) {
                st.pop();
            }
            st.push(s[i] - '0' - 1 + 'a');
        }
    }

    stack<int> st2;
    while (!st.empty()) {
        st2.push(st.top());
        st.pop();
    }

    int idx = 0;
    while (!st2.empty()) {
        num[idx].idx = idx;
        num[idx++].val = st2.top() - 'a' + 1;
        st2.pop();
    }

    for (int i = 0; i < idx; i++) {
        num[i].val += i;
        if (maxV.val < num[i].val) {
            maxV.val = num[i].val;
            maxV.idx = num[i].idx;
        }
    }

    if (maxV.idx != idx) {
        r[0].push_back(maxV);
    } 
    r[0].push_back(num[idx]);
    
    for (int i = 1; i < idx; i++) {
        for (int j = 0; j < r[i - 1].size(); j++) {
            if (r[i - 1][j].idx != idx) {
                if (num[i - 1].val + idx - 1 < r[i - 1][j].val - 1) {
                    r[i].push_back({r[i - 1][j].val - 1, r[i - 1][j].idx});
                }
                r[i].push_back({num[i - 1].val, idx});
            }
        }
    }



    return 0;
}