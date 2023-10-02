#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int pre[26] = {0};
int _next[26] = {0};
int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        string s;
        cin >> n >> s;

        memset(_next, -1, sizeof(_next));
        memset(pre, -1, sizeof(pre));
        for (int j = 0; j < s.size(); j++) {
            int u = s[j] - 'a';
            if (_next[u] == -1) {
                int v = -1;
                while (true) {
                    v++;
                    if (u == v || pre[v] != -1) {
                        continue;
                    }
                    int tmp = v;
                    int cnt = 0;
                    while (_next[tmp] != -1) {
                        tmp = _next[tmp];
                        cnt++;
                    }

                    if (tmp == u && cnt < 25) {
                        continue;
                    }
                    _next[u] = v;
                    pre[v] = u;
                    break;
                }
            }
            s[j] = _next[u] + 'a';
        }
        cout << s << endl;
    }
	
    return 0;
}