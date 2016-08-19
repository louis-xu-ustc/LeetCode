/**
    * File Name: 5_Longest_Palindromic_Substring.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/13/16
*/

/**
 * Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */


#define MAXS 3000
#define MIN(x, y) (x) < (y) ? (x) : (y)

void display(char *s, int *p)
{
    char *end = s;
    int *q = p;

    printf("char - num\n");
    while (*end) {
        printf("%c - %d\n", *end, *q);
        end++;
        q++;
    }
}

int Proc(char *in,char *out)
{
    int nLen=1;
    int i = 0;

    if (!in || !out) {
        printf("Invalid ptr!\n");
        return 0;
    } 

    out[0] = '$';
    while(in[i] != '\0')
    {
        out[nLen++] = '#';
        out[nLen++] = in[i++];
    }
    out[nLen++] = '#';
    out[nLen] = '\0';

    return nLen;
}

void Manacher(int *p, char *str, int len)
{
    int mx = 0, id = 0;

    for(int i = 0;i < len;i++)
    {
        p[i] = mx > i ? MIN(p[2*id-i], mx-i) : 1;
        while(str[i+p[i]] == str[i-p[i]]) p[i]++;
        if (i + p[i] > mx)
        {
            mx=i + p[i];
            id = i;
        }
    }
}

char* longestPalindrome(char* s) 
{
    int length;
    char str[MAXS] = {0};
    int p[MAXS] = {0};
    char ans[MAXS] = {0};
    int maxRadis = 0, maxRadisIdx = 0;
    int i = 0, j = 0, k = 0;
    int mx = 0, id = 0;

    length = Proc(s, str);
    Manacher(p, str, length);

    for (i = 0; i < length; i++) {
        if (p[i] > maxRadis) {
            maxRadis = p[i];
            maxRadisIdx = i;
        }
    }

    int len = 0;
    if (maxRadis % 2 == 0)
        len = maxRadis - 1;
    else
        len = maxRadis / 2 * 2;

    for (i = maxRadisIdx - maxRadis + 1, k = 0, j = 0; k < maxRadis; i += 2, k++) {
        ans[j++] = str[i + 1];
    }
    ans[len] = '\0';

    return ans;
}
