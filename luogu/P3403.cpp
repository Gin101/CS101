#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int maxN = 1e5 + 1;
const int INF = 0x3f3f3f3f;

struct Node {
    int idx = 0;
    int val = 0;
} tmp;

vector<Node> e[maxN];
queue<int> q;
long long dis[maxN] = {0};
bool flag[maxN] = {false};

int main()
{
    long long h = 0;
    long long x = 0;
    long long y = 0;
    long long z = 0;
    cin >> h >> x >> y >> z;

    if (x == 1 || y == 1 || z == 1) {
        cout << h << endl;
    } else {
        for (int i = 0; i < x; i++) {
            tmp.idx = (i + y) % x;
            tmp.val = y;
            e[i].push_back(tmp);
            tmp.idx = (i + z) % x;
            tmp.val = z;
            e[i].push_back(tmp);
        }

        memset(dis, INF, sizeof(dis));

        q.push(1);
        flag[1] = true;
        dis[1] = 1;
        while(!q.empty()) {
            flag[q.front()] = false;
            for (int i = 0; i < e[q.front()].size(); i++) {
                if (dis[e[q.front()][i].idx] > dis[q.front()] + e[q.front()][i].val) {
                    dis[e[q.front()][i].idx] = dis[q.front()] + e[q.front()][i].val;
                    if (!flag[e[q.front()][i].idx]) {
                        q.push(e[q.front()][i].idx);
                        flag[e[q.front()][i].idx] = true;
                    }
                }
            }

            q.pop();
        }

        long long result = 0;
        for (int i = 0; i < x; i++) {
            if (dis[i] <= h) {
                result += (h - dis[i]) / x + 1;
            }
        }

        cout << result << endl;
    }
	
	return 0;
}