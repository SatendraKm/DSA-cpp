
// FIXME: one element missing in a sorted array.

// TODO: Method-
// in the sorted array we can find a missing element by finding
// the total using the last element
// and subtracting the difference from the sum of the elements of the array
// total = (n*(n-1))/2 and subtract
// sum = i -> length sum += A[i]
// missing element = total-sum

// FIXME: one or more element missing in a sorted array.

// TODO: Method->
// in a sorted array not starting from the 1
// get the difference by subtracting (value-index)
// whenever the difference increases then we get the missing number by adding previous difference + index.
// then increase the value of the difference to new calculated difference
// and for each difference we can get all the missing numbers in between the two consucative index
// scaning through the whole array will give all the missing elements.

// sudo code
// int lowest, int highest, int length;
// diff = low-0;
// for(i=0; i<n;i++){
// if (A[i]-i!=diff ){
// cout << "Missing element is - "<<i+diff;
// break;
// }
// }

// Method 2-
// for(i=0; i<n;i++){
// if (A[i]-i!=diff ){
// while (diff< A[i]-i){
// cout << i + diff;
// diff++;
//
// }
// }
// }

// FIXME: Finding more than one missing elements in an unsoterd array
// from the array get the maximum value and then take an array of that same size initialized with 0
// now loop through the array and then increment the value that is found like if the A[1] = 3 then go
// to the array H and increment the value of the index 3 to1
// now the missing then the indexes which have value as 0 are the missing elements of the array
// ---|>
// this is called hash table/ bitset
// int n;
//     for (int i = 0; i < n; i++)
//     {
//         H[A[i]]++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         if (H[i] == 0)
//         {
//             cout << i << " ";
//         }
//     }

#include <iostream>
using namespace std;

int main()
{
    return 0;
}
