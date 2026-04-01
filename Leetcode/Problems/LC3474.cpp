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
    string generateString(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();

        string word(n + m - 1, 'a');
        vector<bool> fixed(n + m - 1, false);

        for (int i = 0; i < n; i++)
        {
            if (str1[i] == 'T')
            {
                for (int j = 0; j < m; j++)
                {
                    int k = i + j;

                    if (fixed[k] && word[k] != str2[j])
                        return "";

                    word[k] = str2[j];
                    fixed[k] = true;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (str1[i] == 'F')
            {
                bool same = true;
                int freePos = -1;

                for (int j = 0; j < m; j++)
                {
                    int k = i + j;

                    if (word[k] != str2[j])
                        same = false;
                    if (!fixed[k])
                        freePos = k;
                }

                if (same)
                {
                    if (freePos == -1)
                        return "";
                    word[freePos] = 'b';
                }
            }
        }

        return word;
    }
};

// ===== TEST RUNNER =====
int main()
{
    Solution sol;

    // Test Case 1
    string str1 = "TFTF";
    string str2 = "ab";
    cout << "Test 1: " << sol.generateString(str1, str2) << endl;
    // Expected: "ababa"

    return 0;
}