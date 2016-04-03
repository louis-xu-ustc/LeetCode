/**
    * File Name: 70_Climbing_Stairs.c
    * Author: louis xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: Apr 3, 2016
*/

/**
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

int climbStairs(int n) {
    int *array = (int *) malloc(sizeof(int)*(n+1));

    if (n== 0 || n == 1 || n == 2) return n;
    array[1] = 1;
    array[2] = 2;
    for (int i = 3; i <= n; i++) {
        array[i] = array[i-2] + array[i-1];
    }
    return array[n];
}
