void SListInit(SL* ps)
{
	assert(ps); //断言
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SListDestory(SL* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SListPrint(SL* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void CheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDataType*)realloc(ps->a, newcapacity*sizeof(SLDataType));
		ps->capacity = newcapacity;
	}
}

void SListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	size_t end = ps->size;
	while (end > 0)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}
	ps->a[end] = x;
	ps->size++;
}

void SListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}

void SListPopFront(SL* ps)
{
	assert(ps);
	size_t start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1]; 
		start++;
	}
	ps->size--;
}

int SListFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SListInsert(SL* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(pos < ps->size);
	CheckCapacity(ps);
	int end =ps->size-1;
	while (end >= (int)pos)  //此处为什么用强转?  因为pos是unsigned int,end是int类型 在比较时,小范围会向大范围转化
	{
		ps->a[end+1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SListErase(SL* ps, size_t pos)
{
	assert(ps && pos < ps->size);
	size_t start = pos;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}
