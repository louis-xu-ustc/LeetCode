/**
    * File Name: 66_Plus_One.c
    * Author: louis xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: Apr 2, 2016
*/

/**
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = digitsSize - 1;
    int *newNum;

    if (!digits || digitsSize < 1) {
        return NULL;
    }

    while (i >= 0) {
        if (digits[i] == 9) {
            digits[i] = 0;
            i--;
        } else {
            digits[i]++;
            break;
        }
    }

    if (digits[0] == 0) {
        *returnSize = digitsSize + 1;
        newNum = (int *)malloc(*returnSize*sizeof(int));
        memcpy(newNum+1, digits, digitsSize*sizeof(int));
        newNum[0] = 1;
    } else {
        *returnSize = digitsSize;
        newNum = (int *)malloc(*returnSize*sizeof(int));
        memcpy(newNum, digits, digitsSize*sizeof(int));
    }

    return newNum;
}
