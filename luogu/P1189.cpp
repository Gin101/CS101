#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxN = 51;

int n = 0;
int m = 0;
char graph[maxN][maxN];
bool flag[maxN][maxN] = {{false}};
int nr[4] = {0, 0, -1, 1};
int nc[4] = {-1, 1, 0, 0};
queue<int> q; 
queue<int> tmp;

void dfs(int r, int c, int idx) {
    int newr = r + nr[idx];
    int newc = c + nc[idx];
    if (graph[newr][newc] == 'X' || newr > n || newr <= 0 || newc > m || newc <= 0) {
        return;
    }
    if (flag[newr][newc]) {
        return;
    }
    flag[newr][newc] = true;
    tmp.push(newr);
    tmp.push(newc);
    dfs(newr, newc, idx);
}

int op = 0;
void bfs(string s) {
    while (!q.empty()) {
        int newr = q.front();
        q.pop();
        int newc = q.front();
        q.pop();
        if (s[0] == 'N') {
            op = 2;
        } else if (s[0] == 'S') {
            op = 3;
        } else if (s[0] == 'W') {
            op = 0;
        } else {
            op = 1;
        }
        dfs(newr, newc, op);
    }
    memset(flag, false, sizeof(flag));
    while (!tmp.empty()) {
        q.push(tmp.front());
        tmp.pop();
        q.push(tmp.front());
        tmp.pop();
    }
}

int main()
{
	cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == '*') {
                q.push(i);
                q.push(j);
                graph[i][j] = '.';
            }
        }
    }
	
    int w = 0;
    cin >> w;

    for (int i = 0; i < w; i++) {
        string s;
        cin >> s;
        bfs(s);
    }
	
    while (!q.empty()) {
        int newr = q.front();
        q.pop();
        int newc = q.front();
        q.pop();
        graph[newr][newc] = '*';
    }
	
	
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }

	return 0;
}