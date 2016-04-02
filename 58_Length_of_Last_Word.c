/**
    * File Name: 58_Length_of_Last_Word.c
    * Author: louis xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: Apr 2, 2016
*/

/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example,
 * Given s = "Hello World",
 * return 5.
 */

int lengthOfLastWord(char* s) {
    int i = 0, cnt = 0;
    int flag = 0;

    while (s[i] != '\0') {
    	if (s[i] != ' ') {
    	    if (!flag) {
    	        flag = 1;
    	        cnt = 0;
    	    }
    		cnt++;
    	} else {
    	    flag = 0;
    	}
    	i++;
    }
    return cnt;
}
