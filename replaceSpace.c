/* 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
输入：s = "We are happy."
输出："We%20are%20happy."
*/
 
char* replaceSpace(char* s){
    char* c = s;
    char *s1 = (char*)malloc(10000*sizeof(char));
    int index = 0;
    while(*c)
    {
        if(*c == ' ') 
        {
            s1[index++] = '%';
            s1[index++] = '2';
            s1[index++] = '0';
        } 
        else 
        {
            s1[index++] = *c;
        }
        c++;
    }
    s1[index] = NULL;
    return s1;
}
