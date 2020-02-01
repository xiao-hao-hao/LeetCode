﻿//88. 合并两个有序数组
//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//说明:初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	if (n == 0)
		return;
	if (m == 0)
	{
		int i = 0;
		for (i = 0; i < n; ++i)
			nums1[i] = nums2[i];
	}
	int i = 0, j = 0, len = m;
	for (int i = 0; i < n; ++i)
	{
		for (j = len - 1; j >= 0 && nums2[i] < nums1[j]; --j)
			nums1[j + 1] = nums1[j];
		nums1[j + 1] = nums2[i];
		++len;
	}
}