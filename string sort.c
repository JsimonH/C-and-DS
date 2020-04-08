/*输入一个长度不超过20的字符串，对所输入的字符串，按照ASCII码的大小从小到大进行排序，请输出排序后的结果
input: dcba
output: abcd

#include<stdio.h>
#include<string.h>

void sort(char a[],int n)
{
    int i,j,temp;
    for(j = 1; j < n; j++)
        for(i = 0; i < n-j; i++)
            if(a[i] > a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
}

int main()
{
    char a[20];
    scanf("%s", a);
    sort(a, strlen(a));
    printf("%s", a);
}
