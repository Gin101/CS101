#include <stdio.h>
#include <ctype.h>

using namespace std;

const int maxN = 5e6 + 1;
int f[maxN] = {0};
int result[maxN] = {0};
int deep[maxN] = {0};
int next[maxN] = {0};
int num[maxN] = {0};

inline int read() {
	int s = 0;
    char c = getchar();
	while (!isdigit(c)) {
        c = getchar();
    }

	while(isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    } 
    
	return s;
}

int find(int u) {
    return f[u] == u ? u : f[u] = find(f[u]);
}

void dfs(int u, int pre) {
    deep[u] = deep[pre] + 1;
    for (int i = num[u]; i; i = next[i]) {
        dfs(i, u);
        f[i] = u;
    }

    result[deep[u]] = result[deep[u]] ? find(result[deep[u]]) : u; 
}

int main()
{
    int n = read();
    int m = read();

    for (int i = 1; i <= n; i++) {
        int fa = read();

        f[i] = i;
        next[i] = num[fa];
        num[fa] = i;
    }

    dfs(1, 0);

    for (int i = 0; i < m; i++) {
        printf("%d\n", result[read()]);
    }

    return 0;
}