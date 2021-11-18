#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 1e5;
struct Line {
    float x = 0;
    float y = 0;
    int z = 0;
} tmp[maxN];
int num[maxN] = {0};
vector<int> e[maxN];

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        num[i] = n - 1;
        cin >> tmp[i].x >> tmp[i].y >> tmp[i].z;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tmp[i].x / tmp[i].y == tmp[j].x / tmp[j].y) {
                num[i]--;
                num[j]--;
                e[i].push_back(j);
            }
        }
        sum += num[i];
    }

    sum /= 2;
    sort(num, num + n, greater<int> ());

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (sum > 0) {
            for (int j = 0; j < e[i].size(); j++) {
                num[e[i][j]]++;
            }
            sum -= num[i];
            sum += i;
            result++;
        }
    }

    cout << result << endl;

    return 0;
}