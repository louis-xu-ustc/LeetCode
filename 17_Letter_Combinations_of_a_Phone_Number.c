/**
    * File Name: 17_Letter_Combinations_of_a_Phone_Number.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/20/16
*/


/**
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

/**
 *  * Return an array of size *returnSize.
 *  * Note: The returned array must be malloced, assume caller calls free().
 */

const char map[10][4] = {
    {' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' '},
    {'a', 'b', 'c', ' '},
    {'d', 'e', 'f', ' '},
    {'g', 'h', 'i', ' '},
    {'j', 'k', 'l', ' '},
    {'m', 'n', 'o', ' '},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v', ' '},
    {'w', 'x', 'y', 'z'},
};

void letterCombine(char *digits, int *returnSize, char *result, int ind, char **array)
{
    char c, *res;
    char *letter = map[digits[0] - '0'];
    int i = 0;

    if (digits[0] == '\0') {
        res = (char *) malloc(sizeof(char) * strlen(result));
        strcpy(res, result);
        array[*returnSize] = res;
        (*returnSize)++;
        return;
    }

    while ((c = letter[i]) != ' ') {
        result[ind] = letter[i];
        letterCombine(digits+1, returnSize, result, ind+1, array);
        i++;
        if (i == 4) {
            break;
        }
    }
    return;
}

char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits) + 1;
    char result[len];
    int ind = 0, size = 0;
    char **array;
    int arraySize = 32768;

    if (!digits || !returnSize || !strlen(digits)) 
        return NULL;

    array = (char **) malloc(sizeof(char *) * arraySize);
    memset(array, 0, arraySize);

    letterCombine(digits, &size, result, ind, array);

    *returnSize = size;

    return array;
}
