/**
    * File Name: 38_Count_and_say.c
    * Author: louis xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: Mar 31, 2016
*/

/**
 * The count-and-say sequence is the sequence of integers beginning as follows:
	1, 11, 21, 1211, 111221, ...

	1 is read off as "one 1" or 11.
	11 is read off as "two 1s" or 21.
	21 is read off as "one 2, then one 1" or 1211.
	Given an integer n, generate the nth sequence.

	Note: The sequence of integers will be represented as a string.
 */
void generate(char *in, char *out)
{
    int i, j, cnt = 1;

    for (i = 1, j = 0; in[i] != '\0'; i++) {
        if (in[i] == in[i-1]) {
            cnt++;
            continue;
        }
        out[j++] = cnt + '0';
        out[j++] = in[i-1];
        cnt = 1;
    }
    out[j++] = cnt + '0';
    out[j++] = in[i-1];
    out[j] = '\0';
}

char* countAndSay(int n) {
    int i;
    char *array_odd, *array_even;

    if (!n) {
        return NULL;
    }
    array_odd = (char *)malloc(BUFSIZ*sizeof(char));
    array_even = (char *)malloc(BUFSIZ*sizeof(char));

    array_odd[0] = '1';
    array_odd[1] = '\0';

    for (i = 2; i <= n; i++) {
        if (i % 2) {
            generate(array_even, array_odd);
        } else {
            generate(array_odd, array_even);
        }
    }

    if (n % 2) {
        return array_odd;
    } else {
        return array_even;
    }
}
