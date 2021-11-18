#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int maxN = 100001;
const int INF = 0x3f3f3f3f;
int a[maxN] = {0};
int b[maxN] = {0};
int dp[maxN] = {0};
int mp[maxN] = {0};// map

int main() 
{
	int n = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
        mp[a[i]] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

    memset(dp, INF, sizeof(dp));
    dp[0] = 0;

    int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (mp[b[i]] > dp[idx]) {
            dp[++idx] = mp[b[i]];
        } else  {
            int l = 0;
            int r = idx;
            while (l < r) {	
                int m = (l + r) / 2;
                if (dp[m] > mp[b[i]]) {
                    r = m;
                } else {
                    l = m + 1;
                } 
            }
            dp[l] = min(mp[b[i]], dp[l]);
     	}
	}
	
	cout << idx << endl;
	
    return 0;
}
/*
最长公共子序列是按位向后比对的，所以a序列每个元素在b序列中的位置如果递增，就说明b中的这个数在a中的这个数整体位置偏后
*/