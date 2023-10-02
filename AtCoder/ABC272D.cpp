#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int maxN = 400;
int graph[maxN][maxN] = {{0}};
queue<pair<int, int> > q;

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    memset(graph, -1, sizeof(graph));
    graph[0][0] = 0;
    
    q.emplace(0, 0);
    while (!q.empty()) {
        for (int i = 0; i < n; i++) {
            int num = m - (q.front().first - i) * (q.front().first - i);
            int tmp = (int)round(sqrt(num));
            if (num == tmp * tmp) {
                if (0 <= q.front().second - tmp && q.front().second - tmp < n && graph[i][q.front().second - tmp] == -1) {
                    graph[i][q.front().second - tmp] = graph[q.front().first][q.front().second] + 1;
                    q.emplace(i , q.front().second - tmp);
                }
                if (0 <= q.front().second + tmp && q.front().second + tmp < n && graph[i][q.front().second + tmp] == -1) {
                    graph[i][q.front().second + tmp] = graph[q.front().first][q.front().second] + 1;
                    q.emplace(i, q.front().second + tmp);
                }
            }
        }
        q.pop();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }

	return 0;
}