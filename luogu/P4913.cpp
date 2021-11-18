#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 1e6;
vector<int> e[maxN];
bool flag[maxN] = {false};
int result = 0;
void dfs(int u, int num) {
    flag[u] = true;
    for (int i = 0; i < e[u].size(); i++) {
        if (!flag[e[u][i]]) {
            dfs(e[u][i], num + 1);
        }  
    }  

    result = max(result, num);
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        if (u != 0) {
            e[i].push_back(u - 1);
        }
        
        if (v != 0) {
            e[i].push_back(v - 1);
        }
    }

    dfs(0, 1);

    cout << result << endl;

    return 0;
}