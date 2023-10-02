#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

const int maxN = 3e5 + 1;
const long long INF = 1e18;
vector<vector<vector<long long> > > e(maxN);
long long dis[maxN] = {0};
set<vector<long long> > se;
vector<long long> tmp;
vector<long long> result;
long long num[maxN] = {0};
int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        long long w = 0;
        cin >> x >> y >> w;

        e[x].push_back({y, w, i + 1});
        e[y].push_back({x, w, i + 1});
    }

    se.insert({0, 1});
    for (int i = 1; i < n; i++) {
        se.insert({INF, i + 1});
    }

    int cnt = 0;
    memset(dis, INF, sizeof(dis));
    dis[1] = 0;
	while(!se.empty() && cnt < k + 1) {
		cnt++;
        auto idx = se.begin();

        tmp.clear();
        tmp = *idx;

        result.push_back(num[tmp[1]]);
        se.erase(idx);
        for (int i = 0; i < e[tmp[1]].size(); i++) {
            if (dis[e[tmp[1]][i][0]] > dis[tmp[1]] + e[tmp[1]][i][1]) {
                se.erase({dis[e[tmp[1]][i][0]], e[tmp[1]][i][0]});
                dis[e[tmp[1]][i][0]] = dis[tmp[1]] + e[tmp[1]][i][1];   
                se.insert({dis[e[tmp[1]][i][0]], e[tmp[1]][i][0]});
                num[e[tmp[1]][i][0]] = e[tmp[1]][i][2];
            }
        }
	}

    cout << result.size() - 1 << endl;

    for (int i = 1; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}