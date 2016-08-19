/**
    * File Name: 10_Regular_Expression_Matching.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/16/16
*/

/**
 Implement regular expression matching with support for '.' and '*'.

 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.

 The matching should cover the entire input string (not partial).

 The function prototype should be:
 bool isMatch(const char *s, const char *p)

 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 */ 

bool isMatch(char* s, char* p) {
    int sSize = strlen(s), pSize = strlen(p), i, j;
    bool checked[sSize+1][pSize+1];

    for(j=2, checked[0][0]=true, checked[0][1]= false; j<=pSize; ++j) 
        checked[0][j] = p[j-1] == '*'? checked[0][j-2]  : false;

    for(i=1; i<=sSize; ++i) {
        for(j=1, checked[i][0]=false; j<=pSize; ++j)
        {
            if(p[j-1]=='*')
                checked[i][j] = (j>1) && ( checked[i][j-2]  || ( ( checked[i-1][j]) && (s[i-1]== p[j-2] || p[j-2] == '.')) );
            else
                checked[i][j] = checked[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');        
        }
    }
    return checked[sSize][pSize];
}
