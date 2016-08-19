/**
    * File Name: 3_Longest_Substring_Without_Repeating_Characters.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/09/16
*/

/* Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 * For "bbbbb" the longest substring is "b", with the length of 1.
 */

int lengthOfLongestSubstring(char* s) {
    int len = 0;
    char *end = s, *tmp;
    char *addressTable[128] = {NULL};

    while (*end) {
        tmp = addressTable[*end];   //get the old address of ASCII (*end)
        addressTable[*end] = end;   //store the new address of ASCII (*end)
        if (tmp >= s) {             
            len = (end - s) > len ? (end - s) : len;
            s = tmp + 1;
        }
        end++;
    }
    len = (end -s) > len ? (end - s) : len;

    return len;
}
