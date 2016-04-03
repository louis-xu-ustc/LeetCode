/**
    * File Name: 88_Merge_Sorted_Array.c
    * Author: louis xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: Apr 3, 2016
*/

/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

int split(int a[], int low, int high)
{
	int pivot = a[low];
	for (;;) {
		while (low < high && a[high] >= pivot) high--;
		if (low >= high) break;
		a[low++] = a[high];

		while (low < high && a[low] <= pivot) low++;
		if (low >= high) break;
		a[high--] = a[low];
	}
	a[high] = pivot;

	return high;
}

void quicksort(int a[], int low, int high)
{
	int mid;

	if (low >= high) return;
	mid = split(a, low, high);
	quicksort(a, low, mid-1);
	quicksort(a, mid+1, high);
}

void merge(int* nums1, int m, int* nums2, int n) {
	memcpy(nums1+m, nums2, n*sizeof(int));
	quicksort(nums1, 0, m+n-1);
}
