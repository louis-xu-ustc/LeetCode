/**
    * File Name: 15_3Sum.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/18/16
*/

/**
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},
 *
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
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

        while (low < high && a[low] <= part_element) {
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
    int middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, (middle - 1));
    quicksort(a, (middle + 1), high);
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **solution;
    int total = 64;
    int size = 0;
    int i, start, end;
    int sum;

    solution = (int **)malloc(total * sizeof(int *));
    for (int i = 0; i < total; i++) {
        solution[i] = (int *)malloc(3 * sizeof(int));
    }

    if (!nums || numsSize < 3 || !returnSize)
        return NULL;

    quicksort(nums, 0, numsSize - 1);

    for (i = 0; i < numsSize -2; i++) {
        if (i > 0 && nums[i] == nums[i-1])
            continue;

        start = i + 1;
        end  = numsSize -1;
        while (start < end) {
            sum = nums[i] + nums[start] + nums[end];
            if (sum == 0) {
                if (size > 0 && solution[size-1][0] == nums[i] &&
                        solution[size-1][1] == nums[start] &&
                        solution[size-1][2] == nums[end]) {
                    start++;
                    end--;
                    continue;
                }
                solution[size][0] = nums[i];
                solution[size][1] = nums[start];
                solution[size][2] = nums[end];
                size++;

                if (size == total) {
                    total <<= 1;
                    solution = (int **)realloc(solution, total * sizeof(int *));
                    for (int t = size; t < total; t++) {
                        solution[t] = (int *)malloc(3 * sizeof(int));
                    }
                }
                start++;
                end--;
            } else if (sum > 0) {
                end--;
            } else {
                start++;
            }
        }
    }

    *returnSize = size;
    return solution;
}
