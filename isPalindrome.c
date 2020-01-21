/*判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

example:
input: 121
output: true

input: -121
output: false
explain: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。*/

bool isPalindrome(int x){
long y = 0;
int tmp = x;
if (x < 0) 
 {
   return false;
 }
while (tmp != 0)
 {
   int n = tmp % 10;
   tmp /= 10;
   y = y * 10 + n;
 }
return x==y;
}
