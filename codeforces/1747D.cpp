#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

const int maxN = 2e5 + 1;
int a[maxN] = {0};
int ya[maxN] = {0};
int s[maxN] = {0};
int last[maxN] = {0};
unordered_map<int, int> mp[2]; 
int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ya[i] = a[i];
        ya[i] ^= ya[i - 1];

        if (!a[i]) {
            s[i] = s[i - 1] + 1;
        }
        last[i] = mp[i & 1][ya[i]];
        mp[i & 1][ya[i - 1]] = i;
    }

    for (int i = 0; i < q; i++) {
        int l = 0;
        int r = 0;
        scanf("%d %d", &l, &r);

        if (s[r] >= r - l + 1) {
            printf("0\n");
        } else if (ya[l - 1] ^ ya[r] || r - l < 2) {
            printf("-1\n");
        } else if (!((r - l) & 1) || !a[l] || !a[r]) {
            printf("1\n");
        } else if (last[r] > l) {
            printf("2\n");
        } else {
            printf("-1\n");
        }
    }
	
	return 0;
}