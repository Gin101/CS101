#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    freopen("filo.in", "r", stdin);
    freopen("filo.out", "w", stdout);

    string s;
    string s2 = "ABCDEFGH";
    cin >> s;

    stack<char> st;
    st.push('A');
    int idx = 1;
    for (int i = 0; i < 8; i++) {
        if (st.top() > s[i]) {
            cout << 0 << endl;
            return 0;
        }

        while (st.top() < s[i]) {
            st.push(s2[idx++]);
        }
        st.pop();
    }

    cout << 1 << endl;

    return 0;
}