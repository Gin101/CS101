#include <iostream>
#include <algorithm>

using namespace std;

const int maxNK = 3e5;
struct Thing {
    int w = 0;
    long long v = 0;
} thing[maxNK];
long long c[maxNK] = {0};

bool cmp(Thing x, Thing y) {
    return x.v == y.v ? x.w > y.w : x.v > y.v;
}
bool flag[maxNK] = {false};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> thing[i].w >> thing[i].v;
    }
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }

    sort(thing, thing + n, cmp);
    sort(c, c + k);

    long long result = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (!flag[j] && thing[j].w <= c[i]) {
                result += thing[j].v;
                flag[j] = true;
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}