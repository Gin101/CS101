#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e5;
int k = 0;
int a[maxN] = {0};
vector<int> e[maxN];
int result = 0;
int dfs(int u, int deep){
	int tmp = deep;
    for (int i = 0; i < e[u].size(); i++) {
        tmp = max(tmp, dfs(e[u][i], deep + 1));
    }

	if (a[u] != 1 && tmp - deep == k - 1) {
        result++;
        return 0;
    } else {
        return tmp;
    }
}

int main()
{
    int n = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a[0] != 1) {
        result = 1;
        a[0] = 1;
    }

	for (int i = 1; i < n; i++) {
        e[a[i] - 1].push_back(i);
    }

	dfs(0, 0);

    cout << result << endl;

    return 0;
}