/*Sum of Square Numbers 
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

可以看成是在元素为 0~target 的有序数组中查找两个数，使得这两个数的平方和为 target，如果能找到，则返回 true，表示 target 是两个整数的平方和。
可以使用双指针得到两个数，使其平方和为 target。关键是右指针的初始化，实现剪枝，从而降低时间复杂度。设右指针为 x，左指针固定为 0，为了使
02 + x2 的值尽可能接近 target，我们可以将 x 取为 sqrt(target)。*/

bool judgeSquareSum(int c){
    long a=0;
    long b=sqrt(c);
    while(a<=b){
        if(a*a+b*b==c){
            return true;
        }
        else if(a*a+b*b<c){
            a++;
        }
        else{
            b--;
        }
    }
    return false;
}
