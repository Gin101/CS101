#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 2e5;
const int maxM = 2e5;
struct Road {
    int a = 0;
    int b = 0;
} road[maxM];
vector<int> city[maxN];

bool cmp(Road x, Road y) {
    return x.a < y.a;
}
bool cmp2(Road x, Road y) {
    return x.b < y.b;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> road[i].a >> road[i].b;
    }
    for (int i = m; i < 2 * m; i++) {
        road[i].a = road[i - m].b;
        road[i].b = road[i - m].a;
    }

    sort(road, road + 2 * m, cmp);
    sort(road, road + 2 * m, cmp2);
    for (int i = 0; i < 2 * m; i++) {
        city[road[i].a - 1].push_back(road[i].b);
    }

    for (int i = 0; i < n; i++) {
        cout << city[i].size() << ' ';
        for (int j = 0; j < city[i].size(); j++) {
            cout << city[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}