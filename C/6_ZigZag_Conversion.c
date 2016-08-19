/**
    * File Name: 6_ZigZag_Conversion.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/13/16
*/


/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows: 
 * string convert(string text, int nRows); 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

char* convert(char* s, int numRows) {
    int n = strlen(s);
    int k = 0;
    char *result;

    if (!s) {
        return NULL;
    }
    if (n <= numRows || numRows == 1) {
        return s;
    }

    result = (char *) malloc(n+1);

    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < n; j += 2*(numRows-1)) {
            result[k++] = s[j];
            if (i != 0 && i != numRows - 1) {
                int t = j + 2*(numRows - 1) - 2*i;
                if (t < n) {
                    result[k++] = s[t];
                }
            }
        }
    }

    result[k] = '\0';
    return result;
}
