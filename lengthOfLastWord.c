/*给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。

如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指仅由字母组成、不包含任何空格的 最大子字符串。*/

int lengthOfLastWord(char * s){
size_t length = strlen(s);
    //处理特殊情况
    if(length==0) return 0;

    //初始化
    int result = 0;
    bool is_reverse_empty=true;
    
    //倒数
    for(int i=length-1;i>=0;i--){
        //倒数如果是空格
        if(is_reverse_empty){
            //如果不是空格，bool置false，同时计数+1
            if(s[i]!=' ') {
                is_reverse_empty=false;
                result++;
            }
        }
        //已经不是空格了，正常计数直到遇到空格
        else{
            if(s[i]!= ' ') result++;
            else break;
        }
    }
    return result;
}
