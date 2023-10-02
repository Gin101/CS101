#include <iostream>

using namespace std;
using mint=atcoder::modint998244353;

const int maxN = 17;
int cnt[1 << maxN] = {0};
int dp[1 << maxN] = {0};
int result[maxN] = {0};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    memset(cnt, 1, sizeof(cnt));
    for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        
    }
	for(int i=0;i<M;i++)
	{
		int a,b;cin>>a>>b;
		a--,b--;
		for(int j=0;j<1<<N;j++)if(j>>a&1&&j>>b&1)cnt[j]*=2;
	}
	for(int i=1;i<1<<N;i+=2)
	{
		mint now=cnt[i];
		for(int j=i-1;j>=0;j--)
		{
			j&=i;
			now-=dp[j]*cnt[i^j];
		}
		dp[i]=now;
		for(int j=1;j<N;j++)if(i>>j&1)
		{
			ans[j]+=now*cnt[(1<<N)-1^i];
		}
	}
	for(int i=1;i<N;i++)cout<<ans[i].val()<<endl;
}
