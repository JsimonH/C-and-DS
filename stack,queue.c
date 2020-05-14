//stack.h
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;  //栈顶
	int _capacity;  //栈的容量
}Stack;

// 初始化栈
void StackInit(Stack* pst)
{
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}

// 入栈
void StackPush(Stack* pst, STDataType data)
{
	assert(pst);
	if (pst->_top == pst->_capacity)
	{
		int _newcapacity = pst->_capacity == 0 ? 4 : pst->_capacity * 2;
		pst->_a = (STDataType*)realloc(pst->_a,sizeof(STDataType)*_newcapacity);
		pst->_capacity = _newcapacity;
	}
	pst->_a[pst->_top] = data;
	++pst->_top;
}

// 出栈
void StackPop(Stack* pst)
{
	assert(pst && pst->_top > 0);
	--pst->_top;
}

// 获取栈顶元素
STDataType StackTop(Stack* pst)
{
	assert(pst);
	return pst->_a[pst->_top - 1];
}

// 获取栈中有效元素个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
}

// 销毁栈
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}


//queue.h
typedef int QDataType;
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* _front;
	struct QueueNode* _rear;
}Queue;

// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QueueNode* newnode =(QueueNode*) malloc(sizeof(QueueNode));
	newnode->_data = data;
	newnode->_next = NULL;
	
	if (q->_rear == NULL)
	{
		q->_front=q->_rear = newnode;
	}
	else
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}

// 队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
	}
	else
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}
}
// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		n++;
		cur = cur->_next;
	}
	return n;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}

// 销毁队列
void QueueDestroy(Queue* q)
{
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear= NULL;
}


//test.c
#include"stack.h"
#include"queue.h"

void TestStack()
{
	Stack st;
	StackInit(&st);
	
	//数据入栈
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	//数据出栈
	printf("数据出栈:\n");
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestroy(&st);
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	
	//入队列
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	
	//出队列
	printf("数据出队列:\n");
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	QueueDestroy(&q);
}

int main()
{
	TestStack();
	TestQueue();
	return 0;
}
