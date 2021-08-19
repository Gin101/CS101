/*
题目描述
在桌面上有一排硬币，共N枚，每一枚硬币均为正面朝上。现在要把所有的硬币翻转成反面朝上，规则是每次可翻转任意N-1枚硬币（正面向上的被翻转为反面向上，反之亦然）。求一个最短的操作序列（将每次翻转N-1枚硬币成为一次操作）。

输入格式
一个自然数N（N为不大于100的偶数）。

输出格式
第一行包含一个整数S，表示最少需要的操作次数。接下来的S行每行分别表示每次操作后桌上硬币的状态（一行包含N个整数（0或1），表示每个硬币的状态：0――正面向上，和1――反面向上，不允许出现多余空格）。

对于有多种操作方案的情况，则只需操作的字典序最小输出一种。

注：操作的字典序：对于一次操作，1表示翻转，0表示不反转。

但是需要你输出的是每一次操作完的状态，0表示正面朝上，1表示反面朝上。
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n = 0;
    cin >> n; 
    cout << n << endl;
    int number[n];
    int count = 0;
    memset(number, 0, sizeof(number));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == count) {
                cout << number[count];
            } else if (number[j] == 0) {
                number[j] = 1;
                cout << 1;
            } else {
                number[j] = 0;
                cout << 0;
            }
        }   
        cout << endl;
        count++;     
    }

    return 0;
}