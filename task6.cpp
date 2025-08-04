#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int find_ways(int, int);

int main() {
    int m, n;
    cin >> m >> n;
    if (m < 1 || n < 1) return -1;
    
    /**
     * m = 3;
     * n = 5;
     * find_ways(3, 5): 56
     * time (ns): 6850
     */

    auto start = high_resolution_clock::now();
    int res = find_ways(m , n);
    auto end = high_resolution_clock::now();

    cout << "find_ways(" << m << ", " << n << "): " << res << endl;

    auto duration1 = duration_cast<nanoseconds>(end - start).count();

    cout << "time (ns): " << duration1 << endl;

    return 0;
}

/** Bottom-up DP with Tabulation */
int find_ways(int m, int n) {
    vector<vector<int>> mtr(m + 1, vector<int>(n + 1, 0)); // Declares an 2D vector

    // Fill first row and first column with 1s
    for (int i = 1; i < m + 1; ++i) mtr[i][0] = 1;
    for (int i = 1; i < n + 1; ++i) mtr[0][i] = 1;
    
    for (int i = 1; i < m + 1; ++i)
        for (int j = 1; j < n + 1; ++j)
            mtr[i][j] = mtr[i][j - 1] + mtr[i - 1][j];
    
    return mtr[m][n];
}

