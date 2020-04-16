/*
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1

输入：n = 2
输出：1

输入：n = 5
输出：5
*/

int fib(int n){
    if(n == 0)
    {
        return 0;
    }
    else if(n==1 || n==2)
    {
        return 1;
    }
       
    int prev = 1,curr = 1,sum = 0;
    for(int i = 3; i <= n; i++)
    {
        sum = (prev + curr) % 1000000007;
        prev = curr;
        curr = sum;
    }
    return curr;
}
