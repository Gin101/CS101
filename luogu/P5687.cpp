#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 3e5 + 1;
int a[maxN] = {0};
int b[maxN] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    long long result = 1ll * a[1] * (m - 1) + 1ll * b[1] * (n - 1);
    int sum = n + m - 2;
    int idx = 2;
    int idx2 = 2;
    int l = 1;
    int h = 1;
    while (true) {
        if (a[idx] < b[idx2]) {
            result += (1ll * a[idx++] * (m - h));
            l++;
            sum += (m - h);
        } else {
            result += (1ll * b[idx2++] * (n - l));
            h++;
            sum += (n - l);
        }
        if (sum == (n * m - 1)) {
            break;
        }
    }
	
    cout << result << endl;

	return 0;
}