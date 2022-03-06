#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
    int n = 0;
    int l = 0;
    long long i = 0;
    cin >> n >> l >> i;

    long long cnt = pow(2, l);
    i -= cnt;
    long long cnt2 = 0;
    long long tmp = 0;
    while (i > 0) {
        tmp = cnt;

        long long cnt2 = 0;
        while (tmp != 0) {
            tmp &= (tmp - 1);
            cnt2++;
        }

        if (cnt2 <= l) {
            i--;
        }
        cnt++;
    }

    tmp = cnt - abs(i - 0) - 1;
    stack<int> st;
    while (tmp > 0) {
        st.push(tmp % 2);
        tmp /= 2;
    }

    for (int i = st.size(); i < n; i++) {
        cout << 0;
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    cout << endl;

    return 0;
}