#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxN = 3e5 + 1;
int box[maxN] = {0};
long long num[maxN] = {0};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int p = 0;
        cin >> p;

        box[p] = i;
    }

    for (int i = 1; i <= m; i++) {
        long long a = 0;
        long long b = 0;
        scanf("%d %d", &a, &b);

        a = box[a];
        b = box[b];
        if (a > b) {
            swap(a, b);
        }
        num[b] = max(num[b], a + 1);
    }

    long long result = 0;
    long long maxNum = 1;
    for (int i = 1; i <= n; i++) {
        maxNum = max(maxNum, num[i]);
        result += i - maxNum + 1;
    }
	
    cout << result << endl;
    
	return 0;
} 