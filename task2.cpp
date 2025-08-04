#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

long long fib_bottomup(int);

int main() {
    int target = 6;
    cout << "fib(" << target - 1 << ") = " << fib_bottomup(target - 1) << endl;
    cout << "fib(" << target  << ") = " << fib_bottomup(target) << endl;
    cout << "fib(" << target + 1 << ") = " << fib_bottomup(target + 1) << endl;
    
    return 0;
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

