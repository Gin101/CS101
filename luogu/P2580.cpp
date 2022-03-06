#include <iostream>
#include <string>

using namespace std;

const int maxN = 1e4 + 1;
int box[maxN][26] = {0};
int result[maxN] = {0};

int main() 
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int cnt = 1;
        int idx = 1;
        for (int j = 0; j < s.size(); j++) {
            if (!box[idx][s[j] - 'a']) {
                box[idx][s[j] - 'a'] = ++cnt;
            }
            idx = box[idx][s[j] - 'a'];  
        }
        result[idx] = 1; 
    }

    int m = 0;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        int idx = 1;
        for (int j = 0; j < s.size(); j++) {
            idx = box[idx][s[j] - 'a'];
            if (!idx) {
                break;  
            }
        }

        if (result[idx] == 1) {
            result[idx] = 2; 
            cout << "OK" << endl;
        } else if (result[idx] == 2) {
            cout << "REPEAT" << endl;
        } else {
            cout << "WRONG" << endl;
        }
    }

    return 0;
}
/*
int main() {  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    int u = 1;
    for (int j = 1; s[j]; ++j) {
      int c = s[j] - 'a';
      if (!ch[u][c])
        ch[u][c] =
            ++tot;  // 如果这个节点的子节点中没有这个字符，添加上并将该字符的节点号记录为++tot
      u = ch[u][c];  // 往更深一层搜索
    }
    tag[u] = 1;  // 最后一个字符为节点 u 的名字未被访问到记录为 1
  }

  scanf("%d", &m);

  while (m--) {
    scanf("%s", s + 1);
    int u = 1;
    for (int j = 1; s[j]; ++j) {
      int c = s[j] - 'a';
      u = ch[u][c];
      if (!u) break;  // 不存在对应字符的出边说明名字不存在
    }
    if (tag[u] == 1) {
      tag[u] = 2;  // 最后一个字符为节点 u 的名字已经被访问
      puts("OK");
    } else if (tag[u] == 2)  //已经被访问，重复访问
      puts("REPEAT");
    else
      puts("WRONG");
  }

  return 0;
}
*/