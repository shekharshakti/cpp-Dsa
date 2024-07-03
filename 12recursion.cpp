#include <iostream>
using namespace std;

int factorial(int n) {
    //base case
    if(n == 1) 
        return 1;
    if(n == 0)
        return 1;

    //recursive relation
    int recursionKaAns = factorial(n-1);

    //processing
    int finalAns = n * recursionKaAns;
    return finalAns;
}

void print(int n) {
    //base case
    if(n == 1) {
        cout << 1 << " ";
        return;
    }
    //processing
    cout << n << " ";
    //recursion call
    print(n-1);
} 

int pow(int n) {
    //base case
    if(n == 0) {
        return 1;
    }

    int ans = 2 * pow(n-1);
    return ans;
}

int fib(int n) {
    //base case
    if(n == 0) 
        return 0;
    if(n == 1) 
        return 1;

    int ans = fib(n-1) + fib(n-2);
    return ans;
} 

int sum(int n ) {
    //base case
    if(n == 1)
        return 1;

    int ans = n + sum(n-1);
    return ans;
}

int main() {
    // Function calls and print statements
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Fibonacci of 7: " << fib(7) << endl;
    cout << "Power of 2 to the 10th: " << pow(10) << endl;
    cout << "Sum of first 5 numbers: " << sum(5) << endl;
    
    cout << "Printing numbers from 5 to 1: ";
    print(5);
    cout << endl;

    return 0;
}
