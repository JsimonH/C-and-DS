#include <iostream>
using namespace std;
#define MAXPROCESS 50                        //最大进程数
#define MAXRESOURCE 100                      //最大资源数
int AVAILABLE[MAXRESOURCE];                  //可用资源数组
int MAX[MAXPROCESS][MAXRESOURCE];            //最大需求矩阵
int ALLOCATION[MAXPROCESS][MAXRESOURCE];     //分配矩阵
int NEED[MAXPROCESS][MAXRESOURCE];           //需求矩阵
int REQUEST[MAXPROCESS][MAXRESOURCE];        //进程需要资源数
bool FINISH[MAXPROCESS];                     //系统是否有足够的资源分配给进程
int p[MAXPROCESS];                           //记录序列
int m, n;                                    //m个进程,n个资源
void Init();
void Menu();
bool Safe();
void Bank();
void showdata(int, int);
