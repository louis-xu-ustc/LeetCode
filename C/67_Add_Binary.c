/**
    * File Name: 67_Add_Binary.c
    * Author: louis xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: Apr 2, 2016
*/

/**
 *  Given two binary strings, return their sum (also a binary string).

	For example,
	a = "11"
	b = "1"
	Return "100".
 */

#define MAX(x, y) (x) >= (y) ? (x) : (y)

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int carry = 0, len = MAX(len_a, len_b);
    char *answer = (char *) malloc((len+1) * sizeof(char));
    char *newAnswer, c;
    int i , j , k;

    if (!len_a) {
        return b;
    }
    if (!len_b) {
        return a;
    }

    for (i = len_a - 1, j = len_b - 1, k = len - 1; i >= 0 && j >= 0; i--, j--, k--) {
        c = (((a[i] - '0') ^ (b[j] - '0')) ^ carry) + '0';
        answer[k] = c;
        if ((carry + a[i] - '0') + (b[j] - '0') >= 2) {
            carry = 1;
        } else {
            carry = 0;
        }
    }
    while (i >= 0) {
        answer[k] = (a[i] - '0') ^ carry + '0';
        carry &= (a[i] - '0');
        i--;
        k--;
    }
    while (j >= 0) {
        answer[k] = (b[j] - '0') ^ carry + '0';
        carry &= (b[j] - '0');
        j--;
        k--;
    }
    answer[len] = '\0';

    if (carry) {
        newAnswer = (char*) malloc((len+2) * sizeof(char));
        memcpy(newAnswer+1, answer, (len+1) * sizeof(char));
        newAnswer[0] = '1';
        return newAnswer;
    } else {
        return answer;
    }
}
