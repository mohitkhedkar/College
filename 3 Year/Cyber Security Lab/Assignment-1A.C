// Assignment-1: Implement Euclid’s algorithm to find the GCD of two integers. Further implement extended Euclidean algorithm to find the multiplicative inverse of the given integer.
//  Author: Mohit Khedkar.

#include <stdio.h>
// Function to returngcd of a and b
int gcd(int a,int b){
        if(a == 0){
            return b;
        }
        return gcd(b%a, a);
}

 // Driver program to test above function
int main(){
    int a = 10, b = 15;   
    printf("GCD(%d, %d) = %dn", a, b,gcd(a, b));

    a = 35, b = 10;
    printf("GCD(%d, %d) = %dn", a, b,gcd(a, b));
    
    a = 31, b = 2;
    printf("GCD(%d, %d) = %dn", a, b,gcd(a, b));
    
    return 0;
}