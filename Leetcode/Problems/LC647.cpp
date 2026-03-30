/*
647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

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
    bool checkPalindrome(int i, int j, string p)
    {
        while (i < j)
        {
            if (p[i] != p[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }

    int countSubstrings(string s)
    {
        int n = s.length();
        int i, j, count = 0;
        for (i = 0; i < n; i++)
        {
            for (j = n - 1; j > i; j--)
            {
                bool isPalindrome = checkPalindrome(i, j, s);
                if (isPalindrome)
                {
                    count++;
                }
            }
        }

        return count + n;
    }
};

// ===== TEST RUNNER =====
int main()
{
    Solution sol;

    // Test Case 1
    string s1 = "abc";
    cout << "Test 1: " << sol.countSubstrings(s1) << endl;
    // Expected: true

    return 0;
}

/*
class Solution
{
public:
    int expand(string &s, int left, int right)
    {
        int count = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s)
    {
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            // odd length palindromes
            count += expand(s, i, i);

            // even length palindromes
            count += expand(s, i, i + 1);
        }

        return count;
    }
};
*/