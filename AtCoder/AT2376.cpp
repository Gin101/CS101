#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e5;
vector<int> e[maxN];

int dfs(int u, int pre) {
	int result = 0;
	for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i] != pre) {
            int tmp = dfs(e[u][i], u);
            if (tmp > 1) {
                return tmp;
            }
            result += tmp;
        }
	}

	return result ^ 1;
}

int main()
{
	int n = 0;
    cin >> n;

	for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        e[u - 1].push_back(v - 1);
        e[v - 1].push_back(u - 1);
	}
	
	if (dfs(0, 0) >= 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
	
	return 0;
}