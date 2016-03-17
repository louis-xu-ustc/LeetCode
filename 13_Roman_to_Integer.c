/**
    * File Name: 13_Roman_to_Integer.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/17/16
*/

/**
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
*/

int romanToInt(char* s) {
    int result = 0, len = strlen(s);
    int map[256];
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    for (int i = 0; i < len; i++) {
        if ((i+1 < len) && (map[s[i]] < map[s[i+1]])) {
            result -= map[s[i]];
        } else {
            result += map[s[i]];
        }
    }

    return result;
}
