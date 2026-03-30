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
    // paste your leetcode solution here
    int twoSum(vector<int> &nums, int target)
    {
        // your code
        return -1;
    }
};

// ===== TEST RUNNER =====
int main()
{
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    cout << "Test 1: " << sol.twoSum(nums1, target1) << endl;
    // Expected: 0 1 (or however you print it)

    // Test Case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    cout << "Test 2: " << sol.twoSum(nums2, target2) << endl;

    return 0;
}