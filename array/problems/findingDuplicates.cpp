// FIXME:
// #include <iostream>
// using namespace std;

// int main()
// {
//     int count = 5;
//     int lastDuplicate = -1;
//     int A[5] = {0, 1, 2, 2, 3};
//     for (int i = 0; i < count - 1; i++)
//     {
//         if (A[i] == A[i + 1] && A[i] != lastDuplicate)
//         {
//             cout << "Duplicate found: " << A[i] << endl;
//             lastDuplicate = A[i];
//         }
//     }

//     return 0;
// }

// FIXME:
// #include <iostream>
// using namespace std;

// int main()
// {
//     int count = 5;
//     int i, j;
//     int A[5] = {0, 1, 2, 2, 3};
//     for (i = 0; i < count - 1; i++)
//     {
//         if (A[i] == A[i + 1])
//         {
//             j = i + 1;
//             while (A[j] == A[i])
//             {
//                 j++;
//             }
//             cout << A[i] << " is appearing " << j - i << " times";
//             i = j - 1;
//         }
//     }

//     return 0;
// }

// BUG: finding duplicate elements in a sorted array
// FIXME:using hashtable
// #include <iostream>
// using namespace std;
/*
definition:
1. get an array of size A[n]+1; so that we can get the array of indexex from 0 to A[i]
    fill the array with the value 0
2. check all the elements in the array A and then go to that H[A[i]] and inclement its count by 1

IT takes time complexity of O(n);
*/

// int main()
// {
//     int count = 5;
//     int i, j;
//     int A[5] = {0, 1, 2, 2, 3};
//     // Find the maximum value in A to determine the size of H
//     int max = A[0];
//     for (i = 1; i < count; i++)
//     {
//         if (A[i] > max)
//             max = A[i];
//     }
//     int H[100] = {0}; // You can use max+1 instead of 100 for a tighter array

//     for (i = 0; i < count; i++)
//     {
//         H[A[i]]++;
//     }

//     // Print duplicates
//     for (i = 0; i <= max; i++)
//     {
//         if (H[i] > 1)
//         {
//             cout << "Duplicate found: " << i << " appears " << H[i] << " times" << endl;
//         }
//     }

//     return 0;
// }

// TODO: finding duplicate elements in an unsorted array
// FIXME:using hashtable
// #include <iostream>
// using namespace std;
/*
definition:
1. for each element check the remaining element and if it is found as duplicate then mark it as -1


IT takes time complexity of O(n**2);
*/

// int main()
// {
//     int count = 5;
//     int i, j;
//     int A[5] = {0, 1, 2, 2, 3};
//     // Find the maximum value in A to determine the size of H
//     int max = A[0];
//     for (i = 1; i < count - 1; i++)
//     {
//         count = 1;
//         if (A[i] != -1)
//         {
//             for (int j = i + 1; i < count; j++)
//             {
//                 if (A[i] == A[j])
//                 {
//                     count++;
//                     A[j] = -1;
//                 }
//             }
//             if (count > 1)
//             {
//                 cout << A[i] << " repeated " << count << " times";
//             }
//         }
//         {
//             /* code */
//         }
//     }

//     return 0;
// }

// HACK: using a bit array
/*
take an array of size of the greatest element in the array A
now we'll be going through the whole array and then
look at each element and increment the index of that element from the H array.
for all the duplicated element, increase the counter in the H array for the index.

*/