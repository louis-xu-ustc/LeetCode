/**
    * File Name: 28_Implement_StrStr.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/24/16
*/

/** 
 * Implement strStr().
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

int strStr(char* haystack, char* needle) {
    int i, j, tmp;
    int m = strlen(haystack);
    int n = strlen(needle);

    if (!haystack || !needle) {
        return -1;
    }

    for (i = 0; i <= m - n; i++) {
        for (j = 0; j < n && haystack[i+j] == needle[j]; j++) {
            ;
        }
        if (j == n) 
            return i;
    }
    return -1;
}
