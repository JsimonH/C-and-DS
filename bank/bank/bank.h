#include <iostream>
using namespace std;
#define MAXPROCESS 50                        //��������
#define MAXRESOURCE 100                      //�����Դ��
int AVAILABLE[MAXRESOURCE];                  //������Դ����
int MAX[MAXPROCESS][MAXRESOURCE];            //����������
int ALLOCATION[MAXPROCESS][MAXRESOURCE];     //�������
int NEED[MAXPROCESS][MAXRESOURCE];           //�������
int REQUEST[MAXPROCESS][MAXRESOURCE];        //������Ҫ��Դ��
bool FINISH[MAXPROCESS];                     //ϵͳ�Ƿ����㹻����Դ���������
int p[MAXPROCESS];                           //��¼����
int m, n;                                    //m������,n����Դ
void Init();
void Menu();
bool Safe();
void Bank();
void showdata(int, int);
