/**
    * File Name: 16_3Sum_Closest.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/18/16
*/

/**
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
 * Return the sum of the three integers. 
 * You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

int split(int a[], int low, int high)
{
    int part_element = a[low];

    for (;;) {
        while (low < high && part_element <= a[high]) {
            high--;
        }
        if (low >= high) break;
        a[low++] = a[high];

        while(low < high && part_element >= a[low]) {
            low++;
        }
        if (low >= high) break;
        a[high--] = a[low];
    }
    a[high] = part_element;

    return high;
}

void quicksort(int a[], int low, int high)
{
    int mid;

    if (low >= high) return;
    mid = split(a, low, high);
    quicksort(a, low, (mid - 1));
    quicksort(a, (mid + 1), high);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i, start, end;
    int sum = 0, val, key, ret;

    quicksort(nums, 0, numsSize - 1);

    sum = nums[0] + nums[1] + nums[2];
    val = sum - target;
    key = abs(val);
    ret = sum;

    for (i = 0; i < numsSize - 2; i++) {
        start = i + 1;
        end = numsSize -1;
        while (start < end) {
            sum = nums[i] + nums[start] + nums[end];
            val = sum - target;
            if (val == 0) {
                return sum;
            } else if (val > 0) {
                end--;
            } else {
                start++;
            }
            if (abs(val) < key) {
                ret = sum;
                key = abs(val);
            }
        }
    }
    return ret;
}
