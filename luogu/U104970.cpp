/*
题目描述
把n分解为若干个大于11的正整数的乘积称作因数分解，例如12=2×2×3是12的一组因数分解方法。因数分解中可以出现相同的因数，也可以分解为整数自己。

我们认为如果两种分解方式得到同一组因数，则是同一种分解方式，例如12=2×2×3、12=2×3×2和12=3×2×2是同一种分解方式，我们取因数从小到大排序后的写法，即12=2×2×3，代表这种分解方式。

对一个整数n，将n的所有分解方式按如下顺序排序：若两种分解方式中前k-1个因数对应相同，则第k个因数更小的在前。例如12共有4种分解方法，排序如下：

12=2×2×3

12=2×6

12=3×4

12=12

于是12的第2种分解方法为12=2×6。

给出n,m，输出n的第m种因数分解方式。

输入格式
1行, 两个正整数n,m,用空格分隔。

输出格式
1行, 若干个正整数, 用单个空格分隔, 依次表示n的第m种因数分解方式中从小到大的每个因数。
*/
#include <iostream>
#include <stdio.h>

using namespace std;

const int maxNZYS = 13;
int number[maxNZYS] = {0};
int m = 0;
int cnt = 0;

void dfs(int start, int n, int idx) {
    if (n == 1) {
        cnt++;

        // cout << "cnt: " << cnt << endl;
        // for (int i = 0; i <= idx; i++) {
        //     cout << number[i] << ' ';
        // }
        // cout << endl;

        if (cnt == m) {
            for (int i = 0; i < idx; i++) {
                cout << number[i] << ' ';
            }
            cout << endl;
        }

        return;
    }

    for (int i = start; i <= n; i++) {
        if (n % i == 0) {
            number[idx] = i;

            dfs(i, n / i, idx + 1);
        }
    }
}

int main()
{
    int n = 0;
    cin >> n >> m;

    dfs(2, n, 0);

    return 0;
}