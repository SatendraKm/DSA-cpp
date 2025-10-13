// IDEA:Iterativer code with time complexity if O(n**2)
/*
#include <iostream>
using namespace std;
int main()
{
    int k;
    int n = 5;
    int A[n] = {0, 2, 3, 4, 4};
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == k)
            {
                cout << A[i] << " and " << A[j] << " equals " << k;
            }
        }
    }

    return 0;
}
*/

// OPTIMIZE: code with using hashing to decrease time complexity to O(n)

// #include <iostream>
// using namespace std;
// int main()
// {
//     int k;
//     int n = 5;
//     int A[n] = {0, 2, 3, 3, 4};
//     int max = A[n - 1];
//     int H[max + 1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         // TODO:
//         // search for each element in the array A
//         // and increment the value of that index in the array B
//         // then check the difference from that number to the key
//         // if the counter of that value is >0 then the complementary is present
//         // return that number

//         if (H[k - A[i]] != 0)
//         {
//             cout << A[i] << "+" << k - A[i] << "=" << k;
//         }
//         H[A[i]]++;
//     }

//     return 0;
// }

// NOTE: Sorted array
//  IDEA: 2 pointer
// time complexity to O(n)

// #include <iostream>
// using namespace std;
// int main()
// {
//     // Todo:
//     // take two pointers at both indexes at the end lets say i at 0 and j at n-1
//     // now sum the values at both these two index
//     // do the following for the values of sum
//     // if (sum > k) { j-- }
//     // else if (sum < k) { i++ }
//     // else sum = k { i++,j-- } -> A[i] + A[j] = k
//     // do {this}while(i<j)
//     return 0;
// }
