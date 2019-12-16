/*给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
Example：
input:nums1 = [1,2,3,0,0,0], m = 3
      nums2 = [2,5,6],       n = 3
output: [1,2,2,3,5,6]*/

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
