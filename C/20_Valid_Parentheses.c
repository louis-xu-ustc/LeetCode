/**
    * File Name: 20_Valid_Parentheses.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/21/16
*/

/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#define PUSH(x) {\
    if (index >= BUFSIZ) { \
        return false; \
    } \
    stack[index] = (x); index++;}

#define POP(x) {\
    if (index <= 0) { \
        return false; \
    } \
    index--; (x) = stack[index];}

bool isValid(char* s) {
    char c, d, stack[BUFSIZ] = { 0 }, *t = s;
    int index = 0;
    bool ret = true;

    while ((c = *t) != '\0') {
        switch (c) {
            case '(':
            case '[':
            case '{':
                PUSH(c);
                break;

            case ')':
                POP(d);
                if (d != '(') {
                    return false;
                }
                break;

            case ']':
                POP(d);
                if (d != '[') {
                    return false;
                }
                break;
            case '}':
                POP(d);
                if (d != '{') {
                    return false;
                }
                break;
            default:
                return false;
        }
        t++;
    }
    if (index != 0)
        ret = false;

    return ret;
}
