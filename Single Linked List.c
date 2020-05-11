//SList.h
#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int SLDataType;
typedef struct SListNode
{
	SLDataType val;
    struct SListNode* next;
}ListNode;

ListNode* SetListNode(SLDataType x);  //动态申请一个节点
void SListPrint(ListNode* plist);  //单链表打印
void SListPushBack(ListNode** pplist, SLDataType x);  //单链表尾插
void SListPushFront(ListNode** pplist, SLDataType x);  //单链表头插
void SListPopBack(ListNode** pplist);  //单链表尾删
void SListPopFront(ListNode** pplist);  //单链表头删
ListNode* SListFind(ListNode* plist, SLDataType x);  //单链表查找
void SListInsertAfter(ListNode* pos, SLDataType x);  //单链表在pos位置之后插入x
void SListEraseAfter(ListNode* pos);  //单链表删除pos位置之后的值


//SList.c
#include"SList.h"

ListNode* SetListNode(SLDataType x)
{
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->val = x;
	Node->next = NULL;

	return Node;
}

void SListPrint(ListNode* plist)
{
	ListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(ListNode** pplist, SLDataType x)
{
	ListNode* newNode = SetListNode(x);
	
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		ListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

void SListPushFront(ListNode** pplist, SLDataType x)
{
	assert(pplist);
	ListNode* newNode = SetListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		newNode->next = *pplist;
		*pplist = newNode;
	}
}

void SListPopBack(ListNode** pplist)
{
	ListNode* prev = NULL;
	ListNode* tail = *pplist;
	//链表为空,或者只有一个节点
	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pplist = NULL;
	}
	//两个及以上节点
	else
	{
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SListPopFront(ListNode** pplist)
{
	ListNode* cur = *pplist;
	//链表为空
	if (cur == NULL)
	{
		return;
	}
	//有一个节点
	else if (cur->next == NULL)
	{
		free(cur);
		*pplist = NULL;
	}
	//两个及以上节点
	else
	{
		ListNode* next = cur->next;
		free(cur);
		*pplist = next;
	}
}

ListNode* SListFind(ListNode* plist, SLDataType x)
{
	ListNode* cur = plist;
	while (cur)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(ListNode* pos, SLDataType x)
{
	assert(pos);
	ListNode* next = pos->next;
	// pos newNode next
	ListNode* newNode = SetListNode(x);
	pos->next = newNode;
	newNode->next = next;
}

void SListEraseAfter(ListNode* pos)
{
	assert(pos);
	// pos next end
	ListNode* next = pos->next;
	
	if (next != NULL)
	{
		ListNode* end = next->next;
		free(next);
		pos->next = end;
	}
}


//test.c
#include"SList.h"

int main()
{
	ListNode* list = NULL;
	printf("单链表尾插:\n");
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPrint(list);

	printf("单链表头插:\n");
	SListPushFront(&list, 0);
	SListPrint(list);
	
	printf("单链表尾删:\n");
	SListPopBack(&list);
	SListPopBack(&list);
	SListPrint(list);

	printf("单链表头删:\n");
	SListPopFront(&list);
	SListPrint(list);

	printf("单链表查找:\n");
	ListNode* ret1 = SListFind(list, 5);
	ListNode* ret2 = SListFind(list, 2);
	SListPrint(ret1);
	SListPrint(ret2);

	printf("单链表插入:\n");
	SListInsertAfter(ret2, 5);
	SListPrint(list);

	printf("单链表删除:\n");
	SListEraseAfter(ret2);
	SListPrint(list);
	return 0;
}
