#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl
#define printVec(v)       \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int x = 0, y = 0;
        int n = commands.size();
        vector<pair<int, int>> Directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // North, East, South, West
        int d = 0;
        int res = 0;

        set<pair<int, int>> obs;
        for (int i = 0; i < obstacles.size(); i++)
        {
            obs.insert({obstacles[i][0], obstacles[i][1]});
        }

        for (int i = 0; i < n; i++)
        {
            // left - 90 degrees (-1)
            if (commands[i] == -1)
            {
                d = (d + 1) % 4;
            }
            // right - 90 degrees (-2)
            else if (commands[i] == -2)
            {
                d = (d + 3) % 4;
            }
            // 1 >= k <= 9
            else
            {
                int dx = Directions[d].first;
                int dy = Directions[d].second;

                for (int k = 0; k < commands[i]; k++)
                {
                    if (obs.count({x + dx, y + dy}))
                        break;
                    x = x + dx;
                    y = y + dy;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<int> commands = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles = {{2, 4}};
    int target1 = 9;
    cout << "Test 1: " << sol.robotSim(commands, obstacles) << endl;
    // Expected: 65

    return 0;
}