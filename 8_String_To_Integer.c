/**
    * File Name: 8_String_To_Integer.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/14/16
*/

/**
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 */

#define MAXS 100
#define BITS_OVERFLOW 10

int myAtoi(char* str) {
    int A[MAXS] = {0};
    char *p = str;
    int i =0;
    int length;
    long int sum = 0;
    int sign = 0;

    if (!str) {
        return 0;
    }

    while (*p) {
        if (*p == ' ') {
            if (i > 0 || sign != 0) { // for case '+ 1', '1 2'
                break;
            }
            p++;
            continue;
        }
        if (sign != 0 && (*p == '+' || *p == '-')) { // for case '+-' or '-+' ...
            return 0;        
        }
        if (*p == '+' || *p == '-') {
            sign = (*p == '+') ? 1 : -1;
            p++;
            continue;
        }
        if (*p < '0' || *p > '9') {
            break;
        } else {
            A[i] = *p - '0';
            i++;
            if (i > BITS_OVERFLOW) { //truncate if overflowed
                break;
            }
            p++;
        }
    }

    if (i == 0) { // for case '+' or '-'
        return 0;
    }

    length = i;
    for (i = 0; i < length; i++) {
        sum *= 10;
        sum += A[i];
    }

    sum = (sign == -1) ? -sum : sum;
    if (sign != -1 && sum > INT_MAX) {
        return INT_MAX;
    }
    if (sign == -1 && sum < INT_MIN) {
        return INT_MIN;
    }

    return sum;
}
