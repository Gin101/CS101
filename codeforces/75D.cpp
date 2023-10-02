#include <iostream>

using namespace std;

const int maxN = 51;
long long s[maxN] = {0};
long long v[maxN] = {0};
long long w[maxN] = {0};
long long q[maxN] = {0};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int l = 0;
        cin >> l;

        w[i] = -1005;
        q[i] = -1005;
        for (int j = 0; j < l; j++) {
            int num = 0;
            cin >> num;

            s[i] += num;
            q[i] = max(q[i], s[i] - v[i]);
            v[i] = min(v[i], s[i]);
            w[i] = max(w[i], s[i]);
        }
    }
	
    long long result = -1005;
    long long sum = 0;
    long long tmp = 0;
    for (int i = 0; i < m; i++) {
        int num = 0;
        cin >> num;

        result = max(max(result, 1ll * q[num]), sum + w[num] - tmp);
        tmp = min(tmp, sum + v[num]);
        sum += s[num];
    }
	
    cout << result << endl;

	return 0;
}
