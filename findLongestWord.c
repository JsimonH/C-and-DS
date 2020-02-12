/*    Longest Word in Dictionary through Deleting
删除 s 中的一些字符，使得它构成字符串列表 d 中的一个字符串，找出能构成的最长字符串。如果有多个相同长度的结果，返回字典序的最小字符串。
Input:s = "abpcplea", d = ["ale","apple","monkey","plea"]
Output: "apple"    */

int cmp(const void * a, const void * b)
{
    int val;
    char * c = *(char **)a;
    char * d = *(char **)b;
    val = strlen(d) - strlen(c);//长得排在前面
    if(val == 0)//长度相同的则进行字典序小的排序。
        return strcmp(c,d);
    return val;
}

char * findLongestWord(char * s, char ** d, int dSize){
    qsort(d, dSize, sizeof(char *), cmp);//进行行排序
    char* str; 
    int i, ri = 0;
    int b = 0, b1 = 0, len = 0, len1 = 0;
    len = strlen(s);
    for(i = 0; i < dSize; i++)
    {
        b = b1 = 0;
        len1 = strlen(d[i]);
        while(b < len && b1 < len1)
        {
            if(s[b] == d[i][b1])//进行匹配
                b1++;
            b++;
        }
        if(b1 == len1)//匹配成功则结束
        {
            str = (char *)malloc(sizeof(char) * (len1 + 2));
            strcpy(str,d[i]);
            return str;
        }
    }
    return "";
}
