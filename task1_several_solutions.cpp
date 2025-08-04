// Fibonacci Numbers, 
// Dynamic Programming Strategy: Store solutions to subproblems (Memoization or Tabilation)
// Branch and Bound Strategy: Prune redundant recursive calls (applies to memoization)

// --------------------------------------------------

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

const int N = 100;
long long fibArr[N];

long long fib_recursion(int);
long long fib_topdown(int);
long long fib_bottomup(int n);
long long fib_optimized(int n);
void fillArr(long long* arr);

int main() {
    fillArr(fibArr);

    for (int i = 0; i <= 5; ++i) {
        cout << "n = " << i << " → ";
        cout << "rec = " << fib_recursion(i) << endl;
        cout << "        top-down = " << fib_topdown(i) << endl;
        cout << "        bottom-up = " << fib_bottomup(i) << endl;
        cout << "        bottom-up optimized = " << fib_optimized(i) << "\n\n";
    }

    return 0;
}

/**
 * Pure recursion (no DP)
 * Time Complexity: O(2^n)
 * Space: O(n), because recursion uses stack memory 
 */
long long fib_recursion(int n) {
    assert(n >= 0); // Check input
    if (0 == n || 1 == n) return n; 
    return fib_recursion(n - 1) + fib_recursion(n - 2);
}

/**
 * Top-down Dynamic Programming (Recursion with Memoization)
 * Branch & Bound: Avoid recalculating overlapping subproblems
 * Time: O(n)
 * Space: O(n)
 */
long long fib_topdown(int n) {
    assert(n >= 0); // Assert that the n is not negative
    if (fibArr[n] != -1) return fibArr[n];
    if (0 == n || 1 == n) return fibArr[n] = n;
    return fibArr[n] = fib_topdown(n - 1) + fib_topdown(n - 2);
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

/**
 * Bottom-up DP (space optimized), (Tabulation), Cycle (for)
 * Time: O(n)
 * Space: O(1)
 */
long long fib_optimized(int n) { 
    assert(n >= 0); // Ensure n is non-negative
    
    if (0 == n || 1 == n) return n;
    
    long long prev = 0; // F(0)
    long long curr = 1; // F(1)

    long long temp;
    for (int i = 2; i <= n; ++i) {
        temp = prev + curr;
        prev = curr;
        curr = temp;
    }

    return curr;
}

/**
 * Initialize DP array with -1 to mark "unsolved"
 */
void fillArr(long long* arr) {
    for (int i = 0; i < 100; ++i)
        arr[i] = -1;
}

