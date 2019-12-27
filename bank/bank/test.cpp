#define _CRT_SECURE_NO_WARNINGS 1
#include"bank.h"

int main()
{
	int input;
	Init();
	do
	{
		Menu();
		cout << "请输入要执行的操作：\n"<<endl;
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Safe();
			break;
		case 2:
			Bank();
			break;
		case 0:
			cout<<"退出程序"<<endl;
			break;
		default:
			cout << "请输入正确选项：\n"<<endl;
			break;
		}
	}while(input);
	return 0;
}
void Menu()
{
	cout << "/***********************************/\n"<<endl;
	cout << "/******     1.安全性检测   *********/\n" << endl;
	cout << "/******     2.银行家算法   *********/\n" << endl;
	cout << "/******     0.退出         *********/\n" << endl;
	cout << "/***********************************/\n" << endl;
}

void Init()                //初始化算法
{
	int i, j;
	cout << "请输入进程的数目:";
	cin >> m;
	cout << "请输入资源的种类:";
	cin >> n;
	cout << "请输入每个进程最多所需的各资源数,按照" << m << "*" << n << "矩阵输入" << endl;
	for (i = 0; i<m; i++)
	for (j = 0; j<n; j++)
		cin >> MAX[i][j];
	cout << "请输入每个进程已分配的各资源数,也按照" << m << "*" << n << "矩阵输入" << endl;
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			cin >> ALLOCATION[i][j];
			NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
			if (NEED[i][j]<0)
			{
				cout << "您输入的第" << i + 1 << "个进程所拥有的第" << j + 1 << "个资源数错误,请重新输入:" << endl;
				j--;
				continue;
			}
		}
	}
	cout << "请输入各个资源现有的数目:" << endl;
	for (i = 0; i<n; i++)
	{
		cin >> AVAILABLE[i];
	}
}

void Bank()                //银行家算法
{
	int i, cusneed, flag = 0;
	char again;
	while (1)
	{
		showdata(n, m);
		cout << endl;
	input:
		cout << "请输入要申请资源的进程号(注:第1个进程号为0,依次类推)" << endl;
		cin >> cusneed;
		if (cusneed > m)
		{
			cout << "没有该进程，请重新输入" << endl;
			goto input;
		}
		cout << "请输入进程所请求的各资源的数量" << endl;
		for (i = 0; i<n; i++)
		{
			cin >> REQUEST[cusneed][i];
		}
		for (i = 0; i<n; i++)
		{
			if (REQUEST[cusneed][i]>NEED[cusneed][i])//如果用户选择的进程的第i个资源请求数＞该进程该资源所需的数量
			{
				cout << "您输入的请求数超过进程的需求量!请重新输入!" << endl;
				goto input;
			}
			if (REQUEST[cusneed][i]>AVAILABLE[i])//如果用户选择的进程的第i个资源请求数＞系统现有的第i个资源的数量
			{
				cout << "您输入的请求数超过系统有的资源数!请重新输入!" << endl;
				goto input;
			}
		}
		for (i = 0; i<n; i++)//如果请求合理，那么下面
		{
			AVAILABLE[i] -= REQUEST[cusneed][i];//系统可用资源减去申请了的
			ALLOCATION[cusneed][i] += REQUEST[cusneed][i];//进程被分配的资源加上已申请了的
			NEED[cusneed][i] -= REQUEST[cusneed][i];//进程还需要的资源减去已申请得到的
		}
		if (Safe())//AVAILABLE  ALLOCATION  NEED变动之后，是否会导致不安全
		{
			cout << "同意分配请求!" << endl;
		}
		else//不安全则复原
		{
			cout << "您的请求被拒绝!" << endl;
			for (i = 0; i<n; i++)
			{
				AVAILABLE[i] += REQUEST[cusneed][i];
				ALLOCATION[cusneed][i] -= REQUEST[cusneed][i];
				NEED[cusneed][i] += REQUEST[cusneed][i];
			}
		}
		for (i = 0; i<n; i++)
		{
			if (NEED[cusneed][i] == 0)//请求=需求
			{
				flag++;
			}
		}
		
		if (flag == n)//如果该进程各资源都已满足条件，则释放资源
		{
			for (i = 0; i<n; i++)
			{
				AVAILABLE[i] += ALLOCATION[cusneed][i];
				ALLOCATION[cusneed][i] = 0;
				NEED[cusneed][i] = 0;
			}
			cout << "进程" << cusneed << " 占有的资源被释放！" << endl;
			flag = 0;
		}
		for (i = 0; i<m; i++)//分配好了以后将进程的标识FINISH改成false
		{
			FINISH[i] = false;
		}
		showdata(n, m);
		cout << "您还想再次请求分配吗?是请按y/Y,否请按其它键" << endl;
		cin >> again;
		if (again == 'y' || again == 'Y')
		{
			continue;
		}
		break;
	}
}

bool Safe() //安全性算法
{
	int i, j, k, l = 0;
	int Work[MAXRESOURCE]; //工作数组
	for (i = 0; i < n; i++)
		Work[i] = AVAILABLE[i];
	for (i = 0; i < m; i++)
	{
		FINISH[i] = false;//FINISH记录每个进程是否安全
	}
	while (l<m)//正常的话，共执行m次
	{
		int init_index = l;//记录当前安全序列大小
		for (i = 0; i < m; i++)
		{
			if (FINISH[i] == true)//判断当前进程是否执行
			{
				continue;
			}
			for (j = 0; j < n; j++)//循环查找第i个进程需要的各个资源数 是否 超过系统现有的对应资源数
			{
				if (NEED[i][j] > Work[j])//第i个资源需要的第j个资源数>系统现有的第j个资源数
				{
					break;
				}
			}
			if (j == n)//如果第i个进程所需的各个资源数都没有超过系统现有的对应资源数  
			{
				FINISH[i] = true;//给该进程的FINISH标记为true  
				for (k = 0; k < n; k++)
				{
					Work[k] += ALLOCATION[i][k];/*将Work赋值为第i个进程各个已分配资
					源数＋系统现有的对应资源数(因为当改进程全部资源数都满足时进程结束并将资源返还给系统) */
				}
				p[l++] = i;//记录进程号	
			}
			else//如果超过继续循环下一个进程
			{
				continue;
			}
		}
		if (l == init_index)//比较安全序列是否发生变化
		{
			cout << "系统是不安全的" << endl;
			return false;
		}
	}//for循环
	cout << "系统是安全的" << endl;
	cout << "安全序列:" << endl;
	for (i = 0; i < l; i++)
	{
		cout << p[i];
		if (i != l - 1)
		{
			cout << "-->";
		}
	}
	cout << "" << endl;
	return true;
}

void showdata(int n, int m)   //显示
{
	int i, j;
	cout << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "系统可用的资源数为:    ";
	for (j = 0; j<n; j++)
		cout << "    " << AVAILABLE[j];
	cout << endl;
	cout << "各进程还需要的资源量:" << endl;
	for (i = 0; i<m; i++)
	{
		cout << "    进程" << i << ":";

		for (j = 0; j<n; j++)
			cout << "     " << NEED[i][j];
		cout << endl;
	}
	cout << endl;
	cout << "各进程已经得到的资源量:    " << endl << endl;
	for (i = 0; i<m; i++)
	{
		cout << "    进程" << i << ":";
		for (j = 0; j<n; j++)
			cout << "     " << ALLOCATION[i][j];
		cout << endl;
	}
	cout << endl;
}