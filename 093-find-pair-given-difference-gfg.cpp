#include <bits/stdc++.h>
using namespace std;

// Today's Date - 10 Feb 2024
// GFG Question Name - Find Pair Given Difference

class Solution
{
public:
    bool findPair(int arr[], int size, int n)
    {
        sort(arr, arr + size);

        auto possibleAns = upper_bound(arr, arr + size, n);
        if (possibleAns == arr + size)
            return 0;

        int index = possibleAns - arr;

        for (int i = index; i < size; ++i)
        {
            int currEle = arr[i];

            int left = 0;
            int right = i - 1;
            while (left <= right)
            {
                int mid = left + ((right - left) / 2);
                int diff = currEle - arr[mid];

                if (diff == n)
                    return 1;
                else if (diff > n)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    // int arr[] = {5, 20, 3, 2, 5, 80};
    // int arr[] = {90, 70, 20, 80, 50};

    int arr[] = {8182, 8847, 9438, 1292, 2782, 7715, 6984, 7173, 2768, 776, 2762, 2248, 692, 9622, 5814, 6978, 3073, 6849, 3363, 8582, 2924, 7136, 8285, 2402, 1625, 7966, 6811, 4169, 4542, 2327, 9887, 9075, 7525, 5677, 6718, 307, 3391, 3701, 7479, 6158, 4477, 6593, 4757, 1520, 6214, 6922, 8497, 5638, 3770, 8211, 4219, 3045, 1698, 8856, 5447, 3322, 6821, 8609, 7491, 1362, 7287, 3729, 6788, 4812, 9405, 3505, 1470, 9147, 7206, 5300, 5304, 8034, 1892, 6412, 9553, 4457, 3334, 4402, 6446, 7103, 8964, 7017, 148, 662, 5872, 1946, 3983, 2692, 554, 7825, 405, 7840, 1554, 7192, 9003, 7310, 7048, 472, 6457, 4253, 5772, 8112, 8638, 4015, 876, 4543, 4824, 4209, 8944, 1269, 7663, 4259, 8285, 4162, 4920, 508, 6107, 8903, 3199, 6660, 3079, 9955, 852, 4632, 7146, 9854, 8294, 546, 6678, 1102, 1150, 2449, 5565, 9788, 2815, 6440, 4330, 7638, 648, 9625, 5259, 4663, 3883, 9895, 8824, 5155, 403, 4931, 4057, 9953, 7942, 7135, 9908, 8793, 8119, 3405, 4999, 2764, 3950, 1676, 3865, 5100, 476, 5781, 1239};

    int size = sizeof(arr) / sizeof(arr[0]);
    // int n = 78;
    // int n = 45;
    int n = 219;
    cout << solution.findPair(arr, size, n) << endl;
    return 0;
}