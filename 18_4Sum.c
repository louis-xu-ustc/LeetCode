/**
    * File Name: 18_4Sum.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/21/16
*/

/**
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 * A solution set is:
 * (-1,  0, 0, 1)
 * (-2, -1, 1, 2)
 * (-2,  0, 0, 2)
 */

/**
 *  * Return an array of arrays of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
#define BITS 4

int split(int a[], int low, int high)
{
    int part_element = a[low];

    for (;;) {
        while (low < high && a[high] > part_element) {
            high--;
        }
        if (low >= high) break;
        a[low++] = a[high];

        while(low < high && a[low] < part_element) {
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
    quicksort(a, low, mid-1);
    quicksort(a, mid+1, high);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, start, end;
    int sum;
    int **solution;
    int total = 64;
    int size = 0;

    if (!nums || numsSize < 4 || !returnSize) {
        return NULL;
    }
    solution = (int **)malloc(sizeof(int *) * total);
    for (i = 0; i < total; i++) {
        solution[i] = (int *) malloc(sizeof(int) * BITS);
    }

    quicksort(nums, 0, numsSize-1);

    for (i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i-1] == nums[i]) 
            continue;
        for (j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j-1] == nums[j])
                continue;

            start = j + 1;
            end = numsSize - 1;
            while (start < end) {
                sum = nums[i] + nums[j] + nums[start] + nums [end];
                if (sum == target) {
                    if (size > 0 && solution[size-1][0] == nums[i] &&
                            solution[size-1][1] == nums[j] &&
                            solution[size-1][2] == nums[start] &&
                            solution[size-1][3] == nums[end]) {
                        start++;
                        end--;
                        continue;
                    }
                    solution[size][0] = nums[i];
                    solution[size][1] = nums[j];
                    solution[size][2] = nums[start];
                    solution[size][3] = nums[end];
                    size++;

                    if (size == total) {
                        total <<= 1;
                        solution = (int **)realloc(solution, total * sizeof(int *));
                        for (int t = size; t < total; t++) {
                            solution[t] = (int *) malloc(BITS * sizeof(int));
                        }
                    }
                    start++;
                    end--;
                } else if (sum > target) {
                    end--;
                } else {
                    start++;
                }
            }
        }
    }

    *returnSize = size;

    return solution;
}
