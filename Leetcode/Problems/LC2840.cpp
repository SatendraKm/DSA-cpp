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
    bool checkStrings(string s1, string s2)
    {
        int n = s1.length();
        int i = 0;
        int even[26] = {0};
        int odd[26] = {0};
        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            }
            else
            {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (even[i] != 0 || odd[i] != 0)
                return false;
        }

        return true;
    }
};

// ===== TEST RUNNER =====
int main()
{
    Solution sol;

    // Test Case 1
    string s1 = "azagmtvhske";
    string s2 = "mkazstvhage";
    cout << "Test 1: " << sol.checkStrings(s1, s2) << endl;
    // Expected: true

    return 0;
}