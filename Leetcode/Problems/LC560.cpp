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
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, sum = 0;
        for (int num : nums)
        {
            sum += num;
            count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};

// ===== TEST RUNNER =====
int main()
{
    Solution sol;

    // Test Case 1
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << "Test 1: " << sol.subarraySum(nums, k) << endl;
    // Expected: 2

    return 0;
}