/**
    * File Name: 1_two_sum.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/08/16
*/
/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *result = NULL;
    int i, j, tmp = 0;

    result = (int *)malloc(2 * sizeof(int));
    if (result == NULL) {
        return NULL;
    } else {
        memset(result, 0, sizeof(result));
    }

    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            tmp = nums[i] + nums[j];
            if (abs(tmp - target) < 0.00001 && i != j) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return NULL;
}
