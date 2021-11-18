#include <iostream>
#include <stack>

using namespace std;

const int maxN = 200001;
int cnt = 0;
int tot = 0;
int last[maxN] = {0};
int s[maxN] = {0};
int col[maxN] = {0};
int head[maxN] = {0};
int _next[maxN * 2] = {0};
int vet[maxN * 2] = {0};

void ope(int x, int y) { 
    cnt++;
    _next[cnt] = head[x];
    head[x] = cnt;
    vet[cnt] = y;
}

int low[maxN] = {0};
int dfn[maxN] = {0};
bool flag[maxN] = {0};
int tmp = 0;
stack<int> st;

void tarjan(int x) {
    dfn[x] = ++tmp;
    low[x] = dfn[x];
    flag[x] = true;
    st.push(x);

    for (int i = head[x]; i; i = _next[i]) {
        int v = vet[i];
        if (!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if (flag[v]) {
            low[x] = min(low[x], dfn[v]);
        }
    }
    
    if (low[x] == dfn[x]) {
        tot++;
        int t = -1;
        while (t != x) {
            t = st.top();
            st.pop();
            flag[t] = false;
            col[t] = tot;
        }
    }
}

int main()
{
    int m = 0;
    int n = 0;
    cin >> m >> n;

    int idx = 0;
    for (int i = 1; i <= m; i++) {
        int l = 0;
        cin >> l;
        for (int j = 1; j <= l; j++) {
            cin >> s[j];
        }

        for (int j = 1; j <= min(idx, l); j++) {
            if (last[j] < s[j]) {
                ope(s[j], last[j]);
                ope(last[j] + n, s[j] + n);
                break;
            } else if (last[j] > s[j]) {
                ope(last[j] + n, last[j]);
                ope(s[j], s[j] + n);
                break;
            }
            if (j == min(idx, l) && idx > l) {
                cout << "No" << endl;
                return 0;
            }
        }
        idx = l;
        for (int j = 1; j <= l; j++) {
            last[j] = s[j];
        }
    }
    
    for (int i = 1; i <= n * 2; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if(col[i] == col[i + n]) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (col[i] < col[i + n]) {
            result++;
        }
    }

    cout << result << endl;
    for(int i = 1; i <= n; i++){
        if (col[i] < col[i + n]) {
            cout << i << ' ';
        }
    }

    cout << endl;
    
    return 0;
}