#include <iostream>
#include <stack>

using namespace std;

struct Num {
    int val = 0;
    int idx = 0;
};
stack<Num> st;
const int maxN = 3e6;
int result[maxN] = {0};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;

        while (!st.empty() && st.top().val < a) {
            result[st.top().idx] = i + 1;
            st.pop();
        }

        Num tmp;
        tmp.val = a;
        tmp.idx = i;
        st.push(tmp);
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}