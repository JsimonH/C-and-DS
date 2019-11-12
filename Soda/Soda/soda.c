#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int money = 20;
//	int total = money;
//	int empty = money;
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//	return 0;
//}


int Drink_sum(int money, int price)
{
	int sum = 0;
	int temp = 0;
	int ret = 0;
	sum = money / price;
	ret = sum;
	while (ret / 2 != 0)
	{
		temp = ret;
		ret = ret / 2;
		sum += ret;
		ret = temp % 2 + ret;
	}
	return sum;
}

int main()
{
	int money = 0;
	int price = 0;
	printf("please enter money and price:\n");
	scanf("%d %d", &money, &price);
	int bottle = Drink_sum(money, price);
	printf("%d元可以喝汽水%d瓶\n", money, bottle);
	return 0;
}

