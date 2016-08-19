/**
    * File Name: 7_Reverse_Integer.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/14/16
*/

/**
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */

#define MAXS 100

int reverse(int x) {
    long int tmp;
    int A[MAXS] = {0};
    int idx = 0;
    int len;
    int ans;

    if (x == 0) 
        return 0;

    tmp = (x > 0) ?  x : -x;
    while (tmp) {
        A[idx] = tmp % 10;
        idx++;
        tmp = tmp/10;
    }

    len = idx;
    tmp = 0;
    for (idx = 0; idx < len; idx++) {
        tmp *= 10;
        tmp += A[idx];
    }

    if(tmp>INT_MAX||tmp<INT_MIN)
        return 0;
    ans = (x > 0) ? tmp : -tmp;

    return ans;
}
