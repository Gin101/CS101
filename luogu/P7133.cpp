#include <iostream>
#include <queue>
#include <cstdio>

#define ull __int128
#define Fraction pair<ull, ull>

using namespace std;

const int MAXN = 100020, MAXM = 500030;

struct Edge {
	int to, next;
} edge[MAXM];
int head[MAXN], tot;

int n, m;
int in[MAXN], out[MAXN];
Fraction val[MAXN];
vector<int> ansl;

void addedge(int u, int v) {
	edge[++tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot;
}

ull gcd(ull a, ull b) {
	return b ? gcd(b, a % b) : a;
}

Fraction addition(Fraction a, Fraction b) {
	if (!a.second || !b.second) {
		if (a.second) {
			ull g = gcd(a.first, a.second);
			return make_pair(a.first / g, a.second / g);
		} else {
			ull g = gcd(b.first, b.second);
			return make_pair(b.first / g, b.second / g);
		}
	}
	
	ull p = a.first * b.second + b.first * a.second, q = a.second * b.second;
	ull g = gcd(p, q);
	
	return make_pair(p / g, q / g);
}

void toposort() {
	queue<int> Q;
	
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) {
			Q.push(i);
			val[i] = make_pair(1, 1);
		}
	
	while (Q.size()) {
		int u = Q.front(); Q.pop();
		
		for (int i = head[u]; i; i = edge[i].next) {
			int v = edge[i].to;
			
			val[v] = addition(val[v], make_pair(val[u].first, val[u].second * out[u]));
			in[v]--;
			
			if (in[v] == 0)
				Q.push(v);
		}
	}
}

void print(ull n) {
	if (n > 9) print(n / 10);
	putchar(n % 10 + 48);
}

int main() {
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		int d, a;
		cin >> d;
		
		if (d == 0) {
			ansl.push_back(i);
		}
		
		while (d--) {
			cin >> a;
			addedge(i, a);
			in[a]++; out[i]++;
		}
	}
	
	toposort();
	
	for (int i = 0; i < ansl.size(); i++) {
		print(val[ansl[i]].first);
		putchar(' ');
		print(val[ansl[i]].second);
		puts("");
	}
	
	return 0;
}