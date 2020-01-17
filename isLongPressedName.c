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
