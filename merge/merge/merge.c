#define _CRT_SECURE_NO_WARNINGS 1
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int i = 0, j = 0;
	while (i<m&&j<n)
	{
		if (nums1[i] <= nums2[j])
		{
			i++;
		}
		else
		{
			//ºóÒÆ
			m += 1;
			for (int a = m; a>i + 1; a--)
			{
				nums1[a - 1] = nums1[a - 2];
			}
			nums1[i] = nums2[j];
			j++;
		}
	}
	while (j<n)
	{
		nums1[i++] = nums2[j++];
	}
}