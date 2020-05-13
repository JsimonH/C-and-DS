//List.h
#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

//带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _val;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

ListNode* ListCreate();  //创建返回链表的头结点
void ListDestory(ListNode* pHead);  //双向链表销毁
void ListPrint(ListNode* pHead);  //双向链表打印
void ListPushBack(ListNode* pHead, LTDataType x);  //双向链表尾插
void ListPopBack(ListNode* pHead);  //双向链表尾删
void ListPushFront(ListNode* pHead, LTDataType x);  //双向链表头插
void ListPopFront(ListNode* pHead);  // 双向链表头删
ListNode* ListFind(ListNode* pHead, LTDataType x);  //双向链表查找
void ListInsert(ListNode* pos, LTDataType x);  //双向链表在pos的前面进行插入
void ListErase(ListNode* pos);  //双向链表删除pos位置的节点

//List.c
#include"List.h"

ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_prev = head;
	head->_next = head;
	return head;
}

void ListDestroy(ListNode* pHead) 
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
	pHead = NULL;
}

void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d->", cur->_val);
		cur = cur->_next;
	}
	printf("到链表头啦\n");
}

ListNode* SetListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_val = x;
	newNode->_prev = NULL;
	newNode->_next = NULL;
	return newNode;
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newNode = SetListNode(x);
	//phead tail newnode
	ListNode* tail = pHead->_prev;
	tail->_next = newNode;
	newNode->_prev = tail;
	newNode->_next = pHead;
	pHead->_prev = newNode;
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* tail = pHead->_prev;
	ListNode* tailPrev = tail->_prev;
	//pHead   tailPrev   tail
	tailPrev->_next = pHead;
	pHead->_prev = tailPrev;
	free(tail);
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newNode = SetListNode(x);
	//pHead   newNode   first 
	ListNode* first = pHead->_next;
	pHead->_next = newNode;
	newNode->_prev = pHead;
	newNode->_next = first;
	first->_prev = newNode;
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	//pHead   first   second
	ListNode* first = pHead->_next;
	ListNode* second = first->_next;
	second->_prev = pHead;
	pHead->_next = second;
	free(first);
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_val == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newNode = SetListNode(x);
	ListNode* posPrev = pos->_prev;
	//posPrev   newNode   pos
	posPrev->_next = newNode;
	newNode->_prev = posPrev;
	newNode->_next = pos;
	pos->_prev = newNode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->_prev;
	ListNode* posNext = pos->_next;
	posPrev->_next = posNext;
	posNext->_prev = posPrev;
	free(pos);
}

//test.c
#include"List.h"

int main()
{
	ListNode* list = ListCreate();
	printf("双向链表尾插:\n");
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPushBack(list, 5);
	ListPrint(list);

	printf("双向链表尾删:\n");
	ListPopBack(list);
	ListPrint(list);

	printf("双向链表头插:\n");
	ListPushFront(list, 1);
	ListPushFront(list, 0);
	ListPrint(list);
	
	printf("双向链表头删:\n");
	ListPopFront(list);
	ListPrint(list);

	ListDestroy(list);
	return 0;
}
