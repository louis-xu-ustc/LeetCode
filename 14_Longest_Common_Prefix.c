/**
    * File Name: 14_Longest_Common_Prefix.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/18/16
*/

/**
 * Write a function to find the longest common prefix string among an array of strings.
 */

char* longestCommonPrefix(char** strs, int strsSize) {
    char *prefix = (char *)malloc(10000*sizeof(char));
    *prefix = '\0';
    char *p = prefix;
    int i;

    if (strsSize == 0)
        return prefix;

    for (int idx = 0; idx < strlen(strs[0]); idx++) {
        i = 1;
        for (; i < strsSize && strlen(strs[i]) > idx; i++) {
            if (strs[i][idx] != strs[0][idx])
                return prefix;
        }
        if (i == strsSize) {
            *p = strs[0][idx];
            p++;
        }

    }

    return prefix;
}

