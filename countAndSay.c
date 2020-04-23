/*Count and Say
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which 
means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" 
and "11" which is "1211".
*/

char * countAndSay(int n){
    char *res = (char*)malloc(sizeof(char) * 5000);
    char *tmp = (char*)malloc(sizeof(char) * 5000);
    res[0] = '1'; res[1] = '\0';     // res 初始化为 "1"
    int len = 1;                     // len 为 res 的有效长度
    while (--n) {
        int i = 0, j = 0;
        while(i < len) {             // 对 res 的每位字符 c 进行报数
            int count = 1;
            char c = res[i++];
            while (i < len && res[i] == c)    // 计算本轮报数结果，即本轮有几个 c
                i++,count++;
            tmp[j++] = count + '0';           // 将报数结果存入 tmp
            tmp[j++] = c;
        }
        tmp[j] = '\0';
        strcpy(res, tmp);                     // 将 tmp 复制到 res，并更新 res 长度
        len = j;
    }
    return res;
}
