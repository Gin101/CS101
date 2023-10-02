#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e6 + 1;
int a[maxN] = {0};
int f[maxN] = {0};
int find(int x) {
    if (f[x] == x) {
        
    }
}

int main()
{


    return 0;
}
#define rep(i,l,r)for(int i=(l);i<=(r);i++)
using namespace std;const int N=1000010;int n,k,sm,a[N],L[N],fa[N],v[N];int get(int x){return x==fa[x] ? x : fa[x]=get(fa[x]);}int main(){scanf("%d%d",&n,&k);int r=1;rep(i,1,n)scanf("%d",&a[i]);rep(i,1,n){L[i]=i-1;while(L[i]&&a[L[i]]<a[i])L[i]=L[L[i]];}rep(i,1,n){fa[i]=i;int l=get(L[i]+1);if(l<=r)sm++;v[l]++;v[i+1]--;if(l)fa[l]=l-1;if(i>=k)printf("%d ",sm),sm+=v[++r];}return 0;}