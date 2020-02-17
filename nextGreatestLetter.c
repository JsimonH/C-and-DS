/*Find Smallest Letter Greater Than Target
给定一个只包含小写字母的有序数组letters 和一个目标字母 target，寻找有序数组里面比目标字母大的最小字母。
数组里字母的顺序是循环的。举个例子，如果目标字母target = 'z' 并且有序数组为 letters = ['a', 'b']，则答案返回 'a'。
Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c
*/

char nextGreatestLetter(char* letters, int lettersSize, char target){
int left,right,mid;
if(target>=letters[lettersSize-1] || target<letters[0])
{
   return letters[0];
}
left=0;
right=lettersSize;
while(left<right)
 {
   mid=left+(right-left+1)/2;
   if(target<letters[mid])
   {
     right=mid-1;
   }
   else
   {
     left=mid;
   }
 }
    return letters[left+1];
} 
