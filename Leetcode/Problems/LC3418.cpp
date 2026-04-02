#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl
#define printVec(v)       \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl

// ===== SOLUTION =====
class Solution
{
    int m;
    int n;
    vector<vector<vector<int>>> t;

public:
    int solve(vector<vector<int>> &coins, int i, int j, int p)
    {
        if (i == m - 1 && j == n - 1)
        {
            if (coins[i][j] < 0 && p > 0)
            {
                return 0;
            }
            return coins[i][j];
        }
        // out of bound
        if (i >= m || j >= n)
        {
            return INT_MIN;
        }

        if (t[i][j][p] != INT_MIN)
        {
            return t[i][j][p];
        }

        // Note: condition for taking the coin
        int next = max(solve(coins, i + 1, j, p), solve(coins, i, j + 1, p));
        if (next == INT_MIN)
            return t[i][j][p] = INT_MIN;

        int take = INT_MIN;
        if (next != INT_MIN)
        {
            take = coins[i][j] + next;
        }

        // Note: condition for skipping the coin
        int skip = INT_MIN;
        if (coins[i][j] < 0 && p > 0)
        {
            int skipDown = solve(coins, i + 1, j, p - 1);
            int skipRight = solve(coins, i, j + 1, p - 1);
            skip = max(skipDown, skipRight);
        }
        return t[i][j][p] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>> &coins)
    {
        m = coins.size();
        n = coins[0].size();
        t = vector<vector<vector<int>>>(m,
                                        vector<vector<int>>(n,
                                                            vector<int>(3, INT_MIN)));

        return solve(coins, 0, 0, 2);
    }
};

// ===== TEST RUNNER =====
int main()
{
    Solution sol;

    // Test Case 1
    vector<vector<int>> coins = {{0, 1, -1}, {1, -2, 3}, {2, -3, 4}};
    int result = sol.maximumAmount(coins);
    cout << "Test 1: " << result << endl;
    // Expected: 8

    return 0;
}