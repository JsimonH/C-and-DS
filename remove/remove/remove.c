#define _CRT_SECURE_NO_WARNINGS 1

int removeElement(int* nums, int numsSize, int val)//ɾ��������ظ�Ԫ��
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)//�������Ⱦ��������ѭ��
		{
			continue;
		}
		if (nums[i] == val)//������������һ��Ԫ�ؽ���
		{
			tmp = nums[i];
			nums[i] = nums[numsSize - 1];
			nums[numsSize - 1] = tmp;
			if (nums[numsSize - 1] == val)//������һ������Ҳ����val��ѭ��i--
			{
				i--;
			}
			numsSize--;
		}
	}
	return numsSize;
}