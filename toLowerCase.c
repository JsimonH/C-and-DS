/*实现函数 ToLowerCase() ，该函数接收一个字符串参数 str ，并将该字符串中的大写字母转换成小写字母，
之后返回新的字符串 。*/

char* toLowerCase(char* str)
{
    char *start = str;
     while(*str)
     {
         if(*str >= 'A' && *str <= 'Z') 
         {
         *str = *str + 32;
         str++;
         }
     }
    return start;
}
