// Assignment-1: Implement Euclid’s algorithm to find the GCD of two integers. Further implement extended Euclidean algorithm to find the multiplicative inverse of the given integer.
//  Author: Mohit Khedkar.

// C program to find multiplicative modulo inverse using 
// Extended Euclid algorithm. 
#include <stdio.h> 
  
// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int* x, int* y); 
  
// Function to find modulo inverse of a 
void modInverse(int a, int m) { 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        printf("Inverse doesn't exist"); 
    else  { 
        // m is added to handle negative x 
        int res = (x % m + m) % m; 
        printf("Modular multiplicative inverse is %d", res); 
    } 
} 
// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int* x, int* y) { 
    // Base Case 
    if (a == 0)  { 
        *x = 0, *y = 1; 
        return b; 
    } 
int x1, y1; 
    int gcd = gcdExtended(b % a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    *x = y1 - (b / a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
// Driver Code 
int main() { 
    int a = 3, m = 11; 
    
     modInverse(a, m); 


    return 0; 
} 
