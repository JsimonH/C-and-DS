/*给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
example:
input："Test1ng-Leet=code-Q!"
output："Qedo1ct-eeLg=ntse-T!"*/

char * reverseOnlyLetters(char * S){
if(strlen(S) < 2)
        return S;
    int start = 0, end = strlen(S) - 1;
    while(start < end)
        if((S[start] < 'A' || S[start] > 'Z') && (S[start] < 'a' || S[start] > 'z'))
            start++;
        else if((S[end] < 'A' || S[end] > 'Z') && (S[end] < 'a' || S[end] > 'z'))
            end--;
        else
        {
            char c = S[start];
            S[start] = S[end];
            S[end] = c;
            start++;
            end--;
        }
    return S;
}
