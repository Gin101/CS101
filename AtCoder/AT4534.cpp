#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long 
const int MAX=105,MAXN=1e5+5,P=1e9+7; 
int n,k;
int f[MAX][MAXN],a[MAX],l,r,pre[MAX][MAXN];
signed main()
{
    
	n=read(),k=read();
	for(register int i=1;i<=n;++i)a[i]=read();
	f[0][0]=pre[0][0]=1;
	for(register int i=1;i<=k;++i)pre[0][i]+=pre[0][i-1];
	for(register int i=1;i<=n;++i){
		for(register int j=0;j<=k;++j){
			l=max(0LL,j-a[i]),r=j;
			f[i][j]=(((f[i][j]+pre[i-1][r])%P-pre[i-1][l-1])+P)%P;
		}
		pre[i][0]=1;
		for(register int j=1;j<=k;++j)pre[i][j]=(pre[i][j-1]+f[i][j])%P; 
	}
	printf("%lld\n",f[n][k]);
	return 0;
}