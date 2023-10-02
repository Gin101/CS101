#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 26;
int in[maxN] = {0};
bool flag[maxN] = {false};
vector<int> e[maxN];
queue<int> q;
int result[maxN] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        in[s[2] - 65]++;
        e[s[0] - 65].push_back(s[2] - 65);
    }

    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    int idx = 0;
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        if (flag[q.front()]) {
            
        }

        flag[q.front()] = true;
        result[idx++] = q.front();
        for (int i = 0; i < e[q.front()].size(); i++) {
            if (in[e[q.front()][i]] == 0) {
                cout << "Inconsistency found after " << cnt << " relations." << endl;
                return 0;
            }
            if (--in[e[q.front()][i]] == 0) {
                q.push(e[q.front()][i]);
            }
        }
        q.pop();

        if (idx == n) {
            cout << "Sorted sequence determined after " << cnt << " relations: ";
            for (int i = 0; i < n; i++) {
                cout << char(result[i] + 65);
            }
            cout << '.' << endl;
            return 0;
        }
    }

    cout << "Sorted sequence cannot be determined." << endl;

    return 0;
}