/*
题目描述
现代数学的著名证明之一是 Georg Cantor 证明了有理数是可枚举的。他是用下面这一张表来证明这一命题的：

1/1 , 1/2 , 1/3 , 1/4, 1/5, …

2/1, 2/2 , 2/3, 2/4, …

3/1 , 3/2, 3/3, …

4/1, 4/2, …

5/1, …

…

我们以 Z 字形给上表的每一项编号。第一项是 1/1，然后是 1/2，2/1，3/1，2/2，…

输入格式
整数N (1 <= N <= 10 ^ 7)

输出格式
表中的第 N 项。
*/
#include <iostream>

using namespace std;

int find(bool shun, int n) {
    int count = 1;

    while (true) {
        if (shun) {
            for (int i = 1; i <= count; i++) {
                n -= 1;
                if (n == 0) {
                    return i;
                }
            }
        } else {
            for (int i = count; i > 0; i--) {
                n -= 1;
                if (n == 0) {
                    return i;
                }
            }
        }
        count++;
        shun = !shun;
    }

    return 1;
}

int main()
{
    int n = 0;
    cin >> n;
    int first = find(false, n);
    int second = find(true, n);

    cout << first << '/' << second << endl;

    return 0;
}