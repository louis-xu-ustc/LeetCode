/**
    * File Name: 22_Generate_Parentheses.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/22/16
*/

/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
*/

/**
 *  * Return an array of size *returnSize.
 *  * Note: The returned array must be malloced, assume caller calls free().
 *  */

void traverse(char *result, int *returnSize, int top, int left, int right, char **array)
{
    char *res;

    if (!left && !right) {
        res = (char *)malloc(sizeof(char) * (top + 2));
        result[top+1] = '\0';
        strcpy(res, result);
        array[*returnSize] = res;
        (*returnSize)++;
        return;
    }
    if (left) {
        result[top+1] = '(';
        traverse(result, returnSize, top+1, left-1, right+1, array);
    }
    if (right) {
        result[top+1] = ')';
        traverse(result, returnSize, top+1, left, right-1, array);
    }
    return;
}


char** generateParenthesis(int n, int* returnSize) {
    int len = 2*n+1;
    char result[len];
    char **array;
    int size = 0, arraySize = 32768;
    int left, right, top = -1;

    if (!n) 
        return NULL;

    array = (char **)malloc(sizeof(char *) * arraySize);
    memset(array, 0, arraySize);

    left = n;
    right = 0;
    *returnSize = 0;
    traverse(result, &size, top, left, right, array);

    *returnSize = size;

    return array;
}
