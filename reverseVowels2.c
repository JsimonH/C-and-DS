/*Reverse Vowels of a String
Given s = "leetcode", return "leotcede".
使用双指针，一个指针从头向尾遍历，一个指针从尾到头遍历，当两个指针都遍历到元音字符时，交换这两个元音字符。*/

int vowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    else
        return 0;
}

char * reverseVowels(char * s){
    int i = 0, j = strlen(s) - 1;
    char t;
    while(i < j){
        while(i < j && !vowel(s[i]))
            i++;
        while(i < j && !vowel(s[j]))
            j--;
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
    return s;
}
