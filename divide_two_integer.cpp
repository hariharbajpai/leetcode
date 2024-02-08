#include<iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Check for division by zero and overflow
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;

        // Determine the sign of the quotient
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        // Convert both dividend and divisor to positive long long integers
        long long dvd = labs(dividend);  
        long long dvs = labs(divisor);    

        // Initialize the quotient
        long long quotient = 0;

        // Perform division using repeated subtraction
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {  // Bitwise left shift (multiply by 2)
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }

        // Adjust the sign of the quotient
        quotient = (sign == -1) ? -quotient : quotient;

        // Check for overflow and return the result
        if (quotient > INT_MAX) return INT_MAX;
        else return quotient;
    }
};

int main(){

    return 0;
}