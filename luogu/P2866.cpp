#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main()
{
    int n = 0;
    cin >> n;

    long long result = 0;
    for (int i = 0; i < n; i++) {
        int h = 0;
        cin >> h;

        while (!st.empty() && st.top() <= h) {
            st.pop();
        }
        result += st.size();
        st.push(h);
    }

    cout << result << endl;

    return 0;
}