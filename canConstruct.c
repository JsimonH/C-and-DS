/*给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。
如果可以构成，返回 true ；否则返回 false。
(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)
notice:
你可以假设两个字符串均只含有小写字母。
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true*/

int delete_s(char *mag, int i) {
    for(int j = i; mag[j] != '\0'; j++) 
        mag[j] = mag[j+1];
    return 0;
}

bool canConstruct(char * ransomNote, char * magazine){
    int ranlen = strlen(ransomNote);
    int maglen = strlen(magazine);
    if(ranlen > maglen) return false;
    for(int i = 0; ransomNote[i] != '\0'; i++) {
        int j, flag = 1;
        for(j = 0; magazine[j] != '\0'; j++) {
            if(ransomNote[i] == magazine[j]){
                flag = delete_s(magazine, j);
                break;
            }
        }
        if(flag == 1 && magazine[j] == '\0')
            return false;
    }
    return true;
}
