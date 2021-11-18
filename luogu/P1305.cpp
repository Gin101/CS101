#include <iostream>

using namespace std;

const int maxN = 26;
int l[maxN] = {0};
int r[maxN] = {0};
bool flag[maxN] = {false};
bool flag2[maxN] = {false};

void dfs(int root) {
	if (root == -1) {
		return;
	} 
	
	cout << char(root + 'a');
	dfs(l[root]);
	dfs(r[root]);	
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char a;
        char b;
        char c;
        cin >> a >> b >> c;

        flag[a - 'a'] = true;
        if (b != '*') {
            flag2[b - 'a'] = true;
            l[a - 'a'] = b - 'a';
        } else {
            l[a - 'a'] = -1;
        }

        if (c != '*') {
            flag2[c - 'a'] = true;
            r[a - 'a'] = c - 'a';
        } else {
            r[a - 'a'] = -1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (flag[i] && !flag2[i]) {
            dfs(i);
            break;
        }
    }

    cout << endl;

    return 0;
}