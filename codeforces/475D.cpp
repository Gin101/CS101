#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int n = 0;
const int maxN  = 1e5 + 1;
map<int, long long> result;
int a[maxN] = {0};
int que[maxN][30] = {{0}};
int q[maxN * 3] = {0};
int gcd(int a,int b) {
	if (!b) {
        return a;
    }
	return gcd(b, a % b);
} 
int query(int x, int y) {
	int k = log2(y - x + 1);
	return gcd(que[x][k], que[y - (1 << k) + 1][k]);
}
int find(int l,int l2, int x) {
	int r = n;
    int sum = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (query(l, mid) == x) {
            sum = mid;
            l2 = mid + 1;
        } else {
            r = mid - 1;
        }
	}
	return sum;
}
void ope(int l) {
	int r = l;
    int last = 0;
    int x = a[l];
	while (true) {
		last = r;
		r = find(l, r, x);
		if (result[x]) {
            result[x] += (r - last + 1);
        }
		if (r == n) {
            return;
        }    
		r++; 
		x = query(l, r);
	}
}
int main() 
{
    int m = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        que[i][0] = a[i];
    }    

	for (int i = 1; i <= 20; i++) {
        for (int j = 1; j + (1 << (i - 1)) <= n; j++) {
            que[j][i] = gcd(que[j][i - 1], que[j + (1 << (i - 1))][i - 1]);
        }
    }

	scanf("%d", &m);
	for (int i = 1; i <= m; i ++ ) {
        scanf("%d", &q[i]);
        result[q[i]] = 1;
    } 

	for (int i = 1; i <= n; i++) {
        ope(i);
    }

	for (int i = 1; i <= m; i++) {
		printf("%lld\n",result[q[i]] - 1);
	} 

	return 0;
} 