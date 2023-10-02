#include <stdio.h>
#include <vector>

using namespace std;

const int maxN = 200001;
struct Node {
    int l = 0;
    int r = 0;
    int pre = 0;
    int _next = 0;
    int tag = 0;
} p[maxN];
int idx = 0;
int l2 = 1;
int r2 = 0;
int head = 1;
int f[maxN] = {0};
vector<vector<int> > result;

int main() 
{
    int n = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
        if (f[i] == f[l2]) {
            r2 = i;
        } else {
            p[++idx].l = l2;
            p[idx].r = r2;
            p[idx].pre = idx - 1;
            p[idx]._next = idx + 1;
            p[idx].tag = f[l2];
            l2 = i;
            r2 = l2;
        }
    }

    p[++idx].l = l2;
    p[idx].r = r2;
    p[idx].pre = idx - 1;
    p[idx]._next = idx + 1;
    p[idx].tag = f[l2];
    l2 = n;
    r2 = l2; 
    p[idx]._next = 0;
    bool flag = true;
    while (flag) {
        int tmp = p[head].tag;
        flag = false;
        vector<int> v;

        int idx2 = head;
        while (idx2 != 0) {
            if (tmp != p[idx2].tag) {
                idx2 = p[idx2]._next;
                continue;
            }

            flag = true;
            v.push_back(p[idx2].l); 
            p[idx2].l++;
            tmp ^= 1;
            if (p[idx2].l > p[idx2].r) {
                if (idx2 == head) {
                    head = p[idx2]._next;
                }
                p[p[idx2].pre]._next = p[idx2]._next;
                p[p[idx2]._next].pre = p[idx2].pre;
            } 

            idx = p[idx2]._next;
        }
        result.push_back(v);
    }

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("%d ", result[i][j]);
        }
        
        printf("\n");
    }

    return 0;
}