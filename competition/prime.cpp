#include<bits/stdc++.h>
#define forO(var, from, to) for(int var = from; var <= (to); ++var)
#define forR(var, from, to) for(int var = from; var >= (to); --var)
using ll = long long;
using std::cin;
using std::cout;
const int SQRT = 5500;
const int N = 3e7 + 10;
int a[N], cnt;
ll primes[N];
int ansPrime[N], ansPower[N];
bool notPrime[N];
const int MaxInput = 1000000;
char buf[MaxInput], *fs, *ft;
#define inchar() (fs == ft && (ft = (fs = buf) + fb -> sgetn(buf, MaxInput), fs == ft) ? EOF : *fs++)
inline void read(int & x) {
	static std::streambuf *fb = std::cin.rdbuf();
	x = 0;
	char ch = inchar();
	while(!isdigit(ch)) ch = inchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = inchar();
}
inline void write(int x){
     char F[200];
     int tmp=x>0?x:-x;
     int cnt2=0;
    while(tmp>0){
        F[cnt2++]=tmp%10+'0';
        tmp/=10;
    }
    while(cnt2>0){
        putchar(F[--cnt2]);
    }
}
#undef inchar
constexpr void init() {
	forO(i, 2, N - 5) {
		if(!notPrime[i]) {
			primes[++cnt] = i;
			ansPrime[i] = i;
			ansPower[i] = 1;
		}	
		forO(j, 1, cnt) {
			ll cur = i * primes[j];
			if(i * primes[j] > N - 5) break;
			notPrime[cur] = true;
			ansPrime[cur] = ansPrime[i] + primes[j];
			ansPower[cur] = ansPower[i] + 1;
			if(i % primes[j] == 0) {
				ansPrime[cur] -= primes[j];
				break;
			}
		}	
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int T; read(T);
	while(T--) {
		int n; read(n);
        write(ansPrime[n] ^ ansPower[n]);
        cout << endl;
	}
	return 0;
}