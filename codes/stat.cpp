#include <iostream>

using namespace std;

int n = 0;
int m = 0;
int ans = 0;

int nodes[15][35] = {0};	// 记录当前节点可以去哪些节点
int w[15][35] = {0};		// 记录节点到其他节点需要的路程
int cnt[15] = {0};			// 记录节点有多少条路径

bool visited[15][35] = {false};

void dfs(int seq, int left, int sum, int flag[])
{
	// cout << "-------------------------" << endl;
	// cout << "seq: " << seq << endl;
	// cout << "left: " << left << ", sum: " << sum << endl;

	if (left == 0) {
		// cout << "ans: " << ans << endl;
		if (ans == 0) {
			ans = sum;
		} else {
			ans = min(ans, sum);
		}
		return;
	}

	for (int i = 0; i < cnt[seq]; i++) {
		// cout << "$$$$$$$" << endl;
		// printf("seq: %d -> try: %d / %d\n", seq, i + 1, cnt[seq]);
		if (visited[seq][i]) {
			// printf("i: %d, visited [%d -> %d]\n", i, seq, nodes[seq][i]);
			continue;
		}
		visited[seq][i] = true;

		int nextNode = nodes[seq][i];
		int newL = left;

		// cout << "next node: " << nextNode << endl;
		// for (int j = 0; j <= 15; j++) {
		// 	cout << flag[j] << " ";
		// }
		// cout << endl;

		
		if (flag[nextNode] == 0) {
			// printf("new vvvv\n");
			newL--;
		}
		flag[nextNode]++;

		dfs(nodes[seq][i], newL, sum + w[seq][i], flag);
		visited[seq][i] = false;
		flag[nextNode]--;
	}
	// cout << "seq: " << seq << ", finish loop" << endl;
}

int main()
{
	// freopen("stat.in", "r", stdin);
	// freopen("stat.out", "w", stdout);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u = 0;
		int v = 0;
		int d = 0;
		cin >> u >> v >> d;

		nodes[u][cnt[u]] = v;
		w[u][cnt[u]] = d;
		cnt[u]++;
	}

	for (int i = 1; i <=n; i++) {
		// cout << "*******************" << endl;
		// cout << "start from: " << i << endl;
		int flag[15] = {false};
		flag[i] = 1;
		dfs(i, n - 1, 0, flag);
	}

	if (ans == 0) {
		cout << "NO" << endl;
	} else {
		cout << ans << endl;
	}

	return 0;
}