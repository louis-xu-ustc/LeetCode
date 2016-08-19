/**
    * File Name: 12_Integer_to_Roman.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/17/16
*/

/**
 * Given an integer, convert it to a roman numeral. 
 * Input is guaranteed to be within the range from 1 to 3999.
 */

char* intToRoman(int num) {
    char *Roman = (char *)malloc(30*sizeof(char));
    const char *P[] = 
    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
        "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
        "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
        "", "M", "MM", "MMM", "MMMM",
    };

    *Roman = '\0';

    if (num/1000) 
        strcat(Roman, P[num/1000 + 30]);
    if (num/100%10)
        strcat(Roman, P[num/100%10 + 20]);
    if (num/10%10)
        strcat(Roman, P[(num/10)%10+10]);
    if (num%10)
        strcat(Roman, P[num%10]);

    return Roman;
}
