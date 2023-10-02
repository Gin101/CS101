#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e5 + 2;
long long a[maxN] = {0};
long long b[maxN] = {0};
int main()
{
    long long l = 0;
    long long n = 0;
    long long n2 = 0;
    cin >> l >> n >> n2;

    for (int i = 1; i <= n + n2; i++) {
        cin >> a[i] >> b[i];
    }

    int idx = 1;
    int idx2 = n + 1;
    long long result = 0;
    for (int i = 1; i < n + n2; i++) {
        if (a[idx] == a[idx2]) {
            result += min(b[idx], b[idx2]);
        }
        if (b[idx] < b[idx2]) {
            b[idx2] -= b[idx];
            idx++;
        } else {
            b[idx] -= b[idx2];
            idx2++;
        }
    }
    
    cout << result << endl;
	
	return 0;
}