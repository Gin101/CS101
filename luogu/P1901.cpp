#include <iostream>
#include <stack>

using namespace std;

const int maxN = 1e6;
int h[maxN] = {0};
int v[maxN] = {0};
int val[maxN] = {0};
struct Station {
    int h = 0;
    int v = 0;
};
stack<Station> st;
stack<Station> st2;

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i] >> v[i];
    }

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().h < h[i]) {
            val[i] += st.top().v;
            st.pop();
        }

        Station tmp;
        tmp.h = h[i];
        tmp.v = v[i];
        st.push(tmp);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!st2.empty() && st2.top().h < h[i]) {
            val[i] += st2.top().v;
            st2.pop();
        }
        
        Station tmp;
        tmp.h = h[i];
        tmp.v = v[i];
        st2.push(tmp);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, val[i]);
    }
    cout << result << endl;

    return 0;
}