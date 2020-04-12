/*第一个只出现一次的字符

在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "

*/


char firstUniqChar(char* s){
    if (s == NULL) 
    {
        return ' ';
    }
    
    int* arr = (int *)malloc(sizeof(int) * 26);
    memset(arr, 0, sizeof(int) * 26);

    for (int i = 0; i < strlen(s); i++) 
    {
        arr[s[i] - 'a']++;
    }

    for (int i = 0; i < strlen(s); i++) 
    {
        if (arr[s[i] - 'a'] == 1) 
        {
            return s[i];
        }
    }
    return ' '; 
}
