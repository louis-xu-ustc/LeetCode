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

#define MAX(x, y) {(x) >= (y) ? (x) : (y)}
char* addBinary(char* a, char* b) {
	int len_a = strlen(a);
	int len_b = strlen(b);
	int carry = 0, len = MAX(len_a, len_b);
	char *answer = (char *) malloc(len * sizeof(char));
	char *newAnswer;
	int i , j , k;

	for (i = len_a-1, j = len_b - 1, k = len - 1; i >= 0 && j >= 0; i--, j--, k--) {
		answer[k] = a[i] ^ b[j] + carry;
		carry = a[i] & b[j];
	}
	while (i) {
		answer[k] = a[i] + carry;
		carry &= a[i];
		i--;
		k--;
	}
	while (j) {
		answer[k] = b[j] + carry;
		carry &= b[j];
		j--;
		k--;
	}
	if (carry) {
		newAnswer = (char*) alloc((len+1) * sizeof(int));
		memcpy(newAnswer+1, answer, len * sizeof(int));
		newAnswer[0] = 1;
		return newAnswer;
	} else {
		return answer;
	}

}
