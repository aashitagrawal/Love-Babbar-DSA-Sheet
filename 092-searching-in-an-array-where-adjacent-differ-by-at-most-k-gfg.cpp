#include <bits/stdc++.h>
using namespace std;

// Today's Date - 7 Feb 2024
// GFG Question Name - Searching in an array where adjacent differ by at most k

int search(int arr[], int n, int x, int k)
{
    int index=0;
    while(index<n)
    {
        if(arr[index]==x)
            return index;
        else
            index += ceil(abs(x-arr[index])/float(k));
    }
    return -1;
}

int main()
{
    int n = 4;
    int arr[] = {4, 5, 6, 7, 6};
    int x = 5;
    int k = 2;
    cout << search(arr, n, x, k) << endl;
    return 0;
}