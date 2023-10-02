#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> e[10];
bool flag[10] = {false};
string s;
void add(int u, int v) {
    e[u].push_back(v);
    e[v].push_back(u);
}
void dfs(int u) {
    if (s[u] != '0' && !flag[u]) {
        flag[u] = true;
        for (int i = 0; i < e[u].size(); i++) {
            dfs(e[u][i]);
        }
    }
}

int main()
{   
    cin >> s;

    add(0, 1);
    add(0, 2);
    add(1, 3);
    add(1, 4);
    add(2, 4);
    add(2, 5);
    add(3, 6);
    add(3, 7);
    add(4, 7);
    add(4, 8);
    add(5, 8);
    add(5, 9);
    for (int i = 0; i < s.size(); i++) {
        if (s[0] == '1') {
            cout << "No" << endl;
            return 0;
        } 
        if (s[i] == '1') {
            dfs(i);
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (!flag[i] && s[i] == '1') {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}