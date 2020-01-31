/*给定两个二进制字符串，返回他们的和（用二进制表示）。
输入为非空字符串且只包含数字 1 和 0。*/


char* addBinary(char* a, char* b) {
    int i,j,temp,temp1,lenA,lenB,len;
    char *str;
    lenA = strlen(a);
    lenB = strlen(b);
    len  = lenA > lenB?lenA:lenB;
    str  = (char *)malloc( sizeof(char)*(len+2) ); 
    memset(str,0,(len+2)*sizeof(char));
    temp = 0;
    
    for(i = len; i>= 0 && lenA>0 && lenB>0;i--){
        *(str+i) = ( (*(a+lenA-1) - '0') + (*(b+lenB-1) - '0') + temp ) % 2 + '0';
        temp     = ( (*(a+lenA-1) - '0') + (*(b+lenB-1) - '0') + temp ) / 2;
        lenA--;
        lenB--;
    }
    if(lenA == 0){
        for(;lenB > 0;i--){
            *(str+i) = ( (*(b+lenB-1) - '0') + temp ) %2 + '0';
            temp     = ( (*(b+lenB-1) - '0') + temp ) /2;
            lenB--;
        }
    }
    else if(lenB == 0){
         for(;lenA > 0;i--){
            *(str+i) = ( (*(a+lenA-1) - '0') + temp ) %2 + '0';
            temp     = ( (*(a+lenA-1) - '0') + temp ) /2;
            lenA--;
        }
    }
    
    if(temp == 1){
        *(str + i) = temp + '0';
        return str + i;
    }
     return str + i + 1;
}
