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
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<int> indices(n), results;
        stack<int> stack;
        for (int i = 0; i < n; ++i)
        {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int lhs, int rhs)
             { return positions[lhs] < positions[rhs]; });
        for (int i : indices)
        {
            if (directions[i] == 'R')
            {
                stack.push(i);
            }
            else
            {
                while (!stack.empty() && healths[i] > 0)
                {
                    int a = stack.top();
                    stack.pop();
                    if (healths[a] > healths[i])
                    {
                        healths[a] = healths[a] - 1;
                        stack.push(a);
                        healths[i] = 0;
                    }
                    else if (healths[a] < healths[i])
                    {
                        healths[i] = healths[i] - 1;
                        healths[a] = 0;
                    }
                    else
                    {
                        healths[i] = 0;
                        healths[a] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (healths[i] > 0)
            {
                results.push_back(healths[i]);
            }
        }

        return results;
    }
};

// ===== TEST RUNNER =====
int main()
{
    Solution sol;

    // Test Case 1
    vector<int> positions = {3, 5, 2, 6};
    vector<int> healths = {10, 10, 15, 12};
    string directions = "RLRL";
    vector<int> result = sol.survivedRobotsHealths(positions, healths, directions);
    printVec(result);
    // Expected: [14]

    return 0;
}