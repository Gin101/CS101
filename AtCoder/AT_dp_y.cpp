#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e6;
const int MOD = 1e9 + 7;
long long dp[maxN] = {0};
long long fc[maxN] = {0};
long long iv[maxN] = {0};
pair<int, long long> pa[maxN];

long long ope(int x, int y) {
    return fc[x] * iv[y] % MOD * iv[x - y] % MOD;
}
int main()
{
    int w = 0;
    int s = 0;
    int n = 0;
    cin >> w >> s >> n;

    for (int i = 1; i <= n; i++) {
        cin >> pa[i].first >> pa[i].second;
    }

    fc[0] = 1;
    iv[0] = 1;
    for (int i = 1; i <= 2e5; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;

        long long num = fc[i];
        int tmp = MOD - 2;
        long long result = 1;
        while (tmp) {
            if (tmp & 1) {
                result = result * num % MOD;
            }
            num = num * num % MOD;
            tmp /= 2;
        }
        iv[i] = result;
    }

    pa[++n] = {w, s};
    sort(pa + 1, pa + n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = ope(pa[i].first + pa[i].second - 2, pa[i].second - 1);
        for (int j = 1; i <= i - 1; j++) {
            if (pa[j].first <= pa[i].first && pa[j].second <= pa[i].second) {
                dp[i] = (dp[i] + MOD - dp[j] * ope(pa[i].first - pa[j].first + pa[i].second - pa[j].second, pa[i].second - pa[j].second) % MOD) % MOD;
            }
        }
    }
	
    cout << dp[n] << endl;

    return 0;
} 
/*
#include<iostream>
#include <algorithm>
using namespace std;
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define pii pair<int,ll>
#define fi first
#define se second
#define ll long long
const int N=214514;
const int md=1e9+7;
pii q[N];
ll f[N],fc[N],iv[N];
int w,s,n;
ll msk(ll a,int b,ll k=1){while(b){if(b&1)k=k*a%md;a=a*a%md;b>>=1;};return k;}
ll C(int x,int y){return fc[x]*iv[y]%md*iv[x-y]%md;}
int main(){fc[0]=iv[0]=1;
	scanf("%d%d%d",&w,&s,&n);
	rep(i,1,n)scanf("%d%d",&q[i].fi,&q[i].se);
	rep(i,1,2e5)fc[i]=(fc[i-1]*i)%md,iv[i]=msk(fc[i],md-2);
	q[++n]={w,s};sort(q+1,q+n+1);
	rep(i,1,n){f[i]=C(q[i].fi+q[i].se-2,q[i].se-1);
		rep(j,1,i-1)if(q[j].fi<=q[i].fi&&q[j].se<=q[i].se){
			f[i]=(f[i]+md-f[j]*C(q[i].fi-q[j].fi+q[i].se-q[j].se,q[i].se-q[j].se)%md)%md;
		}
	}printf("%lld",f[n]);
} 
*/