#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void init();
long long fact_topdown(int n);
long long fact_bottomup(int n);

const int MAX = 21;
long long memo[MAX];

int main() {
    int n;
    cin >> n;
    
    /**
     * n = 20;
     * Top-down time (ns): 270
     * Bottom-up time (ns): 120
     */

    init();

    auto start1 = high_resolution_clock::now();
    long long res1 = fact_topdown(n);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    long long res2 = fact_bottomup(n);
    auto end2 = high_resolution_clock::now();

    cout << "Top-down result: " << res1 << endl;
    cout << "Bottom-up result: " << res2 << endl;

    auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
    auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();

    cout << "Top-down time (ns): " << duration1 << endl;
    cout << "Bottom-up time (ns): " << duration2 << endl;

    return 0;
}

/** Array initialization */
void init() {
    for (int i = 0; i < MAX; ++i) memo[i] = -1;
}

/** Top-down with memoization */
long long fact_topdown(int n) {
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    return memo[n] = n * fact_topdown(n - 1);
}

/** Bottom-up with Tabulation */
long long fact_bottomup(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

