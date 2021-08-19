/*
题目描述
你将得到一个整数n,请列出把整数n划分为若干个正整数的每一种方法,这些正整数必须选自数组a.

数组a中可能有重复元素,每个可以选择一次,例如对n=6,a={1,1,2,2,3,4},n=1+1+2+2是可以的,数组a中有2个1和2个2可供选择;n=2+2+2则不正确,因为数组a中没有3个2.

输入格式
输入共2行;

第1行，2个正整数n,k,k为数组a的元素个数;

第2行，k个用空格隔开的正整数a_0,a_1,a_n-1为数组a中的元素;

输出格式
输出为若干行:

每行为用空格隔开的若干个正整数,为一种n划分为若干个正整数的方法,每组数按在a中的下标从小到大输出.

若两种方法中前k−1个数在a中的下标相同,则第k个数的下标更小的在前.

如果两种方法选取的数在a中的下标不全相同,则视为不同的方法. 例如对n=6,a={1,1,2,2,3,4},选取a的0,2,4或0,3,4号元素都会得到n=1+2+3,两者都要在合适的位置分别输出.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

int n = 0;
int k = 0;
const int maxK = 20;
int number[maxK];
int result[maxK] = {0};

void dfs(int idx, int sum, int cnt) {
    if (sum == n){
        for (int i = 0; i < cnt; i++) {
            cout << result[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < k; i++) {
        result[cnt] = number[i];
        // printf("sum: %d, result[%d]: %d\n", sum, i, result[i]);
        dfs(i + 1, sum + number[i], cnt + 1);
    }
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> number[i];
    }

    dfs(0, 0, 0);

    return 0;
}