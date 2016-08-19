/**
    * File Name: 4_Median_of_Two_Sorted_Arrays.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/10/16
*/

/* There two sorted arrays nums1 and nums2 of size m and n respectively. 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum = nums1Size+nums2Size;
    int i = 0, j = 0, k = 0;
    int nums[sum];
    double median;

    if (!sum) {
        return 0;
    }

    while (i < nums1Size && j < nums2Size) {
        if(*(nums1 + i) <= *(nums2 + j)) {
            nums[k] = *(nums1 + i);
            i++;
        } else {
            nums[k] = *(nums2 + j);
            j++;
        }
        k++;
    }

    if (i != nums1Size) {
        while (i < nums1Size) {
            nums[k] = *(nums1 + i);
            i++;
            k++;
        }
    }

    if (j != nums2Size) {
        while (j < nums2Size) {
            nums[k] = *(nums2 + j);
            j++;
            k++;
        }
    }

    if (sum % 2) {
        median = nums[sum / 2];
    } else {
        median = (double)(nums[(sum/2) - 1] + nums[sum/2]) / 2;
    }

    return median;
}
