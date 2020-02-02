/*给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。将空字符串定义为有效的回文串。*/

bool IsLetterFunc(char *ch) {
    if (*ch <= 'Z' && *ch >= 'A') {
        return true;
    }
    if (*ch <= 'z' && *ch >= 'a') {
        *ch = *ch - 'a' + 'A';
        return true;
    }
    return false;
}

bool IsDataFunc(char *ch) {
    return (*ch <= '9' && *ch >= '0');
}

bool IsCharFunc(char *ch) {
    return IsLetterFunc(ch) || IsDataFunc(ch);
}
bool isPalindrome(char * s){
    char *begin = NULL;
    char *end = NULL;
    begin = s;
    end = begin + (strlen(s) - 1);
    while (begin <= end) {
        if (!IsCharFunc(begin)) {
            begin++;
            continue;
        }
        if (!IsCharFunc(end)) {
            end--;
            continue;
        }
        if (*begin == *end) {
            begin++;
            end--;
            continue;
        }
        return false;
    }
    return true;
}
