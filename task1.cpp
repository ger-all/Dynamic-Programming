#include <iostream>
#include <cassert>
using namespace std;

const int N = 100;
long long fibArr[N];

long long fib_topdown(int);
void fillArr(long long* arr);

int main() {
    fillArr(fibArr);
    int target = 6;
    cout << "fib(" << target - 1 << ") = " << fib_topdown(target - 1) << endl;
    cout << "fib(" << target  << ") = " << fib_topdown(target) << endl;
    cout << "fib(" << target + 1 << ") = " << fib_topdown(target + 1) << endl;
    
    return 0;
}

/* Top-down Fibonacci with memoization, Dynamic Strategy */
long long fib_topdown(int n) {
    assert(n >= 0); // Ensure n is non-negative
    if (fibArr[n] != -1) return fibArr[n]; // Already calculated
    if (0 == n || 1 == n) return fibArr[n] = n; // Base cases
    return fibArr[n] = fib_topdown(n-1) + fib_topdown(n-2); // Memoized recursion
}

/* Fill array with -1 to mark uninitialized values (Main step of memoization) */
void fillArr(long long* arr) {
    for (int i = 0; i < N; ++i)
        arr[i] = -1;
}

