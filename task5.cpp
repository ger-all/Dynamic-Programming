#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int SIZE = 46;
long long memo[SIZE];

long long climb_TopDown(int);
long long climb_BottomUp(int);
void init();

int main() {
    int n;
    cin >> n;
    if (n < 1 || n > 45) return -1;
    
    /**
     * n = 5;
     * Top-down result: 5
     * Bottom-up result: 5
     * Top-down time (ns): 250
     * Bottom-up time (ns): 100
     */
    
    init();

    auto start1 = high_resolution_clock::now();
    long long res1 = climb_TopDown(n);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    long long res2 = climb_BottomUp(n);
    auto end2 = high_resolution_clock::now();

    cout << "Top-down result: " << res1 << endl;
    cout << "Bottom-up result: " << res2 << endl;

    auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
    auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();

    cout << "Top-down time (ns): " << duration1 << endl;
    cout << "Bottom-up time (ns): " << duration2 << endl;

    // cout << "find_ways(" << m << ", " << n << "): " << res << endl;

    // cout << "time (ns): " << duration1 << endl;

    return 0;
}


/**
 * Top-down Dynamic Programming (Recursion with Memoization)
 * Branch & Bound: Avoid recalculating overlapping subproblems
 * Time: O(n)
 * Space: O(n)
 */
long long climb_TopDown(int n) {
    assert(n >= 0); // Assert that the n is not negative
    if (memo[n] != -1) return memo[n];
    if (0 == n || 1 == n) return memo[n] = n;
    return memo[n] = climb_TopDown(n - 1) + climb_TopDown(n - 2);
}

/**
 * climb_the_stairs_
 * Bottom-up DP (space optimized), (Tabulation), Cycle (for-loop)
 * Time: O(n)
 * Space: O(1)
 */
long long climb_BottomUp(int n) {
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

/** Array initialization */
void init() {
    for (int i = 0; i < SIZE; ++i) memo[i] = -1;
}

