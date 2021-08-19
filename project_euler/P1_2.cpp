#include <cstdio>

using namespace std;

int main ()
{
    /*
    He is using a clever improvisation of the formulae for arithmetic progressions. For example, to find the sum of the terms 3,6,9,12,..., you would use (n/2)(a+l), where n is the number of terms, a is the first term, and l is the last term. But to find the last term requires a bit of work. The nth term is given by a+(n-1)d, where d is the common difference. So we need to solve 3+3(n-1)=1000, giving 3(n-1)=997, and n=997/3+1=333.333... However, n must be integer, so int(333.333...)=333, and checking, 3+3(333-1)=999; this is the last term before 1000.

    In general, a+(n-1)d=x, gives n=int((x-a)/d+1).

    But for this problem we can improve even further, as a=d we get n=int(x/d-d/d+1)=int(x/d).

    The nth (last) term, l=a+(n-1)d=d+(int(x/d)-1)*d=d*int(x/d).

    Combining this to find the sum, S=(n/2)(a+l)=(int(x/d)/2)*(d+d*int(x/d)).

    Simplifying, S=d*int(x/d)*(1+int(x/d))/2.

    As the problem asks for the sum of multiples of 3 and 5 we find the sum of each series, but as 3,6,9,... and 5,10,15,... have multiples of 15 in common, we need to subtract the series for 15,30,45,...

    However, caution is needed. The problem states below then 1000, so we must use 999 in the formula (otherwise it would include 1000 in the sum, as a multiple of 5):

    T = 3*int(999/3)*(1+int(999/3))/2 + 5*int(999/5)*(1+int(999/5))/2 - 15*int(999/15)*(1+int(999/15))/2

    Therefore, T = 3*333*(1+333)/2 + 5*199*(1+199)/2 - 15*66*(1+66)/2 = 233168.
    */

    /*
    Exactly! This was another one that I solved without code, also.

    First of all, stop thinking on the number 1000 and turn your attention to the number 990 instead. If you solve the problem for 990 you just have to add 993, 995, 996 & 999 to it for the final answer. This sum is 
    (a)=3983
    Count all the #s divisible by 3: From 3... to 990 there are 330 terms. The sum is 330(990+3)/2    
    (b)=163845 
    Count all the #s divisible by 5: From 5... to 990 there are 198 terms. The sum is 198(990+5)/2    
    (c)=98505

    Now, the GCD (greatest common divisor) of 3 & 5 is 1 so the LCM (least common multiple) should be 3x5 15.
    This means every number that divides by 15 was counted twice and it should be done only once. Because of this, you have an extra set of numbers started with 15 all the way to 990 that has to be removed from (b)&(c).
    Then, from 15... to 990 there are 66 terms and the sum is 66(990+15)/2    
    (d)=33165

    The answer for the problem is: (a)+(b)+(c)-(d) = 233168

    Simple but very fun problem.
    */
}