/**
    * File Name: 29_Divide_Two_Integers.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/24/16
*/


long ABS (int num) {
    if (num >= 0) {
        return (long) num; 
    } else {
        return -(long)(num);
    }
}

int divide (int dividend, int divisor) {
    bool negative = (dividend<0) ^ (divisor<0);
    long a = ABS(dividend);  
    long b = ABS(divisor);  

    int finalCount = 0;  
    int count = 0;

    if (!divisor || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;

    while (a >= b) {  
        count = 1;  
        long sum = b;  
        while (sum+sum <= a){  
            sum += sum;  
            count += count;  
        }  
        a -= sum;
        finalCount += count;  
    };  

    if (negative) {  
        return 0 - finalCount;  
    }else{  
        return finalCount;  
    } 
}
