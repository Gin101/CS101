#include <iostream>

using namespace std;
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define pii pair<int,ll>
#define fi first
#define se second
#define ll long long
#define mi ((l+r)>>1)
#define ls (i<<1)
#define rs (i<<1|1)
const int N=214514;
vector<pii>q[N];
ll tr[N*4],lz[N*4];int n,m;
void add(int s,int t,ll w,int i=1,int l=1,int r=n){
	if(s<=l&&r<=t){tr[i]+=w,lz[i]+=w;return;}
	if(s<=mi)add(s,t,w,ls,l,mi);
	if(t>mi)add(s,t,w,rs,mi+1,r);
	tr[i]=max(tr[ls],tr[rs])+lz[i];
}
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x = 0;
        int y
    }
	scanf("%d%d",&n,&m);int x,y,z;
	rep(i,1,m)scanf("%d%d%d",&x,&y,&z),q[y].push_back({x,z});
	rep(i,1,n){add(i,i,tr[1]);
		for(pii y:q[i])add(y.fi,i,y.se);
	}printf("%lld",max(tr[1],0ll));
}