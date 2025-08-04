#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int N = 91;
long long fibArr[N];

long long fib_topdown(int);
long long fib_bottomup(int);
void fillArr(long long* arr);

int main() {
    unsigned int n;
    cin >> n;
    if (n > 90) return -1;
    
    fillArr(fibArr);

    cout << "n = " << n << " → \n";

    // Top-down հաշվարկ + ժամանակաչափում
    auto start = high_resolution_clock::now();
    long long topdown_result = fib_topdown(n);
    auto end = high_resolution_clock::now();
    auto duration_topdown = duration_cast<microseconds>(end - start);

    cout << "top-down = " << topdown_result
         << " (time: " << duration_topdown.count() << " microseconds)\n";

    // Bottom-up հաշվարկ + ժամանակաչափում
    start = high_resolution_clock::now();
    long long bottomup_result = fib_bottomup(n);
    end = high_resolution_clock::now();
    auto duration_bottomup = duration_cast<microseconds>(end - start);

    cout << "bottom-up = " << bottomup_result
         << " (time: " << duration_bottomup.count() << " microseconds)\n";
    
    return 0;
}

/**
 * Top-down Dynamic Programming (Recursion with Memoization)
 * Branch & Bound: Avoid recalculating overlapping subproblems
 * Time: O(n)
 * Space: O(n)
 */
 long long fib_topdown(int n) {
    assert(n >= 0); // Ensure n is non-negative
    if (fibArr[n] != -1) return fibArr[n]; // Already calculated
    if (0 == n || 1 == n) return fibArr[n] = n; // Base cases
    return fibArr[n] = fib_topdown(n-1) + fib_topdown(n-2); // Memoized recursion
}

/**
 * Bottom-up Dynamic Programming (Tabulation), Cycle (for)
 * Time: O(n)
 * Space: O(n)
 */
long long fib_bottomup(int n) { 
    assert(n >= 0); // Ensure n is non-negative
    if (0 == n || 1 == n) return n;

    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/* Fill array with -1 to mark uninitialized values (Main step of memoization) */
void fillArr(long long* arr) {
    for (int i = 0; i < N; ++i)
        arr[i] = -1;
}

