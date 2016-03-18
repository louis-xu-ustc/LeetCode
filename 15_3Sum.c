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

#define N 1000
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **solution;
    int low, mid, high, l, r, c;
    int i = 0;

    solution = (int **)malloc(N * sizeof(int *));
    if (!solution) {
        return NULL;
    }
    else {
        memset(solution, 0, sizeof(N * sizeof(int *)));
    }

    for (int i = 0; i < N; i++) {
        solution[i] = (int *)malloc(3 * sizeof(int));
        if (!solution[i]) {
            return NULL;
        }
        else {
            memset(solution[i], 0, sizeof(3 * sizeof(int)));
        }
    }

    if (!nums || numsSize < 3 || !returnSize)
        return NULL;

    quicksort(nums, 0, numsSize - 1);

    *returnSize = 0;
    low = 0;
    high = numsSize - 1;
    while (low < high) {
        l = nums[low];
        r = nums[high];
        if (l + r > 0 && 2 * l + r > 0)
        {
            high--;
            continue;
        }
        if (l + r < 0 && l + 2 * r < 0) {
            low++;
            continue;
        }
        if (l + r >= 0) {
            for (mid = low + 1; mid < high; mid++) {
                c = nums[mid];
                //printf("1- l:%d, r:%d, c:%d\n", l, r, c);
                //printf("1- low:%d, high:%d, mid: %d\n", low, high, mid);
                if (l + r + c > 0) {
                    break;
                }
                if (l + r + c == 0) {
                    printf("1-ok l:%d, r:%d, c:%d\n", l, r, c);
                    solution[i][0] = l;
                    solution[i][1] = c;
                    solution[i][2] = r;
                    (*returnSize)++;
                    i++;
                }
            }
            high--;
        }
        else {
            for (mid = high - 1; mid > low; mid--) {
                c = nums[mid];
                //printf("2- l:%d, r:%d, c:%d\n", l, r, c);
                //printf("2- low:%d, high:%d, mid: %d\n", low, high, mid);
                if (l + r + c < 0) {
                    break;
                }
                if (l + r + c == 0) {
                    printf("2-ok l:%d, r:%d, c:%d\n", l, r, c);
                    solution[i][0] = l;
                    solution[i][1] = c;
                    solution[i][2] = r;
                    (*returnSize)++;
                    i++;
                }
            }
            low++;
        }
    }

    return solution;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {

    int **ret = NULL;
    int total = 64;
    int size = 0;
    int i,start,end;
    int sum;

    ret = (int **)malloc(sizeof(int *) * total);
    for(i = 0; i < total; ++i)
        ret[i] = (int *)malloc(sizeof(int) * 3);

    qsort(nums,numsSize,sizeof(int),cmp);

    for(i = 0; i < numsSize-2; ++i){
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        start = i + 1;
        end = numsSize - 1;
        while(start < end){
            sum = nums[i] + nums[start] + nums[end];
            if(sum == 0){
                if(size > 0 && ret[size-1][0] == nums[i] && 
                        ret[size-1][1] == nums[start] && ret[size-1][2] == nums[end]){
                    ++start;
                    --end;
                    continue;
                }
                ret[size][0] = nums[i];
                ret[size][1] = nums[start];
                ret[size][2] = nums[end];
                size++;

                if(size == total){
                    total <<= 1;
                    int t;
                    ret = (int **)realloc(ret,sizeof(int *) * total);
                    for(t = size; t < total; ++t)
                        ret[t] = (int *)malloc(sizeof(int) * 3);
                }
                ++start;
                --end;
            } else if(sum > 0){
                --end;
            }else{
                ++start;
            }
        } // end while(start < end)
    } // end for(i = 0; i < numsSize-2; ++i)

    *returnSize = size;
    return ret;
}
