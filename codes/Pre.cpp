#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

void ope(int first, int second) {
    cout << first << ' ' << second << endl;

    st.pop();
    int pre = 0;
    switch (st.top()) {
        case 43: {
            st.pop();
            if (!st.empty()) {
                pre = st.top();
            } else {
                pre = 0;
            }
            st.push(second + first);
            break;
        } case 45: {
            st.pop();
            if (!st.empty()) {
                pre = st.top();
            } else {
                pre = 0;
            }
            st.push(second - first);
            break;
        } case 42: {
            st.pop();
            if (!st.empty()) {
                pre = st.top();
            } else {
                pre = 0;
            }
            st.push(second * first);
            break;
        } case 47: {
            st.pop();
            if (!st.empty()) {
                pre = st.top();
            } else {
                pre = 0;
            }
            st.push(second / first);
        }
    }

    if (pre >= 1 && pre <= 9) {
        int pre2 = st.top();
        st.pop();
        ope(pre2, pre);
    }
}

int main()
{
    int n = 0;
    cin >> n;

    int c = 0;
    cin >> c;
    st.push(c);
    for (int i = 1; i < n; i++) {
        cin >> c;

        if ((st.top() >= 1 && st.top() <= 9) && (c >= 1 && c <= 9)) {
            ope(c, st.top());
        } else {
            st.push(c);
        }
    }

    cout << st.top() << endl;

    return 0;
}