/**
    * File Name: 26_Remove_Duplicates_from_Sorted_Array.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/23/16
*/

/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

int removeDuplicates(int* nums, int numsSize) {
    int i, j, cnt = 0, size = numsSize;
    if (!nums || numsSize == 1) {
        return numsSize;
    }

    for (i = 1; i < size; i++) {
        if (nums[i] == nums[i-1]) {
            cnt++;
            continue;
        }
        if (cnt > 0) {
            for (j = i; j < size; j++) {
                nums[j-cnt] = nums[j];
            }
            size -= cnt;
            i -= cnt;
            cnt = 0;
        }
    }
    if (cnt > 0) {
        for (j = i; j < size; j++) {
            nums[j-cnt] = nums[j];
        }
        size -= cnt;
        cnt = 0;
    }

    return size;
}

//fucking awesome
int removeDuplicates(int* nums, int numsSize) {
    int i, cnt = 0;

    for (i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1]) {
            cnt++;
        } else {
            nums[i-cnt] = nums[i];
        }
    }

    return numsSize - cnt;
}
