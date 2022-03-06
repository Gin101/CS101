#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n = 0;
int h = 0;
const int maxN = 21;

struct Cow {
    int height = 0;
    int weight = 0;
    int endurance = 0;
} p[maxN];

bool cmp(Cow x, Cow y) {
    return x.weight + x.endurance > y.weight + y.endurance;
}

bool flag[maxN] = {false};
long long result = LONG_MIN;
void dfs(int idx, bool flag2) {
    flag[idx] = flag2;
    if (idx == n) {
        long long tmp = LONG_MAX;
        long long tmp2 = 0;
        for (int i = 1; i <= n; i++) {
            if (flag[i]) {
                tmp2 += p[i].height;
                long long sum = 0;

                for (int j = i + 1; j <= n; j++) {
                    sum += flag[j] ? p[j].weight : 0;
                }

                tmp = min(tmp, p[i].endurance - sum);
            }
        }

        if (tmp2 >= h) {
            result = max(result, tmp);
        } 
        
        return;
    }

    dfs(idx + 1, true);
    dfs(idx + 1, false);
}

int main()
{
    cin >> n >> h;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].height >> p[i].weight >> p[i].endurance;
    }

    sort(p + 1, p + n + 1, cmp);

    dfs(0, false);

    if (result < 0) {
        cout << "Mark is too tall" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}