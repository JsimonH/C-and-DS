// Heap.h
#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// 定义堆的结构
typedef int HpDataType;
typedef struct Heap
{
	HpDataType* _a;
	int      _size;
	int      _capacity;
}Heap;

void HeapCreate(Heap* hp, HpDataType* a, int n);  //堆的创建
void AdjustDown(HpDataType* a, int n, int root);  //向下调整算法，建堆或者堆的删除时使用
void HeapDestory(Heap* hp);  //堆的销毁
void HeapPush(Heap* hp, HpDataType x);  //堆的插入
void AdjustUp(int* a, int child);  //向上调整算法，向堆中插入数据时使用
void HeapPop(Heap* hp);  //堆的删除
HpDataType HeapTop(Heap* hp);  //获取堆顶数据
int HeapEmpty(Heap* hp);  //判断堆是否为空
void HeapPrint(Heap* hp);  //打印堆中数据
void Swap(int* a, int* b);   //交换函数


// Heap.c
#include "Heap.h"

void Swap(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HpDataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 找出小的那个孩子
		if (child + 1 < n && a[child+1] < a[child])
		{
			++child;		
		}

		// 1、孩子比父亲小，则交换，继续往下调
		// 2、孩子比父亲大，则停止调整
		if (a[parent] > a[child])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapCreate(Heap* hp, HpDataType* a, int n)
{
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType) * n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	// 建小堆,从倒数第一个非叶子节点开始
	for (int i = (n-1-1)/2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}

void HeapPush(Heap* hp, HpDataType x)
{
	// 空间不够->增容
	if (hp->_size == hp->_capacity)
	{
		int newcapacity = hp->_capacity * 2;
		hp->_a = (HpDataType*)realloc(hp->_a, sizeof(HpDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}

	hp->_a[hp->_size] = x;
	hp->_size++;

	// 向上调整，调成堆
	AdjustUp(hp->_a, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
    // 把最后一个数据和堆顶数据交换,然后删除堆顶数据
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
    
    // 再进行调堆
	AdjustDown(hp->_a, hp->_size, 0);
}

HpDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; ++i)
	{ 
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}


//Test.c
#include "Heap.h"

int main()
{
	int a[6] = {17,42,31,55,29,77};
	Heap hp;
	// 堆的创建
	printf("创建后的堆:\n");
	HeapCreate(&hp, a, 6);
	HeapPrint(&hp);

	// 堆的插入
	printf("向堆中插入数据6,并重新调堆:\n");
	HeapPush(&hp, 6);
	HeapPrint(&hp);
	
	// 堆的删除
	printf("删除堆顶数据,并重新调堆:\n");
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestory(&hp);
	return 0;
}
