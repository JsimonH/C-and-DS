/*你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
name.length <= 1000
typed.length <= 1000
name 和 typed 的字符都是小写字母。*/

int calculateSame(char *str,int *count){
    char pre=str[0];
    count[0]=1;
    int cur=0;
    for(int i=1;i<strlen(str);i++){
        if(str[i]==pre){
            count[cur]++;
        }
        else{
            pre=str[i];
            cur++;
            count[cur]=1;
        }
    }
    return cur+1;
}
bool comparenessNameTyped(int *name,int *typed,int len){
    for(int i=0;i<len;i++){
        if(name[i]>typed[i])
            return false;
    }
    return true;
}
bool isLongPressedName(char * name, char * typed){
    int *countName=(int *)malloc(sizeof(int)*strlen(name));
    int *counttyped=(int *)malloc(sizeof(int)*strlen(typed));
    memset(countName,0,sizeof(int)*strlen(name));
    memset(counttyped,0,sizeof(int)*strlen(typed));
    int lenTyped=calculateSame(typed,counttyped);
    int lenNam=calculateSame(name,countName);
    if(lenTyped!=lenNam)
        return false;
    else{
        return comparenessNameTyped(countName,counttyped,lenTyped);
    }
}
