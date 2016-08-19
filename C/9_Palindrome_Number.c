/**
    * File Name: 9_Palindrome_Number.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/14/16
*/

/**
 * Determine whether an integer is a palindrome. Do this without extra space.
 */ 

#define MAXS 100

bool isPalindrome(int x) {
    int min = 0, slow = x, fast = x;

    if (x < 0)
        return 0;

    while (fast) {
        min = 10 * min + slow % 10;
        slow /= 10;
        fast /= 100;
    }

    if (slow == min || slow == min / 10) {
        return 1;
    } else {
        return 0;
    }
}
